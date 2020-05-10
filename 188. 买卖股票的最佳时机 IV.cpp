188. 买卖股票的最佳时机 IV.cpp
/*
dp[i][j][0]/dp[i][j][1]：前i天至多买卖j次的情况下所得的收益，最后的0/1表示是否仍持有股票
则dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                    第i天不买卖             第i天卖出
且dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
                    第i天不买卖              第i天买入
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2)  return 0;
        if(k > n/2) {
            int minNum = prices[0], res = 0;
            for(int i = 1; i < n; i++)  {
                if(prices[i] > minNum)  {
                    res += prices[i] - minNum;
                }
                minNum = prices[i];
            }
            return res;
        }

        int dp[n][k+1][2];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)  {
            for(int j = 1; j <= k; j++)  {
                if(i == 0)  {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[0];
                }else{
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
                }
            }
        }
        return dp[n-1][k][0];
    }
};