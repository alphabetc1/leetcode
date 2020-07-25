求topK.cpp
#include<iostream>
using namespace std;

vector<int> GetTopK(vector<vector<int>> &nums, vector<int> &len, int k)	{
	int n = nums.size();
	vector<int> st(n, 0), next(n, 0);

	while(k)	{
		int minTag = -1, minNum = 0x3f3f3f3f;
		for(int i = 0; i < n; i++)	{
			if(st[i] >= len[i])	{
				continue;
			}
			next[i] = st[i] + min(len[i], k / n) - 1;
			if(nums[i][next[i]] < minNum)	{
				minNum = nums[i][next[i]];
				minTag = i;
			}
		}
		k -= next[minTag] - st[minTag] + 1; 
		st[minTag] = next[minTag] + 1;
	}

	int minTag = -1, minNum = 0x3f3f3f3f;
	vector<int> ans;

	for(int j = 0; j < k; j++)	{
		int minTag = -1, minNum = 0x3f3f3f3f;
		for(int i = 0; i < n; i++)	{
			if(st[i] >= len[i])	{
				continue;
			}
			if(nums[st[i]] < minNum)	{
				minNum = nums[st[i]];
				minTag = i;
			}
		}
		ans.push_back(minNum);
		st[minTag]++;
	}
	return ans;
}

int main()	{
	int n, k;
	cin>>n>>k;

	vector<int> len(n, 0);
	vector<vector<int>> nums;
	for(int i = 0; i < n; i++)	{
		cin>>len[i];
		vector<int>temp(len[i], 0);
		for(int j = 0; j < len[i]; j++)	{
			cin>>temp[j];
		}
		nums.push_back(temp);
	}
	return GetTopK(nums, len, k);
}