/**
 * @file    game.h
 * @brief   Arquivo cabeçalho com a implementacao de funcoes que
            controlam o jogo.
 * @author  Daniel Barbosa (nome@email.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */


#include "game.h"


// ======================================================
// ACTIONS 
// ======================================================


/** @brief Identifica a posicao inicial da Snake no tabuleiro.
    @return Posicao inicial da Snake */
Game::Position Game::initialPosition(){

    // Percorre board tentando encontrar inicio
    for( int i = 0 ; i < currentBoard.size() ; i++ ){        // Percorre cada pos do vector
        for( int j=0 ; j < currentBoard[i].length() ; j++ ){ // Percorre cada pos da string
            if( currentBoard[i][j] == '*' ){
                Position inicial;
				inicial.x = j; // coluna
				inicial.y = i; // linha
				return inicial;
            } 
        }
	}

}

/** @brief Lança uma maçã no jogo, dentro das coordenadas do tabuleiro da fase.
    @return Posicao em que a maçã foi lançada */
Game::Position Game::throwApple(){

	// TODO

}

/** @brief Move a cobra de acordo com as coordenadas passadas.
    @return Direcao que deve se mover */
Game::Direction Game::moveSnake(){

	// TODO

}


// ======================================================
// ESTADOS 
// ======================================================

/** @brief Aumenta o tamanho da cobra. */
void Game::expandSnake(){

	// TODO

}


/** @brief Faz a chamada da próxima fase do jogo setando os valores da classe Level. */
void Game::levelUp(){

	currentLevel += 1; // em level é acrescentado um nível 
	currentBoard = boards[currentLevel-1]; // recupera o tabuleiro do level

}


/** @brief Verifica se a cobra teve alguma colisão. */
bool Game::crashSnake(){

	// TODO
	
}


/** @brief Simula a morte da cobra (diminui uma vida). */
void Game::deadSnake(){

	// TODO
	
}


// ======================================================
// SETTERS AND GETTERS 
// ======================================================

/** @brief Define a quantidade de fases do jogo.
    @param levels_ As fases
    @return True se tiver um numero de fases maior que zero; False otherwise. */
bool Game::setLevels( int levels_ ){
	if( levels_ > 0 ){
		levels = levels_;
		return true;
	} else {
		return false;
	}
}


/** @brief Recupera a quantidade de fases do jogo.
    @return As fases. */
int Game::getLevels( void ) const{
	return levels;
}

/** @brief Define a fase atual que o jogador se encontra.
    @param level_ A fase
    @return True se tiver um numero de fases maior que zero; False otherwise. */
bool Game::setCurrentLevel( int level_ ){
	if( level_ > 0 ){
		currentLevel = level_;
		return true;
	} else {
		return false;
	}
}


/** @brief Recupera a fase atual do jogo.
    @return A fase. */
int Game::getCurrentLevel( void ) const{
	return currentLevel;
}


/** @brief Define um vetor com os tabuleiros do jogo.
    @param boards_ Os tabuleiros
    @return True se tiver um numero de tabuleiros maior que zero; False otherwise. */
bool Game::setBoards( std::vector<std::vector<std::string>> boards_ ){
	int qntidade = boards_.size();
	if( qntidade > 0 ){
		boards = boards_;
		return true;
	} else {
		return false;
	}
}


/** @brief Recupera os tabuleiros do jogo.
    @return Os tabuleiros. */
std::vector<std::vector<std::string>> Game::getBoards( void ) const{
	return boards;
}


/** @brief Recupera o tabuleiro atual do jogo.
    @return O tabuleiro. */
std::vector<std::string> Game::getCurrentBoard( void ) const{
	return currentBoard;
}


/** @brief Diminui uma vida do jogador.
    @return True se tinha vidas pra diminuir; False otherwise. */
bool Game::setLives( ){
	if( lives > 0 ){
		lives--;
		return true;
	} else {
		return false;
	}
}


/** @brief Recupera a quantidade de vidas do jogador.
    @return As vidas. */
int Game::getLives( void ) const{
	return lives;
}

/** @brief Atualiza status do jogador
    @param state_ O status */
void Game::setState( int state_ ){
	state = state_;
}

/** @brief Recupera o status do jogador
    @return True se jogador ganhou; False se perdeu */
bool Game::getState( void ) const{
	if( state == 1 ){
		return true;
	}else if( state == 0 ){
		return false;
	}
}

/** @brief Atualiza os tamanhos dos tabuleiros do jogo
    @param sizesBoards_ Vetor com os tamanhos */
void Game::setSizeBoards( std::vector<Position> sizesBoards_ ){
	sizesBoards = sizesBoards_;
}


/** @brief Recupera o vetor com os tamanhos */
std::vector<Game::Position> Game::getSizeBoards( void ) const{
	return sizesBoards;
}

