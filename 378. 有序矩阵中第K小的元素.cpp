378. 有序矩阵中第K小的元素.cpp
class Solution {
public:
    struct node{
        int row, col, sum;
        bool operator > (const node &e) const   {
            return sum > e.sum;
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node, vector<node>, greater<node>>q;

        for(int i = 0; i < matrix.size(); i++)  {
            q.push({i, 0, matrix[i][0]});
        }
        for(int i = 0; i < k-1; i++)  {
            node top = q.top(); q.pop();
            if(top.col+1 < matrix.size())   {
                q.push({top.row, top.col+1, matrix[top.row][top.col+1]});
            }
        }

        return q.top().sum;
    }
};