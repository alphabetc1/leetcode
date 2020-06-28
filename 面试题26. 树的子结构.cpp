面试题26. 树的子结构.cpp
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
    bool isEqual(TreeNode* A, TreeNode* B)    {
        if(!B)  return true;
        else if(!A) return false;
        else if(A->val != B->val)   return false;
        
        return isEqual(A->left, B->left) && isEqual(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A && !B)    return true;
        if(!A || !B)  return false;
        
        return isSubStructure(A->left, B) || isSubStructure(A->right, B) || isEqual(A, B);
    }
};