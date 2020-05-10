123. 买卖股票的最佳时机 III.cpp
/*
dp_i_k：经过至多i次交易_当前是否持有股票(0未持有/1持有) 时的最大利润
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)   return 0;
        int dp_1_0 = 0, dp_2_0 = 0, dp_1_1 = -prices[0], dp_2_1 = -prices[0];
        
        for(int i = 1; i < n; i++)  {
            dp_2_0 = max(dp_2_0, dp_2_1+prices[i]);
            dp_2_1 = max(dp_2_1, dp_1_0-prices[i]);
            dp_1_0 = max(dp_1_0, dp_1_1+prices[i]);
            dp_1_1 = max(dp_1_1, -prices[i]);
        }
        return dp_2_0;
    }
};