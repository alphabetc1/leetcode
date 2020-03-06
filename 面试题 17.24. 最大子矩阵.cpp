#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
#define NMAX 210
using namespace std;
/*
*化二维dp为一维，将问题转化为求最大子序列和
*/
class Solution {
public:
	int maxLen[NMAX];
	vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
		int max = 0x80000000;
		int r1, c1, r2, c2;
		for (int i = 0; i < matrix.size(); i++) {
			memset(maxLen, 0, sizeof(maxLen));
			for (int j = i; j < matrix.size(); j++) {
				for (int k = 0; k < matrix[0].size(); k++) {
					maxLen[k] += matrix[j][k];
				}
				int now = 0, start, end;
				for (int k = 0; k < matrix[0].size(); k++) {
					if (now <= 0) {
						now = maxLen[k];
						start = k;
					}
					else now += maxLen[k];
					if (now > max) {
						max = now;
						r1 = i;
						c1 = start;
						r2 = j;
						c2 = k;
					}
				}
			}
		}
		vector<int>ans = { r1, c1, r2, c2 };
		return ans;
	}
};

int main() {
	Solution s1;
	vector<vector<int>>A = { { 2, 1, 1 },{ 1, 1, 0 },{ 0, 1, 1 } };
	vector<vector<int>>C = { { -1, 1 },{ 1,-1 } };
	vector<int>B = s1.getMaxMatrix(C);
	for (int i = 0; i < B.size(); i++)
		cout << B[i] << " ";
	system("pause");
	return 0;
}