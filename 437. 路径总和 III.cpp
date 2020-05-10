437. 路径总和 III.cpp
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
    int count = 0;
    void getCount(TreeNode* root, int sum)  {
        if(root)    {
            if(root->val == sum)    {
                count++;
            }
            getCount(root->left, sum - root->val);
            getCount(root->right, sum - root->val);
        }
    }

    void Inorder(TreeNode* root, int sum)   {
        if(root)    {
            getCount(root, sum);
            Inorder(root->left, sum);
            Inorder(root->right, sum);
        }
    }
    int pathSum(TreeNode* root, int sum) {
        Inorder(root, sum);
        return count;
    }
};