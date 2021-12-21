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

    FILE *file = fopen("CSV.csv","r");

    fseek(file, 3, SEEK_SET); //disregarding the 3 bytes of UTF-8
    
    GAME *game;
    while(!feof(file)){
        game = play_game(file);
        insert_avl_tree(avl_tree, game);
    }
    fclose(file);

    char option[3];
    scanf("%s", option);

    char year_char[4];
    while(1){
        scanf("%s", year_char); //review
        if(strcmp(year_char, "F") == 0) break;
        else {
            int year_int = atoi(year_char);
            remove_avl_tree(avl_tree, year_int);
        }
    }

    if(strcmp(option, "1") == 0) pre_order_avl_tree(avl_tree);
        
    else if(strcmp(option, "2") == 0) in_order_avl_tree(avl_tree);
        
    else post_order_avl_tree(avl_tree);
    
    removeAll_avl_tree(avl_tree);
    free(avl_tree);

    return 0;
}