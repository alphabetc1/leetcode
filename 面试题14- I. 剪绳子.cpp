面试题14- I. 剪绳子.cpp
//dp[i]代表到长度为i时的最大结果
class Solution {
public:
    int cuttingRope(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        for(int i = 2; i <= n; i++)  {
            for(int j = 1; j < i; j++)  {
                dp[i] = max(dp[i], max(j, dp[j])*(i-j));
            }
        }
        return dp[n];
    }
};