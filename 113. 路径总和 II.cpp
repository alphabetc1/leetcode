113. 路径总和 II.cpp
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
    vector<vector<int>> res;

    void Inorder(TreeNode* root, vector<int>& tmp, int sum)  {
        if(root)    {
            tmp.push_back(root->val);
            if(root->val == sum && !root->left && !root->right) {res.push_back(tmp);}
            Inorder(root->left, tmp, sum - root->val);
            Inorder(root->right, tmp, sum - root->val);
            tmp.pop_back();
        }    
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>tmp;
        Inorder(root, tmp, sum);
        return res;
    }
};