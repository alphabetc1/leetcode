542. 01 矩阵.cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return {{}};
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < m; j++)  {
                if(matrix[i][j])    {
                    dp[i][j] = 10000;
                }
            }
        }
        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < m; j++)  {
                if(i - 1 >= 0)  {
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                }
                if(j - 1 >= 0)  {
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }
        for(int i = n-1; i >= 0; i--)  {
            for(int j = m-1; j >= 0; j--)  {
                if(i + 1 < n)  {
                    dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                }
                if(j + 1 < m)  {
                    dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
                }
            }
        }
        return dp;
    }
};