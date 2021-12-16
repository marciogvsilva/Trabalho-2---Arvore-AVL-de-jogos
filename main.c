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

int main(int argc, char const *argv[]){
    AVL_TREE *avl_tree = create_avl_tree();

    insert(game_circular_list);

    int position, number;
    char option[2];
    do{
        scanf("%c", option);
        if(strcmp(option, "r") == 0) duplicate_node(game_circular_list);
        
        else if(strcmp(option, "p") == 0){ //review
            GAME game;
            scanf("%s", game.company);
            search_list(game_circular_list, game, option);
        }
        
        else if(strcmp(option, "a") == 0){ //review
            GAME game;
            scanf("%d", &game.year);
            search_list(game_circular_list, game, option);
        }
        
        else if(strcmp(option, "i") == 0) printAll_list(game_circular_list);
        
        else if(strcmp(option, "u") == 0){
            scanf("%d", &position);
            search_position_list(game_circular_list, position);
        }
        
        else if(strcmp(option, "mr") == 0 || strcmp(option, "ml") == 0){ //review
            scanf("%d %d", &position, &number);
            move_list(game_circular_list, position, number, option);
        }
    }while(strcmp(option, "F") != 0);

    //imprimir arvore e desalocar toda memoria alocada dinamicamente

    //removeAll_list(game_circular_list); //review
    return 0;
}