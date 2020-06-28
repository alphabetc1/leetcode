剑指 Offer 07. 重建二叉树.cpp
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
    TreeNode* getTree(vector<int>& preorder, vector<int>& inorder, int st1, int ed1, int st2, int ed2) {
        if(st1 > ed1)   return NULL;

        TreeNode* root = new TreeNode(preorder[st1]);
        
        int i;
        for(i = st2; i <= ed2 && inorder[i] != preorder[st1]; i++);
        
        root->left = getTree(preorder, inorder, st1+1, st1+i-st2, st2, i-1);
        root->right = getTree(preorder, inorder, st1+i-st2+1, ed1, i+1, ed2);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size())    return NULL;
        return getTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};