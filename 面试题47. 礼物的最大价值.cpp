面试题47. 礼物的最大价值.cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++)  {
            for(int j = 1; j <= n; j++)  {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};