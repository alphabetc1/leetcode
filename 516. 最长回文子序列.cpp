516. 最长回文子序列.cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int ans = 1;
        for(int i = s.size() - 1; i >= 0; --i)   {
            for(int j = i; j < s.size(); ++j)   {
                if(i == j)  {
                    dp[i][j] = 1;
                    continue;
                }
                if(s[i] == s[j])    {
                    dp[i][j] = max(1, max(dp[i][j], dp[i+1][j-1]+2));
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};