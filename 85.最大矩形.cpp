85.最大矩形.cpp
class Solution {
public:
    int getAns(const vector<int> &dp) {
        stack<int> s;
        s.push(-1);

        int ans = 0;
        for(int i = 0; i < dp.size(); i++)  {
            while(s.top() != -1 && dp[i] < dp[s.top()])    {
                int h = dp[s.top()];
                s.pop();
                ans = max(ans, h * (i - s.top() - 1));
            }
            s.push(i);
        }
        while(s.top() != -1)    {
            int h = dp[s.top()];
            s.pop();
            ans = max(ans, h * ((int)dp.size() - s.top() - 1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size())  return 0;
        
        int n = matrix.size(), m = matrix[0].size();

        int ans = 0;
        vector<int>dp(m, 0);
        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < m; j++)  {
                dp[j] = (matrix[i][j] == '1')? dp[j]+1: 0;
            }
            ans = max(ans, getAns(dp));
        }
        return ans;
    }
};