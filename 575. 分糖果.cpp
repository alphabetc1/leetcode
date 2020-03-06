#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		int n = num_people, delta, t = 1;
		vector<int>ans(n, 0);
		delta = (n + 1)*n / 2;
		while (candies >= delta) {
			candies -= delta;
			delta += n * n;
			t++;
		}
		int start = 1, need;
		while (candies) {
			need = (t - 1)*n + start;
			if (candies > need) {
				candies -= need;
				ans[start - 1] = need;
				start++;
			}
			else {
				ans[start - 1] = candies;
				candies = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			ans[i - 1] += ((t - 2)*n + 2*i)*(t-1) / 2;
		}
		return ans;
	}
};

int main() {
	Solution s1;
	vector<int>ans = s1.distributeCandies(7, 4);
	for (int i = 1; i < ans.size(); i++)
		cout << ans[i] << " ";
	system("pause");
	return 0;
}