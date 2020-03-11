/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//��ǰ�汾/96/100
class Solution {
public:
	TreeNode * ans = NULL;
	bool findTree(TreeNode* root, TreeNode* nodeOne, TreeNode* nodeTwo) {
		if (!root)   return false;
		int nowFlag = (root == nodeOne) + (root == nodeTwo);	//��ǰ����Ƿ���������
		int leftFlag = findTree(root->left, nodeOne, nodeTwo);						//�������Ƿ���������
		int rightFlag = findTree(root->right, nodeOne, nodeTwo);					//�������Ƿ���������
		int count = nowFlag + leftFlag + rightFlag;
		if (count >= 2) {
			ans = root;
			return false;														//���ⱻ���ϲ�����ȸ���
		}
		if (root == nodeOne || root == nodeTwo || count)    return true;
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		findTree(root, p, q);
		return ans;
	}
};

//���°汾/60/100
class Solution {
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q)
			return root;
		TreeNode* leftRoot = lowestCommonAncestor(root->left, p, q);
		TreeNode* rightRoot = lowestCommonAncestor(root->right, p, q);
		if (leftRoot && rightRoot)
			return root;
		return leftRoot ? leftRoot : rightRoot;
	}
};