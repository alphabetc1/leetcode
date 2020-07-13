108. 将有序数组转换为二叉搜索树.cpp
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
    TreeNode* getTree(vector<int>& nums, int s, int t)    {
        if(s > t)   return NULL;
        int mid = (s+t+1)>>1;
        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left = getTree(nums, s, mid-1);
        node->right = getTree(nums, mid+1, t);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getTree(nums, 0, nums.size()-1);
    }
};