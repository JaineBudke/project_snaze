/**
 * @file    snake.h
 * @brief   Arquivo cabeçalho com as informacoes do jogador (snake).
 * @author  Daniel Barbosa (nome@email.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */

#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "game.h"
#include "stack"


/**
 *  Essa eh a classe Snake
 *  Aqui sao definidas as funcoes e variaveis responsáveis pelas
 *  informacoes do jogador (snake).
 */
class Snake {

	public:
        //** @brief Criando um Snake vazio (inicializacao).
	    Snake() : sizeSnake(1) { /* empty */ }


        /** @brief Tenta encontrar caminho para chegar na maçã.
            @return 1 se for possível, 0 se for impossível. */
        bool solveMaze();


	public:
	    int sizeSnake;                               //<! tamanho da cobra
        std::vector<Game::Position> listDirections;  //<! lista de direcoes que a snake deve seguir
        int currentDirection;                        //<! direcao atual

};

#endif