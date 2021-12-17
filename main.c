/*
Arquivo: main.c
Autores:
    Marcio Guilherme Vieira Silva - 11355786
    Matheus Jardim de Ornellas - 5469509
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "avl_tree.h"

int main(){
    AVL_TREE *avl_tree = create_avl_tree();

    play_game();

    char year[3];
    char option[3];
    
    scanf("%s", option);
    do{
        scanf("%s", year); //review
    }while(strcmp(year, "F") != 0);
    
    if(strcmp(option, "1") == 0) return 0; //tests

    /*
    if(strcmp(option, "1") == 0) pre_ordem_avl_tree(avl_tree);
        
    else if(strcmp(option, "2") == 0) in_ordem_avl_tree(avl_tree);
        
    else post_ordem_avl_tree(avl_tree);
    
    removeAll_avl_tree(avl_tree);*/
    free(avl_tree);

    return 0;
}