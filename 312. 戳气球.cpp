312. 戳气球.cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(!n)  return 0;
        
        vector<int> val(n+2, 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2));

        for(int i = 1; i <= n; i++)   {
            val[i] = nums[i-1];
        }

        for(int i = n-1; i >=0 ; i--)  {
            for(int j = i + 2; j <= n+1; j++)  {
                for(int k = i+1; k < j; k++) {
                    int tmp = val[i]*val[j]*val[k];
                    tmp += dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], tmp);
                }
            }
        }
        return dp[0][n+1];
    } 
};