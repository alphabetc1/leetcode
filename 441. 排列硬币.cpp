441. 排列硬币.cpp
//二分法
class Solution {
public:
    int arrangeCoins(int n) {
        long start = 1, end = sqrt(2*(long)n);
        while(start <= end)  {
            long k = (start + end) / 2;
            long sum = (k+1)*k/2;
            long nextSum = (k+2)*(k+1)/2;
            if(sum <= n && nextSum > n)    return k;
            else if(nextSum <= n)    {
                start = k+1;
            }
            else{
                end = k-1;
            }
        }
        return 0;
    }
};