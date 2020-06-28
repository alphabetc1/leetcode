面试题45. 把数组排成最小的数.cpp
class Solution {
public:
    string itoa(int x)  {
        stringstream tmp;
        tmp << x;
        return string(tmp.str());
    }

    static bool compare(string s1, string s2)  {
        if(s1 + s2 < s2 + s1)   return true;
        else return false;
    }

    string minNumber(vector<int>& nums) {
        vector<string> strings;
        for(auto num:nums)  {
            strings.push_back(itoa(num));
        }
        sort(strings.begin(), strings.end(), compare);
        string res;
        for(auto s:strings) {
            res += s;
        }
        return res;
    }
};