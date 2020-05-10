714. 买卖股票的最佳时机含手续费.cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n < 2)   return 0;
        int dp_0 = 0, dp_1 = -prices[0];
        for(int i = 1; i < n; i++)  {
            int tmp = dp_0;
            dp_0 = max(dp_0, dp_1+prices[i]-fee);
            dp_1 = max(dp_1, tmp-prices[i]);
        }
        return dp_0;
    }
};