面试题 17.15. 最长单词.cpp
class Solution {
public:
    bool dfs(set<string> &s, string word) {
        if(word.size() == 0)    {
            return true;
        }
        for(int i = 1; i <= word.size(); ++i)    {
            if(s.count(word.substr(0, i)) && dfs(s, word.substr(i)))   {
                return true;
            }
        }
        return false;
    }

    string longestWord(vector<string>& words) {
        set<string> s;
        for(auto word:words)    {
            s.insert(word);
        }
        sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
            return s1.size() == s2.size()? s1 < s2: s1.size() > s2.size();
        });
        
        for(auto word:words)    {
            s.erase(word);
            if(dfs(s, word)) {
                return word;
            }
        }
        return "";
    }
};