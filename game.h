/*
Arquivo: game.h
Autores:
    Marcio Guilherme Vieira Silva - 11355786
    Matheus Jardim de Ornellas - 5469509
*/

#ifndef GAME_H
#define GAME_H
#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef struct game GAME;

GAME *create_game(); //create game for insertion
GAME *play_game(FILE *file); //read the file line and return game
void print_game(GAME *game); //print game
int get_year_game(GAME *game); //return year of game

#endif //GAME_H