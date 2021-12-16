/*
Arquivo: game.c
Autores:
    Marcio Guilherme Vieira Silva - 11355786
    Matheus Jardim de Ornellas - 5469509
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "avl_tree.h"

struct game{
    char name[50];
    int year;
    char company[20];
};

GAME *create_game(){
    GAME *game = (GAME *) calloc(sizeof(GAME), 1);
    return game;
}

void play_game(){
    GAME *game = create_game();
    FILE *file = fopen("CSV.csv","r");

    fseek(file, 3, SEEK_SET); //disregarding the 3 bytes of UTF-8
    
    while(!feof(file)){
        fscanf(file, "%[^;]; %d; %[^(\r|\n)]", game->name, &game->year, game->company);
        //insert_avl_tree(avl_tree, game);
    }

    fclose(file);
}

void print_game(GAME *game){
    printf("%s\n", game->name);
}