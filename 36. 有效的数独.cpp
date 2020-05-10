36. 有效的数独.cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowBase, colBase, allBase = 0;
        int block[10][10] = {}, row[10][10] = {}, col[10][10] = {};
        for(int i = 0; i < board.size(); i++)   {
            rowBase = i / 3;
            if(i && i % 3 == 0)  allBase += 2;
            for(int j = 0; j < board[0].size(); j++)    {
                if(board[i][j] <= '9' && board[i][j] >= '0')    {
                    int num = board[i][j] - '0';
                    colBase = j / 3;
                    if(block[allBase+rowBase+colBase][num])   return false;
                    else{block[allBase+rowBase+colBase][num] = 1;} 
                    if(row[i][num])   return false;
                    else{row[i][num] = 1;}
                    if(col[j][num])   return false;
                    else{col[j][num] = 1;}
                }
            }
        }
        return true;
    }
};