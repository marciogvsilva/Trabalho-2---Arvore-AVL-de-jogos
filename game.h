/*
Arquivo: game.h
Autores:
    Marcio Guilherme Vieira Silva - 11355786
    Matheus Jardim de Ornellas - 5469509
*/

#ifndef GAME_H
#define GAME_H

typedef struct game GAME;

GAME *create_game(); //create game for insertion
GAME *play_game(FILE *file); //read the file line and return game
void print_game(GAME *game); //print game
/*
boolean item_apagar(ITEM **item);
void item_imprimir(const ITEM *item);
int item_get_chave(const ITEM *item);
boolean item_set_chave(ITEM *item, int chave);
*/

#endif //GAME_H