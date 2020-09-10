76. 最小覆盖子串.cpp
//双指针
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        int count = 0;
        for(auto c:t)   {
            need[c]++;
            count++;
        }

        int left = 0, right = 0;
        int start = 0, maxLength = INT_MAX;

        while(right < s.size())   {
            if(need[s[right]] > 0)  {
                count--;
            }
            need[s[right]]--;
            if(!count)  {
                while(left < right && need[s[left]] < 0)    {
                    need[s[left]]++;
                    left++;
                }
                if(right - left + 1 < maxLength)    {
                    start = left;
                    maxLength = right - left + 1;
                }
                need[s[left]]++;
                left++;
                count++;
            }
            right++;
        }
        return maxLength == INT_MAX? "": s.substr(start, maxLength);
    }
};