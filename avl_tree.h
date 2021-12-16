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

#include "game.h"

typedef struct node NODE;
typedef struct avl_tree AVL_TREE;

//functions that modify the avl tree
AVL_TREE *create_avl_tree(); //Create a avl tree

/*
void insert_avl_tree(AVL_TREE *avl_tree, GAME *game);
void remove_avl_tree(AVL_TREE *avl_tree, int key);
void removeAll_avl_tree(AVL_TREE *avl_tree);

//auxiliary function 
void pre_ordem_avl_tree(AVL_TREE *avl_tree);
void in_ordem_avl_tree(AVL_TREE *avl_tree);
void post_ordem_avl_tree(AVL_TREE *avl_tree);
void print_avl_tree(AVL_TREE *avl_tree);
*/

#endif //AVL_TREE_H