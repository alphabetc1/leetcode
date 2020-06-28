576. 出界的路径数.cpp
//图dp
class Solution {
public:
    int fw[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int findPaths(int m, int n, int N, int i, int j) {
        int mod = 1000000007;
        if(!N)  return 0;

        vector<vector<vector<long>>> dp(m+2, vector<vector<long>>(n+2, vector<long>(N+1, 0)));
        for(int col = 0; col <= m+1; col++) {
            dp[col][0][0] = dp[col][n+1][0] = 1;
        }
        for(int row = 0; row <= n+1; row++)   {
            dp[0][row][0] = dp[m+1][row][0] = 1;
        }
        int res = 0;
        for(int k = 1; k <= N; k++) {
            for(int col = 1; col <= m; col++)   {
                for(int row = 1; row <= n; row++)   {
                    dp[col][row][k] = (dp[col-1][row][k-1] + dp[col][row-1][k-1] + dp[col+1][row][k-1] + dp[col][row+1][k-1]) % mod;
                }
            }
            res = (res + dp[i+1][j+1][k]) % mod;
        }
        return res;
    }
};