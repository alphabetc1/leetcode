面试题56 - I. 数组中数字出现的次数.cpp

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        for(int num:nums) {
            tmp ^= num;
        }
        int flag = tmp & (-tmp);    //lowbit(tmp)

        vector<int>ans(2,0);
        
        for(int num:nums)   {
            if(num & flag)  {       //按该位为0还是1划分
                ans[0] ^= num;
            }else{
                ans[1] ^= num;
            }
        }
        
        return ans;
    }
};