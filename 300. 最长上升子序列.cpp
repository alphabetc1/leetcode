300. 最长上升子序列.cpp
//二分法，O(nlogn)复杂度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> dp(nums.size());
        for(auto num:nums)    {
            int s = 0, t = ans;
            while(s < t)    {
                int mid = (s + t) / 2;
                if(dp[mid] == num)  {
                    s = mid;
                    break;
                }
                else if(dp[mid] < num)  s = mid + 1;
                else t = mid;
            }
            dp[s] = num;
            if(s == ans)    ans++;
        }
        return ans;
    }
};