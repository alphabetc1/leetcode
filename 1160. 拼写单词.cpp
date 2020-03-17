1160. 拼写单词.cpp
//这道题用map比不过array
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<int,int>vis, use;
        for(auto c:chars)   {
            vis[c]++;
        }
        int ans = 0, i, j;
        for(i = 0; i < words.size(); i++)   {
            use.clear();
            for(j = 0; j < words[i].size() && vis[words[i][j]] && vis[words[i][j]] != use[words[i][j]]; j++){
                use[words[i][j]]++;
            }
            if(words[i].length() == j)  {
                ans += j; 
            }
        }
        return ans;
    }
};