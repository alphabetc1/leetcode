496. 下一个更大元素 I.cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> v;
        vector<int> res(nums1.size(), 0);
        vector<int> tmp(nums2.size(), 0);
        if(!nums1.size())   return res;
        v[nums2[nums2.size()-1]] = -1;
        for(int i = nums2.size()-2; i >= 0; i--)    {
            if(nums2[i] < nums2[i+1])   {
                tmp[i] = 1;
                v[nums2[i]] = nums2[i+1];
            }else{
                int index = i+1;
                while(tmp[index] != 0) {
                    if(nums2[i] < nums2[index]) {break;}
                    else {index += tmp[index];}
                }
                if(nums2[i] < nums2[index]) {
                    tmp[i] = index - i;
                    v[nums2[i]] = nums2[index];
                }else{
                    v[nums2[i]] = -1;
                }
            }
        }
        for(int i = 0; i < nums1.size(); i++)   {
            res[i] = v[nums1[i]];
        }
        return res;
    }
};