/**
 * @file    snake.h
 * @brief   Arquivo cabeçalho com as informacoes do jogador (snake).
 * @author  Edivania Pontes (edivaniap@ufrn.edu.br)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    21/06/2017
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
        bool is_snakeBody(const Position & pos) const;

        /*! */
        bool is_valid_position( Position pos, Position size );

        /*! @brief determina se uma posição é válida e relação a um tabuleiro
         *  @param pos posição a ser analisada
         *  @param size dimensoes do tabuleiro
         *  @return true se a posição for válida, false caso contrário */
        Position adjacent_position( Position pos, direction_t dir );

	public:
	    int sizeSnake;                               //<! tamanho da cobra
        std::deque<Position> listDirections;         //<! lista de direcoes que a snake deve seguir
        int currentDirection;                        //<! direcao atual
        std::deque<Position> snakeBody;              //<! posicoes do corpo da cobra 

};

#endif