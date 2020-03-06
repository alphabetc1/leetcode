#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
/*
*优化BFS
*执行用时 :8 ms, 在所有 C++ 提交中击败了76.58%的用户
*内存消耗 :15.2 MB, 在所有 C++ 提交中击败了5.40%的用户
*/
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int freshNum = 0;
		int fw[4][2] = { { 0,1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };
		queue<int> q;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					freshNum++;
				}
				if (grid[i][j] == 2) {
					q.push(i), q.push(j), q.push(0);
				}
			}
		}
		int oi, oj, tips = -1, ni, nj;
		while (freshNum && !q.empty()) {
			oi = q.front(), q.pop();
			oj = q.front(), q.pop();
			tips = q.front(), q.pop();
			for (int i = 0; i < 4; i++) {
				ni = oi + fw[i][0];
				nj = oj + fw[i][1];
				if (ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[ni].size() && grid[ni][nj] == 1) {
					freshNum--;
					grid[ni][nj] = 2;
					q.push(ni), q.push(nj), q.push(tips + 1);
				}
			}
		}
		if (!freshNum)	return tips + 1;
		else return -1;
	}
};

int main() {
	Solution s1;
	vector<vector<int>>A = { { 2, 1, 1 },{ 1, 1, 0 },{ 0, 1, 1 } };
	vector<vector<int>>B = { { 0,2 } };
	cout << s1.orangesRotting(B) << endl;
	system("pause");
	return 0;
}