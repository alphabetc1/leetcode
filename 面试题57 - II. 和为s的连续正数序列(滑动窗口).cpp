#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
//滑动窗口,这题用纯数学的方法效率会比较高
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int sum = 0, limit = target/2 + 1;
		queue<int>q;
		vector<int>res;
		vector<vector<int>>ans;
		for (int i = 1; i <= limit; i++) {
			sum += i;
			q.push(i);
			if (sum > target) {
				while (!q.empty() && sum - q.front() >= target) {
					sum -= q.front();
					q.pop();
				}
			}
			if (sum == target) {
				res.clear();
				for (int j = q.front(); j <= i; j++) {
					res.emplace_back(j);
				}
				sum -= q.front(), q.pop();	//一个简单的优化，下一个序列一定比当前序列长度小
				sum -= q.front(), q.pop();	//所以新增的元素一定比队首(最小的)俩元素的和要大，然而没卵用
				ans.emplace_back(res);
			}
		}
		return ans;
	}
};

int main() {
	Solution s1;
	s1.findContinuousSequence(9);
	system("pause");
	return 0;
}