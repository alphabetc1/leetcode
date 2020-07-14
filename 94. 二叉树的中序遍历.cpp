94. 二叉树的中序遍历.cpp
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*>s;
        TreeNode* p = root;

        while(!s.empty() || p)  {
            while(p)    {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }
};