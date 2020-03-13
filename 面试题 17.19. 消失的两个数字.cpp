面试题 17.19. 消失的两个数字.cpp
//数学解法
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size(); 
        long plusSum = 0, squSum = 0, allSquSum = 0;
        for(int i = 0; i < n; i++)  {
            plusSum += nums[i];
            squSum += nums[i] * nums[i];
            allSquSum += (i+1) * (i+1);
        }
        allSquSum += (n+1) * (n+1);
        allSquSum += (n+2) * (n+2);
        int twoPlusSum = (n+2)*(n+3)/2 - plusSum;
        int twoSquSum = allSquSum - squSum;
        vector<int> ans(2,0);
        int tmp = sqrt(twoSquSum*2 - twoPlusSum*twoPlusSum);
        ans[0] = (twoPlusSum - tmp) / 2;
        ans[1] = (twoPlusSum + tmp) / 2;
        return ans;
    }
};