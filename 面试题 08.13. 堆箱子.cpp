面试题 08.13. 堆箱子.cpp
class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        sort(box.begin(), box.end());
        vector<int>dp(box.size());
        int ans = 0;
        for(int i = 0; i < box.size(); i++) {
            dp[i] = box[i][2];
            for(int j = 0; j < i; j++)  {
                if(box[j][0] < box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2]) 
                    dp[i] = max(dp[i], dp[j]+box[i][2]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};