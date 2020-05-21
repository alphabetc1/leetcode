769. 最多能完成排序的块.cpp
//滑动窗口
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       map<int, int> v;
       int res = 0, start = 0;
       for(int i = 0; i < arr.size(); i++)  {
           v[arr[i]] = 1;
           if(arr[i] == i && start == i)    {
               res++;
               start++;
               v.clear();
           }else if(v.rbegin()->first - v.begin()->first == i - start && start  == v.begin()->first)    {
               res++;
               start = i + 1;
               v.clear();
           }
       } 
       return res;
    }
};