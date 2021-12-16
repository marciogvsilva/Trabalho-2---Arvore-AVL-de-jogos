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

CIRCULAR_LIST *create_avl_tree(); //Create a avl tree


int insert_list(CIRCULAR_LIST *game_circular_list, GAME game); //Insert in last position of circular list
void print_node_list(NODE *node); //Print node
void printAll_list(CIRCULAR_LIST *game_circular_list); //Print all nodes
int search_position_list(CIRCULAR_LIST *game_circular_list, int position); //Search position with number
int search_list(CIRCULAR_LIST *game_circular_list, GAME game, char option[2]); //search in circular list by company and year
int duplicate_node(CIRCULAR_LIST *game_circular_list); //remove duplicate nodes
int remove_list(CIRCULAR_LIST *game_circular_list, NODE *node); //Remove one position of circular list
void removeAll_list(CIRCULAR_LIST *game_circular_list);//Remove all positions of circular list
int move_list(CIRCULAR_LIST *game_circular_list, int position, int number, char option[2]); //move node to right or left

#endif //AVL_TREE_H