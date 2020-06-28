class Solution {
public:
    vector<string> tmpRes;

    bool fnd(vector<string> &s, string t)   {
        if(s.empty())   return false;
        for(auto a:s)   {
            if(a == t)  {
                return true;
            }
        }
        return false;
    }

    bool difCheck(string &s1, string &s2)    {
        int cnt = 0;
        for(int i = 0; i < s1.size(); i++)  {
            cnt += (s1[i] != s2[i]);
            if(cnt > 1) return false;
        }
        return (cnt == 1);
    }

    bool dfs(int cnt, string beginWord, string endWord, vector<string>& wordList, bool vist[]) {
        if(beginWord == endWord)    {
            tmpRes.push_back(beginWord);
            return true;
        }
        if(cnt >= wordList.size())    return false;
        for(int i = 0; i < wordList.size(); ++i) {
            if(!vist[i] && difCheck(beginWord, wordList[i])) {
                vist[i] = true;
                if(dfs(cnt+1, wordList[i], endWord, wordList, vist)) {
                    tmpRes.push_back(beginWord);
                    return true;
                }
            }
        }
        return false;
    }

    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string>ans;
        if(!fnd(wordList, endWord)) return ans;

        bool vist[wordList.size()];
        memset(vist, 0, sizeof(vist));

        if(dfs(0, beginWord, endWord,  wordList, vist))  {
            for(int i = tmpRes.size() - 1; i >= 0; --i) {
                ans.push_back(tmpRes[i]);
            }
        }
        return ans;
    }
};