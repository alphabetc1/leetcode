687. 最长同值路径.cpp
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
    int res = 1;
    int Inorder(TreeNode* root)    {
        if(root)    {
            int leftSum = Inorder(root->left);
            int rightSum = Inorder(root->right);
            int count = 1, sum = 1;
            if(root->left && root->left->val == root->val)  {
                count += leftSum;
                sum += leftSum;
            }
            if(root->right && root->right->val == root->val)    {
                count += rightSum;
                sum = max(sum, 1 + rightSum);
            }
            res = max(res, count);
            return sum;
        }
        return 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        Inorder(root);
        return res - 1;
    }
};