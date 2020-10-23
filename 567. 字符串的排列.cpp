567. 字符串的排列.cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(128, 0);
        int count = 0;
        for(auto str:s1)    {
            need[str]++;
            count++;
        }
        int left = 0, right = 0;
        while(right < s2.size())    {
            if(need[s2[right]] > 0) {
                count--;
            }
            need[s2[right]]--;
            right++;
            while(!count)   {
                if(right - left == s1.size())   {
                    return true;
                }
                if(need[s2[left]] == 0)  {
                    count++;
                }
                need[s2[left]]++;
                left++;
            }
        }
        return false;
    }
};