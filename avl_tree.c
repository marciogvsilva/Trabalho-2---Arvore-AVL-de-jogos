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
    AVL_TREE *avl_tree = (AVL_TREE *) calloc(sizeof(CIRCULAR_LIST), 1);
    return avl_tree;
}





int insert_avl_tree(AVL_TREE *avl_tree, GAME game){
    if(!avl_tree){ //if avl tree dont exists, return error
        print("Error in insert\n");
        return ERROR;
    }
    
    if(avl_tree->root == NULL){ //insert em firts position

    }else if(avl_tree->root != NULL){ //

        return TRUE;
    }

    print("Dont insert\n");
    return FALSE;
}

int search_list(CIRCULAR_LIST *game_circular_list, GAME game, char option[2]){
    if(!game_circular_list) return ERROR; //If circular list dont exists, return error

    if(!game_circular_list->first) return FALSE; //If first position of circular list dont exists, return false

    NODE *aux = game_circular_list->first;
    do{
        //If this position equal name of game, she print
        if(strcmp(option, "a") == 0 && aux->game.year == game.year){
            print_node_list(aux);
            printf("\n");
        }        
        else if(strcmp(option, "p") == 0 && strcmp(aux->game.company, game.company) == 0){
            print_node_list(aux);
            printf("\n");
        }
        aux = aux->next;
    }while(aux == game_circular_list->first); //Searching while aux is different of first position of circular list

    return TRUE;
}

int search_position_list(CIRCULAR_LIST *game_circular_list, int position){
    if(!game_circular_list) return ERROR; //If circular list dont exists, return error

    if(!game_circular_list->first) return FALSE; //If first position of circular list dont exists, return false
    
    NODE *aux = game_circular_list->first;
    for (int i = 0; i < position; i++) aux = aux->next; //count positions in the list until the beam
    print_node_list(aux);
    return TRUE;
}

int duplicate_node(CIRCULAR_LIST *game_circular_list){
    if(!game_circular_list) return ERROR; //If circular list dont exists, return error

    if(!game_circular_list->first) return FALSE; //If first position of circular list dont exists, return false
    
    NODE *aux_extern = game_circular_list->first->previous;
    NODE *aux_intern = game_circular_list->first;
    do{
        aux_extern = aux_extern->next;
        do{
            aux_intern = aux_intern->next;
            if(aux_intern != aux_extern){
                if(strcmp(aux_intern->game.name, aux_extern->game.name) == 0
                    && aux_intern->game.year == aux_extern->game.year
                    && strcmp(aux_intern->game.company, aux_extern->game.company) == 0){
                    remove_list(game_circular_list, aux_intern);
                }
            }
            aux_intern = aux_intern->next;
        }while(aux_intern != game_circular_list->first->previous);
    }while(aux_extern != game_circular_list->first->previous); //Searching while aux is different of first position of circular list
    
    return TRUE;
}

int move_list(CIRCULAR_LIST *game_circular_list, int position, int number, char option[2]){
    if(!game_circular_list) return ERROR; //If circular list dont exists, return error

    if(!game_circular_list->first) return FALSE; //If first position of circular list dont exists, return false
    
    NODE *old_position = game_circular_list->first;
    for (int i = 0; i < position; i++) old_position = old_position->next; //pointer to find position of node

    NODE *node = (NODE *) calloc(sizeof(NODE), 1);
    node->game = old_position->game;
    
    NODE *new_position_previous = old_position; //pointer to find the previous position the new
    remove_list(game_circular_list, old_position);

    if(strcmp(option, "ml") == 0) for (int i = 0; i < number-1; i++) new_position_previous = new_position_previous->previous;
    //use option to set the direction of pointer, left
    
    else if(strcmp(option, "mr") == 0) for (int i = 0; i < number-1; i++) new_position_previous = new_position_previous->next;
    //use option to set the direction of pointer, right

    NODE *new_position = new_position_previous->next; //pointer for new position of list
    new_position_previous->next = node;
    new_position->previous = node;
    node->next = new_position;
    node->previous = new_position_previous;
    
    return TRUE;
}

/*Auxiliar Functions*/
void print_node_list(NODE *node){
    if(!node) return;
    printf("%s", node->game.name);
}

void printAll_list(CIRCULAR_LIST *game_circular_list){
    if(!game_circular_list) return; //If circular list dont exists, return error

    if(!game_circular_list->first) return; //If first position of circular list dont exists, return false
    
    NODE *aux = game_circular_list->first;
    do{
        print_node_list(aux);
        aux = aux->next;
    }while(aux != game_circular_list->first->previous); //Searching while aux is different of first position of circular list
    printf("\n");
}

int remove_list(CIRCULAR_LIST *game_circular_list, NODE *node){
    if(!game_circular_list) return ERROR; //If circular list dont exists, return error

    if(!game_circular_list->first) return FALSE; //If first position of circular list dont exists, return false
    
    NODE *previous_node = node->previous;
    previous_node->next = node->next;
    node->previous = previous_node;
    free(node);
    return TRUE;
}

void removeAll_list(CIRCULAR_LIST *game_circular_list){
    do{
        remove_list(game_circular_list, game_circular_list->first->previous);
    }while(game_circular_list->first);
    free(game_circular_list->first);
    free(game_circular_list);
}