#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*数学解法
*假设我们找到了一组序列a1, a2, a3……an和为target，则
*target = n*(a1+an)/2, 由等差数列的性质得
*target = n*a1 + n*(n-1)/2
*a1 = target/n - (n-1)/2 = (2*target - n*(n-1)) / 2*n
*/
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<int>res;
		vector<vector<int>>ans;
		int n = 2;
		int tmp = 2 * target - n * (n - 1);
		while (tmp > 0) {
			if (tmp % (2 * n) == 0) {
				int a = tmp / (2 * n);
				res.clear();
				for (int i = 0; i < n; i++) {
					res.emplace_back(a + i);
				}
				ans.emplace_back(res);
			}
			n++;
			tmp = 2 * target - n * (n - 1);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	Solution s1;
	s1.findContinuousSequence(9);
	system("pause");
	return 0;
}