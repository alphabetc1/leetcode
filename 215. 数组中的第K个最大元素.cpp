#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 100010
using namespace std;
/*
建立含K个元素的小顶堆
每当有元素加入小顶堆，删去堆顶元素
最后堆顶即为第K大的数
注意1：找第k大的数其实用小顶堆
注意2：stl中heap默认大顶堆
注意3：push_heap(start, end)默认是start到end-1已经是一个堆
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