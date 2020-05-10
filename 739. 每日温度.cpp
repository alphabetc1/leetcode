739. 每日温度.cpp
//贪心
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>res(T.size(), 0);
        for(int i = T.size()-2; i >=0; i--)   {
            if(T[i] >= T[i+1])  {
                int tmp = i + 1 + res[i+1];
                while(res[tmp]) {
                    if(T[i] < T[tmp])   {
                        res[i] = tmp-i;
                        break;
                    }else{
                        tmp = tmp + res[tmp];
                    }
                }
                if(!res[i] && T[i] < T[tmp])  {
                    res[i] = tmp-i;
                }  
            }else{
                res[i] = 1;
            }   
        }
        return res;
    }
};

//递减栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>res(T.size(), 0);
        stack<int> s;
        for(int i = 0; i < T.size(); i++)   {
            while(!s.empty() && T[i] > T[s.top()])  {
                int index = s.top(); s.pop();
                res[index] = i - index;
            }
            s.push(i);
        }
        while(!s.empty())   {
            int tmp = s.top(); s.pop();
            res[tmp] = 0;
        }
        return res;
    }
};