#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;

class Solution {
public:
	int shortestSubarray(vector<int>& A, int K) {
		deque<int>q;
		int n = A.size();
		vector<int>sum(n + 1, 0);
		int ans = n+1;
		for (int i = 0; i < n; i++)
			sum[i + 1] = sum[i] + A[i];
		for (int i = 0; i < n + 1; i++) {	//sumÓÐn+1¸öÔªËØ
			while (!q.empty() && sum[i] <= sum[q.back()]) {
				q.pop_back();
			}
			while (!q.empty() && sum[i] >= sum[q.front()] + K) {
				ans = min(ans, i - q.front());
				q.pop_front();
			}
			q.push_back(i);
		}
		return ans < n + 1 ? ans : -1;
	}
};

int main() {
	Solution s1;
	vector<int>A = { 2,-1, 2};
	cout << s1.shortestSubarray(A, 3) << endl;
	system("pause");
	return 0;
}