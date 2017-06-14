/**
 * @file    game.h
 * @brief   Arquivo cabeçalho com a funções de execução do jogo.
 * @author  Daniel Barbosa (nome@email.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */

#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <vector>
#include <string>

/**
 *  Essa eh a classe Game
 *  Aqui sao definidas as funcoes responsáveis pela execução do jogo (game loop)
 */
class Game {

    public:

        //** @brief Criando um Game vazio (inicializacao).
        Game() : lives(5), currentLevel(0) { /* empty */ }


        /**
         *  Esse eh o struct Position
         *  Esta estrutura é capaz de indicar a posicao (x,y) de um elemento.
         */
        typedef struct {
        	int x; //<! Indica a coordenada X (coluna)
        	int y; //<! Indica a coordenada Y (linha )
        } Position;


        /**
         *  Esse eh o struct Direction
         *  Esta estrutura é capaz de indicar uma direcao (x,y) para um elemento seguir.
         */
        typedef struct {
        	int x; //<! Indica a coordenada X (coluna)
        	int y; //<! Indica a coordenada Y (linha )

        	// TODO: sobrecarga de operador
        } Direction; // Representa o vetor a ser somado com uma posição



        // ======================================================
        // ACTIONS
        // ======================================================

        /** @brief Lança uma maçã no jogo, dentro das coordenadas do tabuleiro da fase.
             @return Posicao em que a maçã foi lançada */
        Position throwApple();


        /** @brief Move a cobra de acordo com as coordenadas passadas buscadas na classe Snake.
             @return Direcao que deve se mover */
        Direction moveSnake();


        /** @brief Identifica a posicao inicial da Snake no tabuleiro.
             @return Posicao inicial da Snake */
        Position initialPosition();


        // ======================================================
        // AUXILIO
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

        /** @brief Define a fase atual que o jogador se encontra.
             @param level_ A fase
             @return True se tiver um numero de fases maior que zero; False otherwise. */
        bool setCurrentLevel( int level_ );


        /** @brief Recupera a fase atual do jogo.
             @return A fase. */
        int getCurrentLevel( void ) const;


        /** @brief Define um vetor com os tabuleiros do jogo.
             @param boards_ Os tabuleiros
             @return True se tiver um numero de tabuleiros maior que zero; False otherwise. */
        bool setBoards( std::vector<std::vector<std::string>> boards_ );


        /** @brief Recupera os tabuleiros do jogo.
             @return Os tabuleiros. */
        std::vector<std::vector<std::string>> getBoards( void ) const;


        /** @brief Recupera o tabuleiro atual do jogo.
             @return O tabuleiro. */
        std::vector<std::string> getCurrentBoard( void ) const;


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

    private:
        int levels; 					         //<! quantidade de fases do jogo
        std::vector<std::vector<std::string>> boards;    //<! tabuleiros a serem processados
        int lives;   			                                  //<! vidas da cobra
        int state;					        //<! 0 se jogador perdeu or 1 se venceu
        std::vector<Position> sizesBoards; 	        //<! tamanhos dos tabuleiros




        // ESSES DADOS TEM Q IR PRA CLASSE LEVEL DEPOIS...
        int currentLevel; 					  //<! fase atual do jogador
        std::vector<std::string> currentBoard; 		  //<! tabuleiro atualmente sendo processado


};

#endif