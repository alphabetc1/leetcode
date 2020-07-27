面试题 10.03. 搜索旋转数组.cpp

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        if(-1 == r) return -1;

        while(l < r)   {
            int mid = l + ((r - l) >> 1);
            if(arr[l] < arr[mid])   {
                if(arr[l] <=  target && target <= arr[mid])   {
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }else if(arr[l] > arr[mid]) {
                if(arr[l] <= target || target <= arr[mid])  {
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }else if(arr[l] == arr[mid])    {
                if(arr[l] == target)    {
                    r = l;
                }else{
                    l++;
                }
            }
        }
        return arr[l] == target?l:-1;
    }
};