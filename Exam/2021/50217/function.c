#include <stdio.h>
#include <stdlib.h>

#include "function.h"

ListNode* init_node(int data, ListNode *prev, ListNode *next) {
	ListNode *node = malloc(sizeof(ListNode));
	if (node == NULL) return NULL;
	node->data = data;
	node->prev = prev;
	node->next = next;
	return node;
}

void insert(LinkedList *list, int data) {
	if (list->head == NULL) {
		ListNode *node = init_node(data, NULL, NULL);
		if (node == NULL) return;
		list->head = node;
		list->tail = node;
		return;
	}
	ListNode *node = list->head;
	for (;node != NULL; node = node->next) {
		if (data > node->data && node->next == NULL) {
			ListNode *new_node = init_node(data, node, NULL);
			if (new_node == NULL) return;
			node->next = new_node;
			list->tail = new_node;
			return;
		}
		else if (data < node->data && node->prev == NULL) {
			ListNode *new_node = init_node(data, NULL, node);
			if (new_node == NULL) return;
			node->prev = new_node;
			list->head = new_node;
			return;
		}
		else if (data > node->data && data < node->next->data) {
			ListNode *new_node = init_node(data, node, node->next);
			if (new_node == NULL) return;
			node->next->prev = new_node;
			node->next = new_node;
			return;
		}
		else if (data < node->data && data > node->prev->data) {
			ListNode *new_node = init_node(data, node->prev, node);
			if (new_node == NULL) return;
			node->prev->next = new_node;
			node->prev = new_node;
		}
		else if (data == node->data && node->next == NULL) {
			ListNode *new_node = init_node(data, node, NULL);
			if (new_node == NULL) return;
			node->next = new_node;
			list->tail = new_node;
			return;
		}
		else if (data == node->data) {
			ListNode *new_node = init_node(data, node, node->next);
			if (new_node == NULL) return;
			node->next->prev = new_node;
			node->next = new_node;
			return;
		}
	}
	return;
}

void delete_head(LinkedList *list) {
	if (list->head == list->tail) {
		list->head = NULL;
		list->tail = NULL;
		return;
	}
	if (list->head != NULL) {
		ListNode *head = list->head;
		list->head = head->next;
		list->head->prev = NULL;
	}
	return;
}
void delete_tail(LinkedList *list) {
	if (list->head == list->tail) {
		list->head = NULL;
		list->tail = NULL;
		return;
	}
	if (list->tail != NULL) {
		ListNode *tail = list->tail;
		list->tail = tail->prev;
		list->tail->next = NULL;
	}
	return;
}
