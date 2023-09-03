#include <stdbool.h>
#include <stddef.h>
#include "isIsomorphic.h"

bool isIsomorphic(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL && root2 == NULL) return true;
	if (root1 == NULL && root2 != NULL) return false;
	if (root1 != NULL && root2 == NULL) return false;
	if (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->mid, root2->mid) && isIsomorphic(root1->right, root2->right)) return true;
	if (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->mid, root2->right) && isIsomorphic(root1->right, root2->mid)) return true;
	if (isIsomorphic(root1->left, root2->mid) && isIsomorphic(root1->mid, root2->left) && isIsomorphic(root1->right, root2->right)) return true;
	if (isIsomorphic(root1->left, root2->mid) && isIsomorphic(root1->mid, root2->right) && isIsomorphic(root1->right, root2->left)) return true;
	if (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->mid, root2->left) && isIsomorphic(root1->right, root2->mid)) return true;
	if (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->mid, root2->mid) && isIsomorphic(root1->right, root2->left)) return true;
	return false;
}
