#include "binary_tree.h"
#include <stddef.h>
#include <stdlib.h>

BinaryNode *InitBinaryTree(void) {
  return GetNode(
      20,
      GetNode(50, 
          GetNode(100, NULL, NULL),
          GetNode(30, 
              GetNode(45, NULL, NULL), 
              GetNode(29, NULL, NULL))),
      GetNode(10,
          GetNode(15, NULL, NULL),
          GetNode(5, 
              GetNode(7, NULL, NULL), NULL)));
}

BinaryNode *InitBinaryTree2(void) {
    // BinaryNode *right = NULL;
    // BinaryNode *head = NULL;
    // BinaryNode *left = NULL;
    //
    // right = GetNode(7);
    // head = GetNode(5, right, NULL);
    // left = head;
    //
    // right = GetNode(15);
    // head = GetNode(10, right, left);
    //
    // BinaryNode *tmp = head;
    //
    // left = GetNode(21);
    // head = GetNode(29, NULL, left);
    //
    // BinaryNode *tmp2 = head;
    //
    // right = GetNode(49);
    // head = GetNode(45, right, NULL);
    // right = head;
    // left = tmp2;
    // head = GetNode(30, right, left);
    //
    // left = head;
    // right = GetNode(50, NULL, left);
    //
    // head = GetNode(20, tmp, right);
    // return head;
}

