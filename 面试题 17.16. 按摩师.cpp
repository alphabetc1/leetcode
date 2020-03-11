/*
简单dp
nums[i]表示到i为止所能服务的最大时间
扫描一遍，当扫描到j时
nums[j] = nums[j-2] + nums[j];  承接j-2天，得到到j能服务的最大时间
nums[j-1] = max(nums[j-1], nums[j-2])   下一轮就可以承接第j-1天的服务时间
*/
class Solution {
public:
	int massage(vector<int>& nums) {
		int n = nums.size();
		if (!n)  return 0;
		else if (1 == n) return nums[0];
		for (int j = 2; j < n; j++) {
			nums[j] += nums[j - 2];
			nums[j - 1] = max(nums[j - 2], nums[j - 1]);
		}
		return max(nums[n - 2], nums[n - 1]);
	}
};