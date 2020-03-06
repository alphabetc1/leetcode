#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
//��������,�����ô���ѧ�ķ���Ч�ʻ�Ƚϸ�
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
				sum -= q.front(), q.pop();	//һ���򵥵��Ż�����һ������һ���ȵ�ǰ���г���С
				sum -= q.front(), q.pop();	//����������Ԫ��һ���ȶ���(��С��)��Ԫ�صĺ�Ҫ��Ȼ��û����
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