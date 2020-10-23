1526. 形成目标数组的子数组最少增加次数.cpp
class Solution {
public:
    int minNumberOperations(vector<int>& target) { 
        int ans = 0;
        stack<int> s;
        s.push(-1);

        target.push_back(0);
        for(auto num:target)    {
            int temp = s.top();
            while(!s.empty() && num < s.top())  {
                s.pop();
            }
            ans += max(0, temp - num);
            s.push(num);
        }
        return ans;
    }
};