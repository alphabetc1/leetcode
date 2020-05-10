988. 从叶结点开始的最小字符串.cpp
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
    string res;
    void Inorder(TreeNode* root, string s1) {
        if(root)    {
            s1 += root->val+'a';
            if(!root->left && !root->right) {
                reverse(s1.begin(), s1.end());
                if(!res.length())   {
                    res = s1;
                }else{
                    int tmp = 0;
                    while(tmp < s1.length() && tmp < res.length())    {
                        if(s1[tmp] < res[tmp])  {
                            res = s1;
                            break;
                        }else if(s1[tmp] > res[tmp])   {break;}
                        tmp++;
                    }
                    if(tmp == s1.length())  {res = s1;}
                }
            }
            Inorder(root->left, s1);
            Inorder(root->right, s1);
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        Inorder(root, "");
        return res;
    }
};