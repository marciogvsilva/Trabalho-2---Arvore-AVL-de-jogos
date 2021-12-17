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

//intern functions
NODE *create_node(); //create node for avl tree
int heigth_node(NODE *node);
int balancing_factor(NODE *node);
void rotation_left(NODE *node);
void rotation_right(NODE *node);
void rotation_right_left(NODE *node);
void rotation_left_right(NODE *node);

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

//creations functions
AVL_TREE *create_avl_tree(){
    AVL_TREE *avl_tree = (AVL_TREE *) calloc(sizeof(AVL_TREE), 1);
    return avl_tree;
}

NODE *create_node(){
    NODE *node = (NODE *) calloc(sizeof(NODE), 1);
    return node;
}

//insertion functions
void insert_avl_tree(AVL_TREE *avl_tree, GAME *game){
    if(!avl_tree || !game) return; //return if avl tree or game arent exists

    if(avl_tree->root == NULL){
        avl_tree->root = create_node();
        avl_tree->root->game = game;
        avl_tree->root->height = heigth_node(avl_tree->root);
        printf("insert in root sucessfuly");
        return;
    }

    //avl_tree->depth = update_depth_avl_tree();
}

//auxiliar insertion functions

/*
//removal functions
void remove_avl_tree(AVL_TREE *avl_tree, int key){}

void removeAll_avl_tree(AVL_TREE *avl_tree){}

//auxiliar removal functions
*/

//print functions
void in_order(NODE *node){
    if(node != NULL){
        in_order(node->node_left);
        print_game(node->game);
        in_order(node->node_right);
    }
}

void pre_order(NODE *node){
    if(node != NULL){
        print_game(node->game);
        in_order(node->node_left);
        in_order(node->node_right);
    }
}

void post_order(NODE *node){
    if(node != NULL){
        in_order(node->node_left);
        in_order(node->node_right);
        print_game(node->game);
    }
}

//auxiliar function
int heigth_node(NODE *node){
    if(node == NULL) return -1;
    return node->height;
}

int balancing_factor(NODE *node){
    return labs((heigth_node(node->node_left)) - (heigth_node(node->node_right)));
}

/*
void rotation_left(NODE *node){}
void rotation_right(NODE *node){}
void rotation_right_left(NODE *node){}
void rotation_left_right(NODE *node){}
*/