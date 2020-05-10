面试题 16.17. 连续数列.cpp
//分治法，DP做更优
class Solution {
public:
    int mergeSum(vector<int>& nums, int st, int ed) {
        if(st < ed - 1)    {
            int mid = (st + ed) / 2;
            int leftSum = mergeSum(nums, st, mid);
            int rightSum = mergeSum(nums, mid, ed);
            int midTmp = nums[mid], midSum = midTmp;
            for(int i = mid - 1; i >=st; i--)   {
                midTmp += nums[i];
                midSum = max(midSum, midTmp);
            }
            midTmp = midSum;
            for(int i = mid+1; i < ed; i++) {
                midTmp += nums[i];
                midSum = max(midSum, midTmp);
            }  
            return max(max(leftSum, rightSum), midSum);
        }
        return nums[st];
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(!n)  return 0;
        else if(1 == n) return nums[0];
        int res = mergeSum(nums, 0, n);
        return res;
    }
};