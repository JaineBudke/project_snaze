/**
 * @file    snake.h
 * @brief   Arquivo cabeçalho com as informacoes do jogador (snake).
 * @author  Edivânia Pontes (edivaniapts@gmail.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */

#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "game.h"
#include "master.h"
#include <deque>
#include <stack>
#include <cassert>


/**
 *  Essa eh a classe Snake
 *  Aqui sao definidas as funcoes e variaveis responsáveis pelas
 *  informacoes do jogador (snake).
 */
class Snake {

	public:
        //** @brief Criando um Snake vazio (inicializacao).
	    Snake() : sizeSnake(0) { /* empty */ }


        /** @brief Tenta encontrar caminho para chegar na maçã.
            @return 1 se for possível, 0 se for impossível. */
        bool solveMaze( std::vector<std::string> currentBoard, Position initialPosition, Position sizeBoard, Position apple );

        /*! @brief verificar se posição passsada faz parte do corpo da cobra
         *        obs: não considerar a ultima posição como parte do corpo
         *  @return true se for uma posição em que a cobra ocupa, falsa caso contrário
         */
        bool is_body(const Position & pos) const;

	public:
	    int sizeSnake;                               //<! tamanho da cobra
        std::deque<Position> listDirections;         //<! lista de direcoes que a snake deve seguir
        int currentDirection;                        //<! direcao atual
        std::deque<Position> snake; 

};

#endif