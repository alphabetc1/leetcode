301. 删除无效的括号.cpp
class Solution {
public:
    int maxSize;
    vector<string> ans;

    void dfs(string &s, string &path, int index, int now)  {
        if(!now)    {
            if(path.size() > maxSize)   {
                maxSize = path.size();
                ans.clear();
                ans.push_back(path);
            }else if(path.size() == maxSize)    {
                ans.push_back(path);
            }
        }
        if(index == s.size() || path.size() + s.size() - index < maxSize)    {
            return;
        }

        for(int i = index; i < s.size(); ++i)   {
            if(i > index && s[i] == s[i-1]) {
                continue;
            }
            int get = 0;
            if(s[i] == '(') {
                ++get;
            }else if(s[i] == ')')   {
                --get;
            }
            if(now + get >= 0)  {
                path += s[i];
                dfs(s, path, i+1, now + get);
                path.pop_back();
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        string str;
        maxSize = 0;
        dfs(s, str, 0, 0);
        
        if(!ans.size()) {
            ans.push_back("");
        }
        return ans;
    }
};