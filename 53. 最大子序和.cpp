53. 最大子序和.cpp
//分治法
class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right)  {
        if(left == right)   return nums[left];
        int ans, nowSum;
        ans = nowSum = nums[mid];
        for(int i = mid - 1;i >= left; i-- )    {
            nowSum += nums[i];
            ans = max(nowSum, ans);
        }
        nowSum = ans;
        for(int i = mid + 1;i <= right; i++ )    {
            nowSum += nums[i];
            ans = max(nowSum, ans);
        }
        return ans;
    }

    int mergeNums(vector<int>& nums, int left, int right)    {
        if(left == right) return nums[left];
        int mid = (left + right) / 2;
        int leftSum = mergeNums(nums, left, mid);
        int rightSum = mergeNums(nums, mid+1, right);
        int midSum = merge(nums, left, mid, right);
        return max(leftSum, max(rightSum, midSum));
    }

    int maxSubArray(vector<int>& nums) {
        return mergeNums(nums, 0, nums.size() - 1);
    }
};

//dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        int ans = nums[0];
        dp[0] = ans;
        for(int i = 1; i < nums.size(); i++)    {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans, sum;
        sum = ans = nums[0];
        for(int i = 1; i < nums.size(); i++)    {
            if(sum > 0) sum += nums[i];
            else sum = nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};