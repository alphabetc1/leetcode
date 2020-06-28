面试题38. 字符串的排列.cpp
//用next_permutation的版本
class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> res;
        
        do  {
            res.push_back(s);
        }while(next_permutation(s.begin(), s.end()));

        return res;
    }
};


//回溯
class Solution {
public:
    vector<string> res;

    void dfs(string s, int pos) {
        if(pos == s.size() - 1) {
            res.push_back(s);
            return;
        }
        for(int i = pos; i < s.size(); i++) {
            if(i != pos && s[i] == s[pos])  continue;
            swap(s[i], s[pos]);
            dfs(s, pos+1);
        }
    }

    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        dfs(s, 0);
        return res;
    }
};