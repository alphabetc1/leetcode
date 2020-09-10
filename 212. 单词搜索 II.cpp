class Trie{
public:
    bool isStr = false;
    string str;
    Trie *next[26] = {nullptr};

    Trie()  {}

    void insert(string str) {
        Trie *root = this;
        for(auto c:str) {
            if(root->next[c-'a'] == nullptr)  {
                root->next[c-'a'] = new Trie();
            }
            root = root->next[c-'a'];
        }
        root->isStr = true;
        root->str = str;
    }
};


class Solution {
public:
    int n, m;
    unordered_set<string> strVis;
    vector<string> ans;
    vector<vector<bool>> vis;
    int fw[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    void dfs(vector<vector<char>>& board, int x, int y, Trie *cur)  {
        if(cur->isStr == true)   {
            if(!strVis.count(cur->str)) {
                ans.push_back(cur->str);
                strVis.insert(cur->str);
            }
        }
        for(int i = 0; i < 4; ++i)  {
            int xx = x + fw[i][0], yy = y + fw[i][1];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy])   {
                continue;
            }
            if(cur->next[board[xx][yy]-'a'] != nullptr) {
                vis[xx][yy] = true;
                dfs(board, xx, yy, cur->next[board[xx][yy] - 'a']);
                vis[xx][yy] = false;
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = new Trie();
        n = board.size();
        if(!n)  {
            return {};
        }
        m = board[0].size();
        for(auto word:words)    {
            root->insert(word);
        }
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i)   {
            for(int j = 0; j < m; ++j)   {
                if(root->next[board[i][j] - 'a'])   {
                    vis[i][j] = true;
                    dfs(board, i, j, root->next[board[i][j] - 'a']);
                    vis[i][j] = false;
                }
            }
        }
        return ans;
    }
};