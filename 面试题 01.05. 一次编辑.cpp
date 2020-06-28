面试题 01.05. 一次编辑.cpp
//双指针
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.size(), m = second.size();
        if(n - m > 1 || m - n > 1)  return false;
        
        int i = 0, j = n - 1, k = m - 1;

        while(i < n && i < m && first[i] == second[i])  {
            i++;
        }
        while(j >= 0 && k >= 0 && first[j] == second[k])    {
            j--, k--;
        }
        
        return j - i < 1 && k - i < 1;
    }
};