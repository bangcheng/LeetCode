// Symmetric Tree
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric_1(struct TreeNode* left, struct TreeNode* right)
{
	if(left==NULL&&right==NULL)
		return 1;
	else if(left!=NULL&&right==NULL)
		return 0;
	else if(left==NULL&&right!=NULL)
		return 0;
	else if(left->val!=right->val)
        return 1;
	else 
		return isSymmetric_1(left->left,right->right)&&isSymmetric_1(left->right,right->left);
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)
    	return 1;
    else
    	return isSymmetric_1(root->left,root->right);
}