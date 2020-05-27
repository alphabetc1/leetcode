79. 单词搜索.cpp
/*关键点在于一旦找到可行路径马上return，不再修改board[row][col]，避免无意义的回溯
*/
class Solution {
public:
    int n, m;

    bool bfs(vector<vector<char>>& board, string& word, int row, int col, int index)   {
        if(index == word.size())    {
            return true;
        } else if(row < 0 || row >= n || col < 0 || col >= m || board[row][col] != word[index])    return false;

        board[row][col] += 128;

        if(bfs(board, word, row+1, col, index+1) || bfs(board, word, row-1, col, index+1)
            || bfs(board, word, row, col+1, index+1) || bfs(board, word, row, col-1, index+1))  {
                return true;
            }

        board[row][col] -= 128;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty())   return false;
        
        n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++)   {
            for(int j = 0; j < m; j++)    {
                if(board[i][j] == word[0])  {
                    if(bfs(board, word, i, j, 0))    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};