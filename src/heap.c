#include "heap.h"
#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

Heap GetHeap(void){
    Heap heap = {
        .head = NULL,
        .length = 0
    };
    return heap;
}

#define IS_HEAD(a, b) ((a == NULL || a->value < b))

static BinaryNode* MinNodeInsert(BinaryNode *head, int new){
    if (head == NULL) {
        head = GetNode(new, NULL, NULL);
        return head;
    } 
    if (head->value < new)  { // pass new value forward (to smallest)
        if (NumChildren(head->left) <= NumChildren(head->right)) {
            head->left = MinNodeInsert(head->left, new);
            return head;
        } else {
            head->right = MinNodeInsert(head->right, new);
            return head;
        }
    } else { // New becomes head
        BinaryNode *new_node;
        BinaryNode *new_left;
        BinaryNode *new_right;
        if (NumChildren(head->left) <= NumChildren(head->right)) {
            new_left = head;
            new_right = head->right;
            new_left->right = NULL;
            // new_node = GetNode(new, head, head->right);
            // if (head->left != NULL) {
            //     head->left->left = NULL;
            // }
        } else {
            new_right = head;
            new_left = head->left;
            new_right->left = NULL;
            // new_node = GetNode(new, head->left, head);
            // if (head->right != NULL) {
            //     head->right->right = NULL;
            // }
        }
        new_node = GetNode(new, new_left, new_right);
        return new_node;
    }
}

void MinHeapInsert(Heap *heap, int new){
    BinaryNode *head = heap->head;
    BinaryNode *new_head = MinNodeInsert(head, new);
    heap->length++;
    heap->head = new_head;
}

BinaryNode *MergeNodes(BinaryNode *n1, BinaryNode *n2) {
    // printf("mergine %i with %i", n1->value, n2->value);
    if (n1 == NULL && n2 == NULL) {
        return NULL;
    }
    if (n1 == NULL ) {
        return n2;
    }
    if (n2 == NULL ) {
        return n1;
    }
    if (n1->value <= n2->value) {
        BinaryNode *left = MergeNodes(n1->left, n1->right);
        n1->left = left;
        n1->right = n2;
        return n1;
    } else {
        BinaryNode *right = MergeNodes(n2->left, n2->right);
        n2->right = right;
        n2->left = n1;
        return n2;
    }
}

int  MinHeapDelete(Heap *heap){
    heap->length--;
    BinaryNode *to_remove = heap->head;
    if (to_remove == NULL) {
        return NULL;
    }
    int val = to_remove->value;
    BinaryNode *left = to_remove->left;
    BinaryNode *right = to_remove->right;
    free(to_remove);
    if (left == NULL || right == NULL) {
        if (left == NULL && right == NULL) {
            heap->head = NULL;
            return val;
        }
        if (left == NULL) {
            heap->head = right;
        }
        if (right == NULL) {
            heap->head = left;
        }
    } else {
        if(left->value <= right->value) {
            left->left = MergeNodes(left->left, left->right);
            left->right = right;
            heap->head = left;
        } else {
            right->right = MergeNodes(right->left, right->right);
            right->left = left;
            heap->head = right;
        }
    }
    return val;
}

void PrintNode(BinaryNode *node) {
    if (node == NULL) {
        printf("NULL");
        return;
    }

    printf("[%i, ", node->value);
    PrintNode(node->left);
    printf(", ");
    PrintNode(node->right);
    printf("]");

}

void PrintHeap(Heap *heap) {
    PrintNode(heap->head);
    printf("\n");
}

