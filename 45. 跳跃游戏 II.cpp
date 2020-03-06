#include <iostream>
#include <algorithm>
#include<string.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;
/*
*̰�ķ�
*˼·
*�����̰�ı�ʾÿ���ܴﵽ����Զ���룬ʲô�����أ���������һ������[2,3,1,1,4]����һ��ֻ�ܴ�������(pos0)��ʼ�������ڶ��־Ϳ���ѡ���pos1����pos2��ʼ������Ŀ����С����Ծ�����Ǵﵽ�յ��������ٵ�������
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