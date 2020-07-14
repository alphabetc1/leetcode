144. 二叉树的前序遍历.cpp
//方法一
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(!s.empty() || p)  {
            if(p)   {
                ans.push_back(p->val);
                s.push(p);
                p = p->left;
            }else{
                p = s.top(); s.pop();
                p = p->right;
            }
        }
        return ans;
    }
};

//方法二，其实一样
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(!s.empty() || p)  {
            while(p)    {
                ans.push_back(p->val);
                s.push(p);
                p = p->left;
            } 
            p = s.top(); s.pop();
            p = p->right;
        }
        return ans;
    }
};