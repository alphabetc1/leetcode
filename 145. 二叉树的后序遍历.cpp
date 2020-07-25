145. 二叉树的后序遍历.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//方法一
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if(!root)   return ans;
        
        s.push(root);
        while(!s.empty())   {
            TreeNode* top = s.top(); s.pop();
            if(top) {
                s.push(top);
                s.push(NULL);
                if(top->right)  { 
                    s.push(top->right);
                }
                if(top->left)   {
                    s.push(top->left);
                }
            }else{
                ans.push_back(s.top()->val);
                s.pop();
            }
        }
        return ans;
    }
};

