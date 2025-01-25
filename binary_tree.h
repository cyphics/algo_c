typedef struct BinaryNode {
    int value;
    struct BinaryNode *left;
    struct BinaryNode *right;
} BinaryNode;


int* PreOrderSearch(BinaryNode head);
