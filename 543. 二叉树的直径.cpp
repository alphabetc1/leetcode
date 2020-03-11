#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 100010
using namespace std;

bool cmp(const int &a, const int &b) {
	return a > b;
}


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int ans;
	int getMaxDepth(TreeNode* root) {
		if (!root)	return 0;
		int leftDepth = getMaxDepth(root->left);
		int rightDepth = getMaxDepth(root->right);
		ans = max(ans, rightDepth + leftDepth);
		return max(leftDepth, rightDepth)+1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root)	return 0;
		ans = 0;
		getMaxDepth(root);
		return ans;
	}
};