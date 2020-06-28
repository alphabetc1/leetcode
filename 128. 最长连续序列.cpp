128. 最长连续序列.cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int>v;
        for(int i = 0; i < nums.size(); i++)    {
            v[nums[i]] = 1;
        }
        int longestLength = 0;
        for(int i = 0; i < nums.size(); i++)    {
            if(!v.count(nums[i]-1)) {
                int tmp = nums[i]+1;
                while(v.count(tmp)) {
                    tmp++;
                }
                longestLength = max(longestLength, tmp - nums[i]);
            }
        }
        return longestLength;
    }
};