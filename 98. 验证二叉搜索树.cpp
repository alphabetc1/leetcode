98. 验证二叉搜索树.cpp
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
    bool getValidBst(TreeNode* root, long long minVal, long long maxVal)  {
        if(!root)   return true;
        if(root->val <= minVal || root->val >= maxVal)    return false;
        else return getValidBst(root->left, minVal, root->val) && getValidBst(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return (getValidBst(root, LONG_MIN, LONG_MAX));
    }
};