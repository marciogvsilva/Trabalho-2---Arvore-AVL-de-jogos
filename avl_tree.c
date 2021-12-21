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
static NODE *create_node(); //create node for avl tree
static int heigth_node(NODE *node); //returns heigth of node
static int balancing_factor(NODE *node); //return balancing factor of node
static void rotation_left(NODE *node); //make the rotation left
static void rotation_right(NODE *node); //make the rotation right
static void rotation_right_left(NODE *node); //make the rotation right, then another left
static void rotation_left_right(NODE *node); //make the rotation left, then another rifht

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
static int insert_auxiliar(NODE *root, GAME *game){
    NODE *aux = root;
    if(get_year_game(aux->game) < get_year_game(game)){
        if(insert_auxiliar(aux->node_left, game)){
            if(balancing_factor(aux) > 1){
                if(get_year_game(aux->game) < get_year_game(aux->node_left->game)) rotation_right(aux);
                else rotation_left_right(aux);
            }
        }
    }else if(get_year_game(aux->game) > get_year_game(game)){
        if(insert_auxiliar(aux->node_right, game)){
            if(balancing_factor(aux) > 1){
                if(get_year_game(aux->game) > get_year_game(aux->node_left->game)) rotation_left(aux);
                else rotation_right_left(aux);
            }
        }
    }else return FALSE;

    aux->height = max(heigth_node(aux->node_left), heigth_node(aux->node_right)) + 1;

    return TRUE;
}

void insert_avl_tree(AVL_TREE *avl_tree, GAME *game){
    if(!avl_tree || !game) return; //return if avl tree or game arent exists

    if(avl_tree->root == NULL){
        avl_tree->root = create_node();
        avl_tree->root->game = game;
        avl_tree->root->height = heigth_node(avl_tree->root);
        printf("insert in root sucessfuly\n");
        return;
    } else insert_auxiliar(avl_tree->root, game);

    //avl_tree->depth = update_depth_avl_tree();
}

//removal functions
/*void remove_avl_tree(AVL_TREE *avl_tree, int year){
    if(!avl_tree || !avl_tree->root) return; //return if avl tree or game arent exists

    NODE *aux = root;
    if(get_year_game(aux->game) < get_year_game(game)){
        if(remove_avl_tree(aux->node_left, year)){
            if(balancing_factor(aux) > 1){
                if(get_year_game(aux->game) < get_year_game(aux->node_left->game)) rotation_right(aux);
                else rotation_left_right(aux);
            }
        }
    }else if(get_year_game(aux->game) > get_year_game(game)){
        if(remove_avl_tree(aux->node_right, game)){
            if(balancing_factor(aux) > 1){
                if(get_year_game(aux->game) > get_year_game(aux->node_left->game)) rotation_left(aux);
                else rotation_right_left(aux);
            }
        }
    }else return FALSE;
}

void removeAll_avl_tree(AVL_TREE *avl_tree){}*/

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
static int heigth_node(NODE *node){
    if(node == NULL) return -1;
    return node->height;
}

static int balancing_factor(NODE *node){
    return labs((heigth_node(node->node_left)) - (heigth_node(node->node_right)));
}

static void rotation_right(NODE *node){//LL
    NODE *aux = node->node_left;
    node->node_left = aux->node_right;
    aux->node_right = node;

    node->height = max(heigth_node(node->node_left), heigth_node(node->node_right)) +1;
    aux->height = max(heigth_node(aux->node_left), heigth_node(aux->node_right)) +1;

    node = aux;
}

static void rotation_left(NODE *node){//RR
    NODE *aux = node->node_right;
    node->node_right = node->node_left;
    aux->node_left = node;

    node->height = max(heigth_node(node->node_left), heigth_node(node->node_right)) +1;
    aux->height = max(heigth_node(aux->node_left), heigth_node(aux->node_right)) +1;

    node = aux;
}

static void rotation_left_right(NODE *node){
    rotation_left(node->node_left);
    rotation_right(node);
}

static void rotation_right_left(NODE *node){
    rotation_right(node->node_right);
    rotation_left(node);
}