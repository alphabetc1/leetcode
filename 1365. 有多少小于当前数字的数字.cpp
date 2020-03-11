//Õ∞≈≈–Ú
class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int>vis(110, 0);
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			vis[nums[i] + 1]++;
		}
		for (int i = 1; i <= 100; i++) {
			vis[i] += vis[i - 1];
		}
		vector<int>ans;
		for (int i = 0; i < n; i++) {
			ans.push_back(vis[nums[i]]);
		}
		return ans;
	}
};