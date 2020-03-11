//dp+ø’º‰—πÀı
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (!n)  return 0;
		if (1 == n)  return triangle[0][0];
		vector<int>dp(n, 0x3f3f3f3f);
		vector<int>dpCopy(n, 0x3f3f3f3f);
		dp[0] = dpCopy[0] = triangle[0][0];
		int lastNum;
		for (int i = 1; i < n; i++) {
			dpCopy[0] = dp[0] + triangle[i][0];
			for (int j = 1; j < i; j++) {
				dpCopy[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
			}
			dpCopy[i] = dp[i - 1] + triangle[i][i];
			dp.assign(dpCopy.begin(), dpCopy.end());
		}
		int minSum = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			minSum = min(minSum, dp[i]);
		}
		return minSum;
	}
};