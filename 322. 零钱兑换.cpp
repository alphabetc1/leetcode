322. 零钱兑换.cpp
//经典dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        vector<int> dp(amount+1, amount+1);
        dp[amount] = 0;
        for(int i = 0; i < coins.size(); i++)   {
            for(int j = amount - coins[i]; j >= 0; j--) {
                dp[j] = min(dp[j], dp[j + coins[i]] + 1);
            }
        }

        if(dp[0] != amount+1)  {
            return dp[0];
        }else{
            return -1;
        }
    }
};

