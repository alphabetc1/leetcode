679. 24 点游戏.cpp

class Solution{
    public:
    bool canGet(double *a, int num) {
        if(fabs(a[0] - 24) < 0.0001 && num == 1)    return true;
        else if(num > 1)    {
            for(int i = 0; i < num; i++)    {
                for(int j = 0; j < num; j++)    {
                    if(i == j)  continue;
                    int m = 0;
                    double b[4];
                    for(int k = 0; k < num; k++)    {
                        if(k != i && k != j)    {
                            b[m++] = a[k];
                        }
                    }
                    b[m] = a[i] + a[j];
                    if(canGet(b, m + 1))  return true;
                    b[m] = a[i] - a[j];
                    if(canGet(b, m + 1))  return true;
                    b[m] = a[i] * a[j];
                    if(canGet(b, m + 1))  return true;
                    if(a[j])    {
                        b[m] = a[i] / a[j];
                        if(canGet(b, m + 1))  return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& nums) {
        double a[4];
        for(int i = 0; i < 4; i++)  {
            a[i] = (double)nums[i];
        } 
        if(canGet(a, 4))    return true;
        else return false;   
    }
};