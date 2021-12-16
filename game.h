/*
Arquivo: game.h
Autores:
    Marcio Guilherme Vieira Silva - 11355786
    Matheus Jardim de Ornellas - 5469509
*/

#ifndef GAME_H
#define GAME_H

typedef struct game GAME;

GAME *create_game();
void play_game();
void print_game(GAME *game);
/*
boolean item_apagar(ITEM **item);
void item_imprimir(const ITEM *item);
int item_get_chave(const ITEM *item);
boolean item_set_chave(ITEM *item, int chave);
*/

#endif //GAME_H