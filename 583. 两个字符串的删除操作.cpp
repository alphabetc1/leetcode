583. 两个字符串的删除操作.cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++)    {
            for(int j = 1; j <= m; j++)    {
                if(word1[i-1] == word2[j-1])    {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);     
                }
            }
        }
        return (word1.length() - dp[n][m] + word2.length() - dp[n][m]);
    }
};