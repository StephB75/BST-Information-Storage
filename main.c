// CS2211a 2023, Section 1
// Assignment 4
// Stephen Bian
// 251287906
// sbian23
// November 13th 2023
// ====== this is a sample main program
#include <stdio.h>
#include <string.h>
#include "bst.h"

int main(void)
{
    // initializing integers
    int sizeOfTree, number, data, yesNo = 1;
    // initializing array
    char str[300];
    // initializing binary search tree
    BStree binarySearchTree;
    // prompting for tree size
    printf("Enter size of tree: ");
    // scanning user input
    scanf("%d", &sizeOfTree);
    // initializing the tree using the size given
    binarySearchTree = bstree_ini(sizeOfTree);

    // input buffering
    while (getchar() != '\n')
        ;

    while (yesNo == 1)
    {
        // prompting user for key information
        printf("Enter your key information (this should be a number followed by a string): ");
        // takes in user input
        scanf("%d ", &number);
        fgets(str, sizeof(str), stdin);

        // prompting user for data
        printf("Enter your data: ");
        // takes in user input
        scanf("%d", &data);

        // removing new line in char
        size_t L = strlen(str);
        if (str[L - 1] == '\n' && L > 0)
        {
            str[L - 1] = '\0';
        }

        // input buffering
        while (getchar() != '\n')
            ;

        // initializing key
        Key k = key_construct(str, number);
        // calling hte insert method to insert a record
        bstree_insert(binarySearchTree, k, data);

        // prompting ht user asking if they want to continue
        printf("To insert more records insert 1, to stop insert 2:");
        // recording the answer into yesNo
        scanf("%d", &yesNo);
    }
    // traversing through the tree
    bstree_traversal(binarySearchTree);
    // freeing all dynammic memory
    bstree_free(binarySearchTree);
}