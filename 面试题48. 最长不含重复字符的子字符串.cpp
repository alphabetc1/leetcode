面试题48. 最长不含重复字符的子字符串.cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size())   return 0;
        int res = 1, tmp = 0;
        map<char, int> v;
        for(int i = 0; i < s.size(); i++)   {
            if(v.count(s[i]))   {
                tmp = tmp < i - v[s[i]]? tmp+1: i - v[s[i]];
            }else{
                tmp++;
            }
            v[s[i]] = i;
            res = max(tmp, res);
        }
        return res;
    }
};