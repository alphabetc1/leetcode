1585. 检查字符串是否可以通过排序子字符串得到另一个字符串.cpp
class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<queue<int>> v(10);
        for(int i = 0; i < s.size(); ++i)  {
            v[s[i] - '0'].push(i);
        }
        for(int i = 0; i < t.size(); ++i)   {
            int digit = t[i] - '0';
            if(v[digit].empty())  {
                return false;
            }
            for(int j = 0; j < digit; ++j)  {
                if(!v[j].empty() && v[j].front() < v[digit].front())  {
                    return false;
                }
            }
            v[digit].pop();
        }
        return true;
    }
};