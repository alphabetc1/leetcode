4. 寻找两个有序数组的中位数.cpp
//平均划分为两份
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)   {
            vector<int> tmpV = nums2; nums2 = nums1; nums1 = tmpV;
            int tmp = m; m = n; n = tmp;
        }
        int iMin = 0, iMax = n, halfNum = (n + m + 1) / 2;
        while(iMin <= iMax)  {
            int i = (iMin + iMax) / 2;
            int j = halfNum - i;
            if(i < iMax && nums2[j-1] > nums1[i])    {
                iMin = i + 1;       //i is too small
            }
            else if(i > iMin && nums1[i-1] > nums2[j])   {
                iMax = i - 1;       //i is too large
            } 
            else{                   //i is ok
                int maxLeft = 0;
                if(!i)  {maxLeft = nums2[j-1];}
                else if(!j) {maxLeft = nums1[i-1];}
                else maxLeft = max(nums1[i-1], nums2[j-1]);
                if((n + m) % 2 == 1)  return maxLeft;

                int minRight = 0;
                if(i == n)  {minRight = nums2[j];}
                else if(j == m) {minRight = nums1[i];}
                else minRight = min(nums1[i], nums2[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int left = 0, right = nums1.size()-1;
        while(left <= right)    {
            int midLeft = ((right - left) >> 1) + 1;
            int midRight = GetMidRight();
            int leftSum = midLeft + midRight;
            int rightSum = n - midRight + m - midRight - 2
            if(leftSum == rightSum)   {

            }else if(leftSum < rightSum)    {
                left = midLeft + 1;
            }else if(leftSum > rightSum)    {
                right = midLeft - 1;
            }
        }
        return 0.0;
    }
};

