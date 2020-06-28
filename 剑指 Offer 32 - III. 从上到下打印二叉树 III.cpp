剑指 Offer 32 - III. 从上到下打印二叉树 III.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;

        queue<TreeNode*> q;
        vector<int>tmp;
        int flag = 1, now = 0, sum = 1, thres = 1;
        q.push(root);

        while(!q.empty()) {
            TreeNode* top = q.front(); q.pop();
            tmp.push_back(top->val);
            now++;
            if(top->left)   {
                q.push(top->left);
                sum++;
            }
            if(top->right)  {
                q.push(top->right);
                sum++;
            }
            if(now == thres)    {
                if(flag == -1)   {
                    reverse(tmp.begin(), tmp.end());
                }
                ans.push_back(tmp);
                tmp.clear();
                flag *= -1;
                thres = sum;
            }
        }
        return ans;
    }
};