面试题 17.14. 最小K个数.cpp
//堆排序
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int>ans;
        if(!k)  return ans;
        priority_queue<int>q;
        
        for(auto num:arr)   {
            q.push(num);
            if(q.size() > k)    {
                q.pop();
            }
        }
        while(!q.empty())   {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};

//快排，O(n)
class Solution {
public:
    int Partition(vector<int>& arr, int low, int high)  {
        int pivot = arr[low];
        while(low < high)   {
            while(low < high && arr[high] >= pivot) {
                high--;
            }
            arr[low] = arr[high];
            while(low < high && arr[low] <= pivot)  {
                low++;
            }
            arr[high] = arr[low];
        }
        arr[low] = pivot;
        return low;
    }

    void QuickSort(vector<int>& arr, int low, int high, int k) {
        if(low < high)  {
            int pivot = Partition(arr, low, high);
            if(pivot == k-1)    {
                return;
            }else if(pivot < k-1)   {
                QuickSort(arr, pivot+1, high, k);
            }else if(pivot > k-1)   {
                QuickSort(arr, low, pivot-1, k);
            }
        }
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int>ans;
        if(!k)  return ans;
        QuickSort(arr, 0, arr.size()-1, k);
        for(int i = 0; i < k; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};