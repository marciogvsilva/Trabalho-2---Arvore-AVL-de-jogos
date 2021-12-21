/*
Arquivo: avl_tree.h
Autores:
    Marcio Guilherme Vieira Silva - 11355786
    Matheus Jardim de Ornellas - 5469509
*/

#ifndef AVL_TREE_H
#define AVL_TREE_H

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define max(a, b) ((a > b) ? a : b)

#include "game.h"

typedef struct node NODE;
typedef struct avl_tree AVL_TREE;

//extern functions
AVL_TREE *create_avl_tree(); //create a avl tree
void insert_avl_tree(AVL_TREE *avl_tree, GAME *game); //insert in avl tree node by node and balance
void pre_ordem_avl_tree(AVL_TREE *avl_tree); //print avl tree in pre-ordem format
void in_ordem_avl_tree(AVL_TREE *avl_tree); //print avl tree in in-ordem format
void post_ordem_avl_tree(AVL_TREE *avl_tree); //print avl tree in post-ordem format
/*void remove_avl_tree(AVL_TREE *avl_tree, int year); //remove a node of avl tree and balance
void removeAll_avl_tree(AVL_TREE *avl_tree); //remove all nodes of avl three
*/
#endif //AVL_TREE_H