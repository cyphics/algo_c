#include "binary_tree.h"
#include <stddef.h>
#include <stdlib.h>

BinaryNode *GetNode(int value) {
    BinaryNode *node = malloc(sizeof(BinaryNode));
    node->right = NULL;
    node->left = NULL;
    node->value = value;
    return node;
}

BinaryNode *CreateHead(int value, BinaryNode *right, BinaryNode *left) {
    BinaryNode *head = GetNode(value);
    head->right = right;
    head->left = left;
    return head;
}

BinaryNode *InitBinaryTree(void) {
    BinaryNode *right = NULL;
    BinaryNode *head = NULL;
    BinaryNode *left = NULL;

    right = GetNode(45);
    left = GetNode(29);
    head = CreateHead(30, right, left);

    left = head;
    right = GetNode(100);
    head = CreateHead(50, left, right);

    BinaryNode *tmp = head;

    left = NULL;
    right = GetNode(7);
    head = CreateHead(5, right, left);
    
    left = head;
    right = GetNode(15);
    head = CreateHead(10, right, left);

    left = head;
    right = tmp;
    head = CreateHead(20, right, left);
    return head;
}

BinaryNode *InitBinaryTree2(void) {
    BinaryNode *right = NULL;
    BinaryNode *head = NULL;
    BinaryNode *left = NULL;

    right = GetNode(7);
    head = CreateHead(5, right, NULL);
    left = head;

    right = GetNode(15);
    head = CreateHead(10, right, left);
    
    BinaryNode *tmp = head;

    left = GetNode(21);
    head = CreateHead(29, NULL, left);

    BinaryNode *tmp2 = head;

    right = GetNode(49);
    head = CreateHead(45, right, NULL);
    right = head;
    left = tmp2;
    head = CreateHead(30, right, left);

    left = head;
    right = CreateHead(50, NULL, left);

    head = CreateHead(20, tmp, right);
    return head;
}


