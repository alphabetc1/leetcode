300. 最长上升子序列.cpp
//二分法，O(nlogn)复杂度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(auto num:nums)  {
            if(!res.size() || num > res.back()) {
                res.push_back(num);
            }else{
                int left = 0, right = res.size() - 1;
                while(left <= right)    {
                    int mid = ((right - left) >> 1) + left;
                    if(res[mid] == num) {
                        left = mid;
                        break;
                    }else if(res[mid] < num)    {
                        left = mid + 1;
                    }else if(res[mid] > num)    {
                        right = mid - 1;
                    }
                }
                res[left] = num;
            }
        }
        return res.size();
    }
};