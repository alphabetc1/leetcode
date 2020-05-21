983. 最低票价.cpp
//dp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last = days[days.size() - 1];
        vector<int> dp(last+1, 0);

        int index = 0;
        for(int i = 1; i <= last; i++)   {
            if(i == days[index])    {
                index++;
                int costNow = INT_MAX;
                int oneDayAgo = i-1;
                int sevenDaysAgo = (i > 7)?i-7:0;
                int thirtyDaysAgo = (i > 30)?i-30:0;
                
                costNow = min(dp[oneDayAgo] + costs[0], costNow);
                costNow = min(dp[sevenDaysAgo] + costs[1], costNow);
                costNow = min(dp[thirtyDaysAgo] + costs[2], costNow);

                dp[i] = costNow;
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[last];
    }
};