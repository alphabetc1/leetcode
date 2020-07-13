209. 长度最小的子数组.cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int st = 0, ed = 0, sum = 0, ans = INT_MAX;
        
        while(ed < nums.size())  {
            while(ed < nums.size() && sum < s)  {
                sum += nums[ed];
                ed++;  
            }
            while(sum - nums[st] >= s)   {
                sum -= nums[st];
                st++;
            }
            if(sum >= s)    {
                ans = min(ans, ed - st);
            }
            
            sum -= nums[st];
            st++;
        }
        if(ans == INT_MAX)  return 0;
        else return ans;
    }
};