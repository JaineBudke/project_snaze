/**
 * @file    manager.h
 * @brief   Arquivo cabeçalho com o gerenciamento central do Snake.
 * @author  Daniel Barbosa (nome@email.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */

#ifndef _MANAGER_H_
#define _MANAGER_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include "master.h"


/**
 *  Essa eh a classe Manager
 *  Aqui sao definidas as funcoes para gerenciamento central do Snake.
 */
class Manager {

    public:

        enum SnakeError {
			BOARD_OK = 0,        // Arquivo lido corretamente
			MISSING_START,		 // Não há posição inicial
			EXTRANEOUS_SYMBOL,	 // Encontrado símbolo diferente de '#', ' ', '*', '.'
			ARCHIVE_NOT_FIND     // Arquivo nao encontrado
        };


	    /** @brief Analisa os tabuleiros e verifica se tem algum erro.
	        @return Se labirinto está correto ou aponta o erro identificado. */
	    SnakeError parsing(  );

	    /** @brief Inicializa lendo o arquivo de entrada fornecido pelo jogador.
	        @param arq Nome do arquivo de entrada.
	        @return Se arquivo foi lido corretamente ou aponta o erro identificado. */
	    SnakeError initialize( char * arq );


	    //** @brief Exibe as informações iniciais e condição geral do jogo.
	    void welcome();


	    /** @brief Verifica se o jogo ainda deve ou não continuar sendo executado.
	        @return True se o jogo acabou; 0 jogo continua. */
	    bool gameOver();


	    //** @brief Faz a chamada da próxima rodada do jogo.
	    void process_events();


	    //** @brief Atualiza o estado do jogo.
	    void update();

	    //** @brief Exibe os resultados da rodada para o jogador.
	    void render();


	    //** @brief Exibe os resultados finais do jogo para o jogador.
	    void render_log();

};

#endif