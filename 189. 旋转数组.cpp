189. 旋转数组.cpp
//方法一：环状替代
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0, n = nums.size();

        for(int start = 0; count < n; ++start)  {
            int tmp = nums[start], cur = start;
            do{
                cur = (cur + k) % n;
                swap(tmp, nums[cur]);
                ++count;
            }while(cur != start);
        }
    }
};

//方法二：整体旋转，再分别旋转前k个和后n-k个，
//方法三：依次挪到队头；
//方法四：辅助数组