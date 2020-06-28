5438. 制作 m 束花所需的最少天数.cpp
//二分二分二分!!!
class Solution {
public:
    int getNum(vector<int>&bloomDay, int thres, int k)    {
        int tag = 0, res = 0;
        for(int i = 0; i < bloomDay.size(); ++i)    {
            if(bloomDay[i] <= thres) {
                tag++;
                if(tag == k)    {
                    res++;
                    tag = 0;
                }
            }else{
                tag = 0;
            }
        }
        return res;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m * k > bloomDay.size()) return -1;
        
        int left = 1, right = 1e9, res = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            int num = getNum(bloomDay, mid ,k);
            if(num >= m) {
                right = mid - 1;
                res = mid;
            }else{
                left = mid + 1;
            }
        }
        return res;
    }
};