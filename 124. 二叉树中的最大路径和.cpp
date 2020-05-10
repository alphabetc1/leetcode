124. 二叉树中的最大路径和.cpp
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
    int res = INT_MIN;

    int Inorder(TreeNode* root)   {
        if(root)    {
            int leftSum = Inorder(root->left);
            int rightSum = Inorder(root->right);
            res = max(res, max(leftSum, rightSum));
            
            int count = root->val;
            if(leftSum > 0)  count += leftSum;
            if(rightSum > 0)    count += rightSum;
            res = max(res, count);

            leftSum = (leftSum == INT_MIN)?0:leftSum;
            rightSum = (rightSum == INT_MIN)?0:rightSum;
            return max(root->val, max(leftSum + root->val, rightSum + root->val));
        }
        return INT_MIN;
    }

    int maxPathSum(TreeNode* root) {
        Inorder(root);
        return res;
    }
};