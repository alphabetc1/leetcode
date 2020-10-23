//log(n+m)版本
class Solution {
public:
    double GetMid(vector<int>& nums1, int st1, int ed1, vector<int>& nums2, int st2, int ed2, int k) {
        int len1 = ed1 - st1 + 1;
        int len2 = ed2 - st2 + 1;
        if(len1 <= 0)    {
            return nums2[st2 + k - 1];
        }else if(len2 <= 0) {
            return nums1[st1 + k - 1];
        }
        if(k == 1)  {
            return min(nums1[st1], nums2[st2]);
        }

        int i = st1 + min(len1, k>>1) - 1;
        int j = st2 + min(len2, k>>1) - 1;

        if(nums1[i] < nums2[j]) {
            return GetMid(nums1, i+1, ed1, nums2, st2, ed2, k - (i - st1 + 1));
        }else   {
            return GetMid(nums1, st1, ed1, nums2, j+1, ed2, k - (j - st2 + 1));
        }
        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int left = (n+m+1)>>1, right = (n+m+2)>>1;
        return (GetMid(nums1, 0, n-1, nums2, 0, m-1, left) + GetMid(nums1, 0, n-1, nums2, 0, m-1, right))*0.5;
    }
};