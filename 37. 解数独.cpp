37. 解数独.cpp
class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>> &rowUsed, vector<vector<bool>> &colUsed, 
    vector<vector<vector<bool>>> &boxUsed, int row, int col)  {
        //cout<<row<<" "<<col<<endl;
        if(col == 9)    {
            col = 0;
            row++;
            if(row == 9)    {
                return true;
            }
        }
        if(board[row][col] == '.')  {
            for(int i = 1; i <= 9; ++i) {
                if(rowUsed[row][i] || colUsed[col][i] || boxUsed[row/3][col/3][i])  {
                    continue;
                }
                cout<<row<<col<<endl;
                board[row][col] = i + '0';
                cout<<board[row][col]<<endl;
                rowUsed[row][i] = true;
                colUsed[col][i] = true;
                boxUsed[row/3][col/3][i] = true;

                if(dfs(board, rowUsed, colUsed, boxUsed, row, col+1))   {
                    return true;
                }

                board[row][col] = '.';
                rowUsed[row][i] = false;
                colUsed[col][i] = false;
                boxUsed[row/3][col/3][i] = false;
            }
        }else{
            return dfs(board, rowUsed, colUsed, boxUsed, row, col+1);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowUsed(9, vector<bool>(10, false));
        vector<vector<bool>> colUsed(9, vector<bool>(10, false));
        vector<vector<vector<bool>>> boxUsed(3, vector<vector<bool>>(3, vector<bool> (10, false)));

        for(int i = 0; i < 9; ++i)   {
            for(int j = 0; j < 9; ++j)    {
                if(board[i][j] != '.')  {
                    int num = board[i][j] - '0';
                    rowUsed[i][num] = true;
                    colUsed[j][num] = true;
                    boxUsed[i / 3][j / 3][num] = true;
                }
            }
        }

        dfs(board, rowUsed, colUsed, boxUsed, 0, 0);
    }
};