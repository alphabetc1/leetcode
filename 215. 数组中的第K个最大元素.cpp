#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 100010
using namespace std;
/*
������K��Ԫ�ص�С����
ÿ����Ԫ�ؼ���С���ѣ�ɾȥ�Ѷ�Ԫ��
���Ѷ���Ϊ��K�����
ע��1���ҵ�k�������ʵ��С����
ע��2��stl��heapĬ�ϴ󶥶�
ע��3��push_heap(start, end)Ĭ����start��end-1�Ѿ���һ����
*/
bool cmp(const int &a, const int &b) {
	return a > b;
}

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		make_heap(nums.begin(), nums.begin() + k, cmp);
		for (int i = k; i < nums.size(); i++) {
			nums[k] = nums[i];
			cout << "before" << endl;
			for (int j = 0; j < nums.size(); j++)
				cout << nums[j] << " ";
			push_heap(nums.begin(), nums.begin() + k + 1, cmp);
			pop_heap(nums.begin(), nums.begin() + k + 1, cmp);
			cout << "after" << endl;
			for (int j = 0; j < nums.size(); j++)
				cout << nums[j] << " ";
			cout << endl;
		}
		return nums[0];
	}
};