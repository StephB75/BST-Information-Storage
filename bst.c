// CS2211a 2023, Section 1
// Assignment 4
// Stephen Bian
// 251287906
// sbian23
// November 13th 2023
// ====== this is in bst.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
// Input: 'size': size of an array
// Output: a BStree,
// Effect: allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned char array of size+1 for member is_free
// set all entries of is_free to 1
// set member size to 'size';
BStree bstree_ini(int size)
{
    // initialize binary search tree
    BStree binarySearchTree;
    // initialize an integer that represents the size of the tree
    int newSize = size + 1;
    // Sets the binary search trees size to the size given through the parameters
    binarySearchTree.size = size;

    // Allocates memory for the is_free array
    binarySearchTree.is_free = (unsigned char *)malloc(newSize * sizeof(unsigned char));
    // allocates memory for the tree_node array
    binarySearchTree.tree_nodes = (Node *)malloc(newSize * sizeof(Node));

    // tierate through the is_free array setting all available indexes to 1 meaning they are free
    for (int k = 0; k < newSize; k++)
    {
        binarySearchTree.is_free[k] = 1;
    }

    // return the binary search tree
    return binarySearchTree;
}

// This method acts as a recursive helper for the bstree algorithm
// This method recursively calls itself going through the binary search tree until it finds an available spot to insert data
void bstree_insertHelper(Node *tree_nodes, unsigned char *is_free, Key key, int data, int tree_size, int indexOfArray)
{
    // if the index of the array is greater than the tree size, return
    if (indexOfArray > tree_size)
    {
        return;
    }
    // if the array at the index given is not free
    if (is_free[indexOfArray] != 1)
    {
        // if the comparator returns a value less than zero
        if (key_comp(tree_nodes[indexOfArray].key, key) < 0)
        {
            // go right using the insert helper method
            bstree_insertHelper(tree_nodes, is_free, key, data, tree_size, 2 * indexOfArray + 1);
        }
        // if the comparator returns a value greater than zero
        else if (key_comp(tree_nodes[indexOfArray].key, key) > 0)
        {
            // go left using the insert helper method
            bstree_insertHelper(tree_nodes, is_free, key, data, tree_size, 2 * indexOfArray);
        }
    }
    // the array at the index given is free
    else
    {
        // change the value in the array from a 1 to a 2 representing that it is NOT free
        is_free[indexOfArray] = 0;
        // change the key at the given index
        tree_nodes[indexOfArray].key = key;
        // change the data at the given index
        tree_nodes[indexOfArray].data = data;
        return;
    }
}

// Input: 'bst': a binary search tree
// 'key': a Key
// 'data': an integer
// Effect: 'data' with 'key' is inserted into 'bst'
// if 'key' is already in 'bst', do nothing
void bstree_insert(BStree bst, Key key, int data)
{
    // call the bstree insert helper method
    bstree_insertHelper(bst.tree_nodes, bst.is_free, key, data, bst.size, 1);
}

// This method acts as a recursive helper for the bstree traversal algorithm
void bstree_traversalHelper(Node *tree_nodes, unsigned char *is_free, int size, int index)
{
    // checking to see if index is out of bounds
    if (index > size)
    {
        return;
    }
    // checking to see if the index at the given array is free
    else if (is_free[index] == 1)
    {
        return;
    }

    // this is a in order traversal
    // Goes throught the left subtree
    bstree_traversalHelper(tree_nodes, is_free, size, 2 * index);
    // Using the print_node method in data.c, print out the nodes at the given index
    print_node(tree_nodes[index]);
    // Goes throught the right subtree
    bstree_traversalHelper(tree_nodes, is_free, size, 2 * index + 1);
}

// Input: 'bst': a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst)
{
    // call the bstree traversal helper method
    bstree_traversalHelper(bst.tree_nodes, bst.is_free, bst.size, 1);
}

// Input: 'bst': a binary search tree
// Effect: all dynamic memory used by bst are freed
void bstree_free(BStree bst)
{
    // iterating through the array
    for (int indexOfArray = 1; indexOfArray <= bst.size; indexOfArray++)
    {
        // if the array at the index is
        if (bst.is_free[indexOfArray] != 1)
        {
            // free the memory allocated for name
            free(bst.tree_nodes[indexOfArray].key.name);
        }
    }
    // free memory allocated for array is_free
    free(bst.is_free);

    // free memory allocated for array tree_nodes
    free(bst.tree_nodes);
}
