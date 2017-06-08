/**
 * @file    level.h
 * @brief   Arquivo cabeçalho com as informacoes da fase atual do jogo.
 * @author  Daniel Barbosa (nome@email.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */

#ifndef _LEVEL_H_
#define _LEVEL_H_

/**
 *  Essa eh a classe Level
 *  Aqui sao definidas as funcoes e variaveis responsáveis pelas
 *  informacoes da fase atual do jogo.
 */
class Level {

	private:
    	std::vector<std::string> currentBoard; //<! tabuleiro atualmente sendo processado
    	int currentLevel; 					   //<! level atual do processo
        Position startPosition; 			   //<! posicao inicial da cobra na fase atual

};

#endif