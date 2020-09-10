1000. 合并石头的最低成本.cpp
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if(!n || (n-1) % (K-1) != 0 || K < 2)    {
            return -1;
        }
        vector<int> sum(n, 0);
        sum[0] = stones[0];
        for(int i = 1; i < n; ++i)  {
            sum[i] = sum[i-1] + stones[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n - K; i >= 0; --i) {
            for(int j = i + K - 1; j < n; ++j)  {
                if(j == i + K - 1)  {
                    dp[i][j] = sum[j] - sum[i] + stones[i];
                    continue;
                }
                dp[i][j] = INT_MAX;
                for(int m = i; m < j; m += K-1)  {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j]);
                }
                if((j - i) % (K-1) == 0)    {
                    dp[i][j] += sum[j] - sum[i] + stones[i];
                }
            }
        }
        return dp[0][n-1];
    }
};