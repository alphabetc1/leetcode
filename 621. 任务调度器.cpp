621. 任务调度器.cpp
//题解https://leetcode-cn.com/problems/task-scheduler/
//桶排序
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26, 0);
        for(auto c:tasks) {
            v[c - 'A']++;
        }
        sort(v.begin(), v.end(), [](int &x, int &y) {return x > y;});
        int cnt = 1;
        for(int i = 1; i < v.size() && v[i] == v[0]; i++)   {
            cnt++;
        }

        int len = tasks.size();
        return max(len, (n+1) * (v[0] - 1) + cnt);
    }
};

//优先级队列
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26, 0);
        for(auto c:tasks) {
            v[c - 'A']++;
        }
        priority_queue<int>q;
        for(auto times:v)   {
            if(times)   {
                q.push(times);
            }
        }

        int time = 0;
        while(!q.empty())   {
            int i = 0;
            list<int> temp;
            while(i <= n)    {
                if(!q.empty())   {
                    if(q.top() > 1) {
                        temp.push_back(q.top() - 1);
                    }
                    q.pop();
                }
                time++;
                i++;
                if(q.empty() && temp.empty())   break;
            }
            for(auto num:temp)  {
                q.push(num);
            }
        }
        return time;
    }
};