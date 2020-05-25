264. 丑数 II.cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n+1, 0);
        nums[1] = 1;
        int sum = 1, i_2 = 1, i_3 = 1, i_5 = 1;
        while(sum < n)  {
            int temp = min(min(nums[i_2] * 2, nums[i_3] * 3), nums[i_5] * 5);
            sum++;
            nums[sum] = temp;
            if(temp == nums[i_2] * 2) {
                i_2++;
            }
            if(temp == nums[i_3] * 3)   {
                i_3++;
            }
            if(temp == nums[i_5] * 5){
                i_5++;
            }
        }
        return nums[n];
    }
};