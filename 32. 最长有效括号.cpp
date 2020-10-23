class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2)    {
            return 0;
        }
        vector<int> dp(s.size(), 0);
        int ans = 0;
        if(s[0] == '(' && s[1] == ')')  {
            dp[1] = 2;
            ans = 2;
        }
        for(int i = 2; i < s.size(); ++i)   {
            if(s[i] == ')') {
                if(s[i-1] == '(')   {
                    dp[i] = dp[i-2] + 2;
                }else if(i - dp[i-1]  > 0 && s[i - dp[i-1]-1] == '(')    {
                    dp[i] = dp[i-1] + 2 + ((i - dp[i-1] - 2 >= 0?dp[i-dp[i-1]-2]: 0));
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};