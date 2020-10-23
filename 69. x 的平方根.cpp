69. x 的平方根.cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)  {
            return x;
        }
        int left = 0, right = (x>>1) + 1;
        while(left < right) {
            int mid = ((right - left)>>1) + left;

            if(mid <= x / mid) {
                left = mid + 1;
            }else if(mid > x / mid)   {
                right = mid;
            }
        }
        return left - 1;
    }
};