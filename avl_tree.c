/*
Arquivo: avl_tree.c
Autores:
    Marcio Guilherme Vieira Silva - 11355786
    Matheus Jardim de Ornellas - 5469509
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "avl_tree.h"

struct node{
    GAME *game;
    NODE *node_left;
    NODE *node_right;
    int height;
};

struct avl_tree{
    NODE *root;
    int depth;
};

AVL_TREE *create_avl_tree(){
    AVL_TREE *avl_tree = (AVL_TREE *) calloc(sizeof(AVL_TREE), 1);
    return avl_tree;
}

/*
void insert_avl_tree(AVL_TREE *avl_tree, GAME *game){}

void remove_avl_tree(AVL_TREE *avl_tree, int key){}

void removeAll_avl_tree(AVL_TREE *avl_tree){}

void pre_ordem_avl_tree(AVL_TREE *avl_tree){}

void in_ordem_avl_tree(AVL_TREE *avl_tree){}

void post_ordem_avl_tree(AVL_TREE *avl_tree){}

void print_avl_tree(AVL_TREE *avl_tree){}
*/