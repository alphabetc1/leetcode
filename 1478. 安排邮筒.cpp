1478. 安排邮筒.cpp
class Solution {
public:
    int minDistance(vector<int>& houses, int K) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        vector<vector<int>>rec(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++)  {
            for(int j = i; j < n; j++)    {
                int tmp = houses[(j+i)/2];
                for(int k = i; k <= j; k++) {
                    rec[i][j] += abs(houses[k] - tmp);
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(K+1, 1e9));
        for(int i = 0; i < n; i++)  {
            dp[i][1] = rec[0][i];
        }
        for(int i = 0; i < n; i++)  {
            for(int j = 2; j <= min(i+1,K); j++)  {
                for(int k = j-1; k <= i; k++) {
                    dp[i][j] = min(dp[k-1][j-1] + rec[k][i], dp[i][j]);
                }
            }
        }
        return dp[n-1][K];
    }
};