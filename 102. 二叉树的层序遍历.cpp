102. 二叉树的层序遍历.cpp
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
        queue<TreeNode*>q;
        vector<vector<int>> res;
        if(!root)   return res;
        q.push(root);
        vector<int>slide;
        int now = 0, thres = 1, sum = 1;
        while(!q.empty())   {
            TreeNode* top = q.front();
            slide.push_back(top->val);
            now++;
            q.pop();
            if(top->left)   {
                q.push(top->left);
                sum++;
            }
            if(top->right)  {
                q.push(top->right);
                sum++;
            }
            if(now == thres)  {
                res.push_back(slide);
                slide.clear();
                thres = sum;
            }
        }
        return res;
    }
};