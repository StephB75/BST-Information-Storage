// CS2211a 2023, Section 1
// Assignment 4
// Stephen Bian
// 251287906
// sbian23
// November 13th 2023
// ====== this is in data.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
// Input: 'in_name': a string ends with '\0'
// 'in_num': an integer
// Output: a Key,
// Effect: copy in_name to Key's name
// set Key's num to be in_num
Key key_construct(char *in_name, int in_num)
{
    // create new key object
    Key newKey;
    // set new key name
    newKey.name = strdup(in_name);
    // set new key num
    newKey.num = in_num;
    return newKey;
}

// Input: 'key1' and 'key2' are two Keys
// Output: if return value < 0, then key1 < key2,
// if return value = 0, then key1 = key2,
// if return value > 0, then key1 > key2,
// Note: use strcmp() to compare key1.name and key2.name
// if key1.name = key2.name, then compare key1.num with key2.num
int key_comp(Key key1, Key key2)
{
    // declare comparor integer
    int comp;
    // use comparor function to compare key1 name and key2 name
    comp = strcmp(key1.name, key2.name);
    // if comparator is equal to zero, return the first key minus the second key, if the comparator is not zero, return the comparator value
    if (comp == 0)
    {
        return key1.num - key2.num;
    }
    else
    {
        return comp;
    }
}
// Input: 'key': a Key
// Effect: key.num key.name are printed
void print_key(Key key)
{
    // print the key name
    printf("%d %s ", key.num, key.name);
}
// Input: 'node': a node
// Effect: node.key is printed and then the node.data is printed
void print_node(Node node)
{
    // call the print_key method to print the key name
    print_key(node.key);
    // print the node data
    printf("%d \n", node.data);
}