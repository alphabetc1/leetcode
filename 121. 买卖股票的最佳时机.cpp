121. 买卖股票的最佳时机.cpp
class Solution {
public:
	int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)   return 0;
        int dp_i_0 = 0, dp_i_1 = -prices[0];
		for(int i = 1; i < n; i++)  {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
	}
};