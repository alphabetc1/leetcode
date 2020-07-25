139. 单词拆分.cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        for(auto word:wordDict) {
            wordDictSet.insert(word);
        }
        vector<bool> dp(s.length()+1);
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++)    {
            for(int j = 0; j < i; j++)  {
                if(dp[j] && wordDictSet.find(s.substr(j, i-j)) != wordDictSet.end())    {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};