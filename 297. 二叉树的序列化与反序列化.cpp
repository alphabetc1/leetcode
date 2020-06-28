297. 二叉树的序列化与反序列化.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string itoa(int num)    {s
        stringstream tmp;
        tmp<<num;
        return string(tmp.str());
    }

    string serialize(TreeNode* root) {
        string ans;
        if(!root)   {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())   {
            TreeNode *top = q.front(); q.pop();
            if(!top)    {
                ans += 'n';
            }else{
                ans += itoa(top->val);
                q.push(top->left);
                q.push(top->right);
            }
            ans += ',';
        }
        return ans; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = new TreeNode;
        if(!data.size())  return NULL;

        int i = 0, sgn = 1;
        if(data[i] == '-')  {
            sgn = -1;
            i++;
        }
        while(i < data.size() && data[i] != ',')   {
            root->val = root->val * 10 + data[i] - '0';
            i++;
        }
        root->val *= sgn;
        i++;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())   {
            TreeNode* top = q.front(); q.pop();
            
            if(i <= data.size() && data[i] != 'n') {
                TreeNode* left = new TreeNode;
                left->val = 0;
                sgn = 1;

                if(data[i] == '-')  {
                        sgn = -1;
                        i++;
                }

                while(i < data.size() && data[i] != ',')   {
                    left->val = left->val * 10 + data[i] - '0';
                    i++;
                }
                left->val *= sgn;
                top->left = left;
                q.push(left); 
            }
            if(i < data.size())     {
                if(data[i] == 'n') i+= 2;
                else i += 1;
            }

            if(i <= data.size() && data[i] != 'n') {
                TreeNode* right = new TreeNode;
                right->val = 0;
                sgn = 1;

                if(data[i] == '-')  {
                        sgn = -1;
                        i++;
                }
                while(i < data.size() && data[i] != ',')   {
                    
                    right->val = right->val * 10 + data[i] - '0';
                    i++;
                }
                right->val *= sgn;
                top->right = right;
                q.push(right); 
            }

            if(i < data.size())     {
                if(data[i] == 'n') i+= 2;
                else i += 1;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));