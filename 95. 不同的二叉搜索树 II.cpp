95. 不同的二叉搜索树 II.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> getTree(int left, int right)  {
        if(left > right)   {
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        for(int i = left; i <= right; i++)  {
            vector<TreeNode*> leftTrees = getTree(left, i-1);
            vector<TreeNode*> rightTrees = getTree(i+1, right);

            for(auto leftTree:leftTrees)    {
                for(auto rightTree:rightTrees)  {
                    TreeNode* newNode = new TreeNode(i);
                    newNode->left = leftTree;
                    newNode->right = rightTree;
                    allTrees.emplace_back(newNode);
                }
            }
        }
        return allTrees;
    }


    vector<TreeNode*> generateTrees(int n) {
        if(!n)  return {};
        return getTree(1, n);
    }
};