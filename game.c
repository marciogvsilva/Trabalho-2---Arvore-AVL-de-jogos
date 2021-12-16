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

void master(){

}

GAME *insert(CIRCULAR_LIST *game_circular_list){
    GAME game;
    FILE *file = fopen("CSV.csv","r");
    fseek(file, 3, SEEK_SET);
    while(!feof(file)){
        fscanf(file, "%[^;]; %d; %[^(\r|\n)]", game.name, &game.year, game.company);
        insert_list(game_circular_list, game);
    }
    fclose(file);
}