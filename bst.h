// CS2211a 2023, Section 1
// Assignment 4
// Stephen Bian
// 251287906
// sbian23
// November 13th 2023
// ====== this is in bst.h
#include "data.h"
typedef struct
{
    Node *tree_nodes;
    unsigned char *is_free;
    int size;
} BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key key, int data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);