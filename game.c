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

struct game{
    char name[50];
    int year;
    char company[20];
};

GAME *create_game(){
    GAME *game = (GAME *) calloc(sizeof(GAME), 1);
    return game;
}

GAME *play_game(FILE *file){
    GAME *game = create_game();
    fscanf(file, "%[^;]; %d; %[^(\r|\n)]", game->name, &game->year, game->company);
    return game;
}

void print_game(GAME *game){
    printf("%s\n", game->name);
}