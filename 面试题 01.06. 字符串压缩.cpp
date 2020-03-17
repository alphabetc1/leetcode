面试题 01.06. 字符串压缩.cpp
class Solution {
public:
    string compressString(string s) {
        if(!s.length()) return s;
        string res;
        int count = 1;
        char tmp = s[0];
        for(int i = 1; i < s.length(); i++)   {
            if(tmp == s[i])    {
                count++;
            }
            else{
                res += tmp;
                res += to_string(count);
                tmp = s[i];
                count = 1;
            }
        }
        res += tmp;
        res += to_string(count);
        if(res.length() >= s.length())  return s;
        else return res;
    }
};