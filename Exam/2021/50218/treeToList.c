#include "treeToList.h"
#include <stdio.h>
#include <stdlib.h>

List treeToListFunc(TreeNode * root) {
	List ret_list;
	if (root == NULL) {
		ret_list.head = NULL;
		ret_list.tail = NULL;
		return ret_list;
	}
	if (root->value % 2 == 0) {
		ret_list.head = root;
		List left = treeToListFunc(root->left);
		List right = treeToListFunc(root->right);
		ret_list.head->right = NULL;
		if (left.head == NULL && right.head == NULL) {
			ret_list.tail = root;
			ret_list.tail->right = NULL;
			return ret_list;
		}
		if (left.head == NULL) {
			ret_list.head->left = right.head;
			ret_list.tail = right.tail;
		}
		else {
			ret_list.head->left = left.head;
			if (right.head == NULL) {
				ret_list.tail = left.tail;
			}
			else {
				left.tail->left = right.head;
				ret_list.tail = right.tail;
			}
		}
	}
	else {
		ret_list.head = root;
		List left = treeToListFunc(root->left);
		List right = treeToListFunc(root->right);
		ret_list.head->right = NULL;
		if (left.head == NULL && right.head == NULL) {
			ret_list.tail = root;
			ret_list.tail->right = NULL;
			return ret_list;
		}
		if (right.head == NULL) {
			ret_list.head->left = left.head;
			ret_list.tail = left.tail;
		}
		else {
			ret_list.head->left = right.head;
			if (left.head == NULL) {
				ret_list.tail = right.tail;
			}
			else {
				right.tail->left = left.head;
				ret_list.tail = left.tail;
			}
		}
	}
	return ret_list;
}
