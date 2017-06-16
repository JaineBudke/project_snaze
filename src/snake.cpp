/**
 * @file    snake.cpp
 * @brief   Arquivo com as funcoes que implementam
                 a resolucao do labirinto.
 * @author  Daniel Barbosa (nome@email.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */


#include "snake.h"

/** @brief Tenta encontrar caminho para chegar na maçã.
     @return 1 se for possível, 0 se for impossível. */
bool Snake::solveMaze(){


    // TODO
    // FAZER ESSA PARTE ACHANDO REALMENTE DIRECAO VALIDA PARA A SNAKE

    // recuperar a posicao inicial automaticamente tbm
    Game::Position posInicial;
    posInicial.x = 3;  // coluna
    posInicial.y = 5;  // linha

    Game::Direction dir1;
    Game::Direction dir2;

    dir1.x = posInicial.x + 1;
    dir1.y = posInicial.y;

    dir2.x = dir1.x + 1;
    dir2.y = dir1.y;

    listDirections.push_back( dir1 );
    listDirections.push_back( dir2 );

}
