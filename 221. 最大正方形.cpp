221. 最大正方形.cpp
//dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1],dp[i-1][j])) + 1;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        if(!matrix.size() || !matrix[0].size())  return res;
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < m; j++)  {
                if(matrix[i][j] == '1')    {
                    if(i == 0 || j == 0)    {
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1],dp[i-1][j])) + 1;  
                    }
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }
};