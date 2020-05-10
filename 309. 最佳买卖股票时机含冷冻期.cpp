309. 最佳买卖股票时机含冷冻期.cpp

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)   return 0;
        int dp_0[n+1], dp_1[n+1];
        dp_0[0] = 0;
        dp_1[0] = -prices[0];
        dp_0[1] = max(0, dp_1[0]+prices[1]);
        dp_1[1] = max(dp_1[0], -prices[1]);
        for(int i =2; i < n; i++)  {
            dp_0[i] = max(dp_0[i-1],dp_1[i-1]+prices[i]);
            dp_1[i] = max(dp_1[i-1], dp_0[i-2]-prices[i]);
        }
        return dp_0[n-1];
    }
};