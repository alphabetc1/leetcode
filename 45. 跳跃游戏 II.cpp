#include <iostream>
#include <algorithm>
#include<string.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;
/*
*贪心法
*思路
*这里的贪心表示每轮能达到的最远距离，什么叫轮呢，比如这样一组数据[2,3,1,1,4]，第一轮只能从起跳点(pos0)开始跳，而第二轮就可以选择从pos1或者pos2开始跳，题目中最小的跳跃数就是达到终点所需最少的轮数。
*/
class Solution {
public:
	int jump(vector<int>& nums) {
		int maxPos, end, ans;
		maxPos = end = ans = 0;
		int lastPos = nums.size() - 1;
		for (int i = 0; i < lastPos; i++) {
			maxPos = max(maxPos, nums[i] + i);
			if (end == i) {
				end = maxPos;
				ans++;
				if (end >= lastPos)	break;
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	int n[10] = { 2,5,1,1,4 };
	vector<int> nu(n, n + 5);
	cout << s.jump(nu) << endl;
	system("pause");
	return 0;
}