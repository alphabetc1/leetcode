101. 对称二叉树.cpp
/*
**分为递归法和非递归法
**本质是设置两个指针，同时查询根节点的左右子树
*/

//递归版
class Solution {
public:
    bool check(TreeNode* p, TreeNode* q)    {
        if(!p && !q)    {
            return true;
        }else if(!q || !p)    {
            return false;
        }
        else return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

//非递归版
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left); q2.push(root->right);
        while(!q1.empty() && !q2.empty())   {
            TreeNode* top1 = q1.front(); q1.pop();
            TreeNode* top2 = q2.front(); q2.pop();
            if(!top1 && !top2)  {
                continue;
            }else if(top1 && !top2 || !top1 && top2)    {
                return false;
            }
            if(top1->val != top2->val)  return false;
            q1.push(top1->right);
            q1.push(top1->left);
            q2.push(top2->left);
            q2.push(top2->right);
        }
        return true;
    }
};