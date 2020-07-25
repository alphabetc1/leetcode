剑指 Offer 11. 旋转数组的最小数字.cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size()-1;
        while(left < right) {
            int mid = left + ((right - left) >> 1);
            if(numbers[mid] > numbers[right])   {
                left = mid + 1;
            }else if(numbers[mid] < numbers[left])  {
                right = mid;
            }else{
                right--;
            }
            
        }
        return numbers[left];
    }
};