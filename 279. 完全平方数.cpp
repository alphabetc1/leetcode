279. 完全平方数.cpp
//类似coin change的dp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 100000);
        dp[n] = 0;
        for(int i = sqrt(n); i >= 1; i--)   {
            for(int k = n; k > n - i*i; k--) {
                for(int j = k - i * i; j >= 0; j -= i*i)    {
                    dp[j] = min(dp[j], dp[j+i*i]+1);
                }
            }
        }
        return dp[0];
    }
};

//或者
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 100000);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)   {
            dp[i] = i;
            for(int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j*j]+1);
            }
        }
        return dp[n];
    }
};