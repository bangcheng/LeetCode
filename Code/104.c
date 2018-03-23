
// 104. Maximum Depth of Binary Tree
// Given a binary tree, find its maximum depth.

// The maximum depth is the number of nodes along 
// the longest path from the root node down to the farthest leaf node.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
	if(root==NULL) return 0;
    int m=maxDepth(root->left)+1;
    int n=maxDepth(root->right)+1;
    if(m<n)
    	return n;
    return m;
}