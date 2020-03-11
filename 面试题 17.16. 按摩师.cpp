/*
��dp
nums[i]��ʾ��iΪֹ���ܷ�������ʱ��
ɨ��һ�飬��ɨ�赽jʱ
nums[j] = nums[j-2] + nums[j];  �н�j-2�죬�õ���j�ܷ�������ʱ��
nums[j-1] = max(nums[j-1], nums[j-2])   ��һ�־Ϳ��Գнӵ�j-1��ķ���ʱ��
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