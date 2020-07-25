662. 二叉树最大宽度.cpp
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
    int widthOfBinaryTree(TreeNode* root) {
        if(nullptr == root) return 0;

        queue<pair<TreeNode*, unsigned long long>>q;
        q.push({root, 1});
        int ans = 0;
        while(!q.empty())   {
            int n = q.size();
            ans = max((int)(q.back().second - q.front().second + 1),ans);
            for(int i = 0; i < n; i++) {
                TreeNode *top = q.front().first;
                unsigned long long topNum = q.front().second;
                q.pop();
                if(top->left)   {
                    q.push({top->left, 2*topNum});
                }
                if(top->right)  {
                    q.push({top->right, 2*topNum+1});
                }
            }
        }
        return ans;
    }
};