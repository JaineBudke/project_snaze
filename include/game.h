/**
 * @file    game.h
 * @brief   Arquivo cabeçalho com a funções de execução do jogo.
 * @author  Edivania Pontes (edivaniap@ufrn.edu.br)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    21/06/2017
 */

#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "master.h"
#include "level.h"

/**
 *  Essa eh a classe Game
 *  Aqui sao definidas as funcoes responsáveis pela execução do jogo (game loop)
 */
class Game {

    public:

        //** @brief Criando um Game vazio (inicializacao).
        Game() : lives(5), currentState(EXPAND) { /* empty */ }


        /**
         *  Esse eh o enum States
         *  Esta estrutura é capaz de indicar uma direcao (x,y) para um elemento seguir.
         */
        enum States {
            RUN = 0,   // Snake deve andar até pegar maçã
            EXPAND,   // Snake anda uma vez e cresce o tamanho
            LEVEL_UP,  // Snake pegou todas as maçãs e avança um level
            CRASH,     // Snake bateu na parede ou no próprio rabo
            DEAD       // Snake perdeu todas as vidas
        };


        // ======================================================
        // ACTIONS
        // ======================================================

        /** @brief Lança uma maçã no jogo, dentro das coordenadas do tabuleiro da fase.
            @return Posicao em que a maçã foi lançada */
        Position throwApple();


        /** @brief Move a cobra uma posicao, de acordo com as coordenadas passadas buscadas na classe Snake.
             @return 1 se cobra chegou na maca, bateu na parede ou rabo. 0 otherwise. */
        bool moveSnake();


        /** @brief Identifica a posicao inicial da Snake no tabuleiro.
             @return Posicao inicial da Snake */
        Position initialPosition();



        // ======================================================
        // AUXILIARES
        // ======================================================

        /** @brief Verifica se o caractere passado é uma parede.
             @return 1 se for, 0 se não for */
        bool isWall( char ch );

        /** @brief Verifica se o caractere passado é uma parede invisivel.
             @return 1 se for, 0 se não for */
        bool isInvisibleWall( char ch );


        /** @brief Verifica se o caractere passado é um lugar livre.
             @return 1 se for, 0 se não for */
        bool isFree( char ch );

        /** @brief Verifica se o caractere passado é a posicao inicial.
             @return 1 se for, 0 se não for */
        bool isInitialPosition( char ch );


        /** @brief Verifica se a snake colidiu com o tail.
             @return 1 se colidiu, 0 otherwise */
        bool collideTail( );


        /** @brief Verifica se a snake colidiu com a parede.
             @return 1 se colidiu, 0 otherwise */
        bool collideWall( );

        /** @brief Verifica se a snake chegou na maca.
             @return 1 se chegou, 0 otherwise */
        bool eatingApple( );



        // ======================================================
        // ESTADOS
        // ======================================================

        /** @brief Aumenta o tamanho da cobra (informacoes da classe Snake). */
        void expandSnake();


        /** @brief Faz a chamada da próxima fase do jogo. */
        void levelUp();


        /** @brief Verifica se a cobra teve alguma colisão. */
        bool crashSnake();


        /** @brief Simula a morte da cobra (diminui uma vida). */
        void deadSnake();

        /** @brief A cobra anda a quantidade de vezes até chegar na maçã. */
        void runSnake();


        // ======================================================
        // SETTERS AND GETTERS
        // ======================================================

        /** @brief Define a quantidade de fases do jogo.
             @param levels_ As fases
             @return True se tiver um numero de fases maior que zero; False otherwise. */
        bool setLevels( int levels_ );


        /** @brief Recupera a quantidade de fases do jogo.
             @return As fases. */
        int getLevels( void ) const;


        /** @brief Define um vetor com os tabuleiros do jogo.
             @param boards_ Os tabuleiros
             @return True se tiver um numero de tabuleiros maior que zero; False otherwise. */
        bool setBoards( std::vector<std::vector<std::string>> boards_ );


        /** @brief Recupera os tabuleiros do jogo.
             @return Os tabuleiros. */
        std::vector<std::vector<std::string>> getBoards( void ) const;


        /** @brief Diminui uma vida do jogador.
 	@return True se tinha vidas pra diminuir; False otherwise. */
        bool setLives( );


        /** @brief Recupera a quantidade de vidas do jogador.
             @return As vidas. */
        int getLives( void ) const;


        /** @brief Atualiza status do jogador
             @param state_ O status */
        void setState( int state_ );


        /** @brief Recupera o status do jogador
             @return True se jogador ganhou; False se perdeu */
        bool getState( void ) const;


        /** @brief Atualiza os tamanhos dos tabuleiros do jogo
             @param sizesBoards_ Vetor com os tamanhos */
        void setSizeBoards( std::vector<Position> sizesBoards_ );


        /** @brief Recupera o vetor com os tamanhos */
        std::vector<Position> getSizeBoards( void ) const;


        // ======================================================
        // GETTERS AND SETTERS DA CLASSE LEVEL
        // ======================================================

        /** @brief Define a fase atual que o jogador se encontra.
            @param level_ A fase
            @return True se tiver um numero de fases maior que zero; False otherwise. */
        bool setCurrentLevel( int level_ );


        /** @brief Recupera a fase atual do jogo.
            @return A fase. */
        int getCurrentLevel( void ) const;

        /** @brief Define o tabuleiro atual do jogo.
            @param level_ O tabuleiro
            @return True se tiver um tabuleiro; False otherwise. */
        bool setCurrentBoard( std::vector<std::string> tabuleiro );

        /** @brief Recupera o tabuleiro atual do jogo.
            @return O tabuleiro. */
        std::vector<std::string> getCurrentBoard( void ) const;

        /** @brief Recupera as macas comidas do jogo.
             @return A quandiade de macas. */
        int getEatenApples( void );

        /** @brief seta as posições do tabuleiro 
                   com carctere que representa a snake */
        void paint_snake_on_board();

        /** @brief seta as posições do tabuleiro que está com 
                   corpo da cobra com carctere de caminho livre (espaço em branco) */
        void clear_snake_of_board();

    public:
        int currentState;                                //<! proximo estado do jogo

    private:
        int levels; 					                 //<! quantidade de fases do jogo
        std::vector<std::vector<std::string>> boards;    //<! tabuleiros a serem processados
        int lives;   			                         //<! vidas da cobra
        int state;					                     //<! 0 se jogador perdeu or 1 se venceu
        std::vector<Position> sizesBoards; 	             //<! tamanhos dos tabuleiros

        Position maca;                            //<! posicao da maca no jogo

};

#endif