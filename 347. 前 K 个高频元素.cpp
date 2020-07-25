347. 前 K 个高频元素.cpp
//堆实现
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>v;
        for(auto num:nums)  {
            v[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(auto num:nums)  {
            if(!v[num]) {
                continue;
            }
            if(q.size() < k)    {
                q.push({v[num], num});
                v[num] = 0;
            }else{
                if(v[num] > q.top().first) {
                    q.pop();
                    q.push({v[num],num});
                    v[num] = 0;
                }
            }
        }
        vector<int>ans;
        while(!q.empty())   {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};

//快排实现，均摊复杂度O(n)
int Partition(vector<pair<int, int>> &numSet, int left, int right)   {
    pair<int, int> pivot = numSet[left];
    while(left < right) {
        while(left < right && numSet[right].second <= pivot.second) right--;
        numSet[left] = numSet[right];
        while(left < right && numSet[left].second >= pivot.second)  left++;
        numSet[right] = numSet[left];
    }
    numSet[left] = pivot;
    return left;
}

void PairQsort(vector<pair<int, int>> &numSet, int left, int right, int k) {
    int pivot = Partition(numSet, left, right);
    if(pivot == k-1)   {
        return;
    }else if(pivot < k - 1) {
        PairQsort(numSet, pivot+1, right, k);
    }else if(pivot > k - 1) {
        PairQsort(numSet, left, pivot - 1, k);
    }
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>v;
        for(auto num:nums)  {
            v[num]++;
        }
        vector<pair<int, int>>numSet;
        for(auto num:nums)  {
            if(v[num])  {
                numSet.push_back({num, v[num]});
                v[num] = 0;
            }
        }

        PairQsort(numSet, 0, numSet.size() - 1, k);

        vector<int> ans;
        for(int i = 0; i < k; i++)  {
            ans.push_back(numSet[i].first);
        }
        return ans;
    }
};