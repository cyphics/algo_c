#include <stdbool.h>
#include <stdint.h>

typedef struct Node {
    char *value;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct LinkedList {
    int length;
    Node *head;
    Node *tail;
} LinkedList;

LinkedList GetEmptyList(void);
void Append(LinkedList *list, char *value);
void Prepend(LinkedList *list, char *value);
char*  GetAt(LinkedList *list, int index);
char*  RemoveFirst(LinkedList *list);
char*  RemoveLast(LinkedList *list);
char*  RemoveAt(LinkedList *list, int index);
char*  RemoveFirst(LinkedList *list);
char*  RemoveLast(LinkedList *list);
void Clear(LinkedList *list);

