面试题 04.05. 合法二叉搜索树.cpp
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
    bool isSubBST(TreeNode* root, long minNow, long maxNow)    {
        return !root || (root->val > minNow && root->val < maxNow && isSubBST(root->left, minNow, root->val) 
        && isSubBST(root->right, root->val, maxNow));
    }
    bool isValidBST(TreeNode* root) {
        return isSubBST(root, LONG_MIN, LONG_MAX);
    }
};