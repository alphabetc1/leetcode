712. 两个字符串的最小ASCII删除和.cpp
//还是最大公共序列的思想

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n; i++)    {
            dp[i+1][0] = dp[i][0] + s1[i] - 'a' + 97;
        }
        for(int i = 0; i < m; i++)    {
            dp[0][i+1] = dp[0][i] + s2[i] - 'a' + 97;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1])  {
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]) - 'a' + 97;
                }
            }
        }
        return dp[n][m];
    }
};