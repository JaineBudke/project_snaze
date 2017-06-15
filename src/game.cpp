/**
 * @file    game.h
 * @brief   Arquivo cabeçalho com a implementacao de funcoes 
            que controlam o jogo.
 * @author  Daniel Barbosa (nome@email.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */


#include "game.h"


Level lv; // instanciando classe level


// ======================================================
// ACTIONS
// ======================================================

/** @brief Identifica a posicao inicial da Snake no tabuleiro.
    @return Posicao inicial da Snake */
Game::Position Game::initialPosition(){

    // Percorre board tentando encontrar inicio
    for( int i = 0 ; i < lv.currentBoard.size() ; i++ ){        // Percorre cada pos do vector
        for( int j=0 ; j < lv.currentBoard[i].length() ; j++ ){ // Percorre cada pos da string
            if( lv.currentBoard[i][j] == '*' ){
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

    bool invalido = true;

    std::srand(std::time(0)); // semente do rand
    Position tamanho = sizesBoards[lv.currentLevel-1]; // pega tamanho do level atual

    // sorteia a maçã até cair num espaço livre
    do{

        int menor = 1;
        int maiorLinha  = tamanho.y -1;
        int maiorColuna = tamanho.x -1;

        int aL = rand()%(maiorLinha-menor+1) + menor;  // sorteia um numero aleatorio para a linha
        int aC = rand()%(maiorColuna-menor+1) + menor; // sorteia um numero aleatorio para a coluna

        if( isFree(lv.currentBoard[aL][aC]) ){
            invalido = false;
            lv.currentBoard[aL][aC] = 'o';
        }

    } while( invalido );

}


/** @brief Move a cobra de acordo com as coordenadas passadas.
    @return Direcao que deve se mover */
Game::Direction Game::moveSnake(){

	// TODO

}

// ======================================================
// AUXILIO
// ======================================================

/** @brief Verifica se o caractere passado é uma parede.
    @return 1 se for, 0 se não for */
bool Game::isWall( char ch ){
    return ( ch == '#' );
}

/** @brief Verifica se o caractere passado é uma parede invisivel.
    @return 1 se for, 0 se não for */
bool Game::isInvisibleWall( char ch ){
    return ( ch == '.' );
}


/** @brief Verifica se o caractere passado é um lugar livre.
    @return 1 se for, 0 se não for */
bool Game::isFree( char ch ){
    return ( ch == ' ' );
}

/** @brief Verifica se o caractere passado é a posicao inicial.
    @return 1 se for, 0 se não for */
bool Game::isInitialPosition( char ch ){
    return ( ch == '*' );
}


// ======================================================
// ESTADOS
// ======================================================

/** @brief Aumenta o tamanho da cobra. */
void Game::expandSnake(){

    // SE tamanho da snake for 1 ela é transformada na cobra
    // SE tamanho da snake for maior que 1 ela cresce

    // SE qntidade de maçãs comidas for o total -> STATE = LEVEL_UP
    // SE qntidade de maçãs comidas for menor que o total -> STATE = RUN e lança maçã

}


/** @brief Faz a chamada da próxima fase do jogo setando os valores da classe Level. */
void Game::levelUp(){

    lv.currentLevel += 1; // em level é acrescentado um nível

    if( lv.currentLevel <= levels ){
        lv.currentBoard = boards[lv.currentLevel-1]; // recupera o tabuleiro do level
    }

    currentState = RUN;

}


/** @brief Verifica se a cobra teve alguma colisão. */
bool Game::crashSnake(){

	// TODO
    // mensagem de "Oh no! You're crash"
    // Muda estado pra DEAD

}


/** @brief Simula a morte da cobra (diminui uma vida). */
void Game::deadSnake(){

	// TODO
    // diminui uma vida da snake
    // pede pra pressionar ENTER pra continuar
    // Muda estado pra RUN

}

/** @brief A cobra anda a quantidade de vezes até chegar na maçã. */
void Game::runSnake(){

    // TODO
    // loop que roda até a snake comer a maçã ou bater numa parede ou rabo
    // * chama o metodo moveSnake
    // * SE bater na parede muda estado para CRASH
    // * SE comer a maçã muda estado para EXPAND

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

// ======================================================
// GETTERS AND SETTERS DA CLASSE LEVEL
// ======================================================


/** @brief Define a fase atual que o jogador se encontra.
    @param level_ A fase
    @return True se tiver um numero de fases maior que zero; False otherwise. */
bool Game::setCurrentLevel( int level_ ){
    if( level_ > 0 ){
        lv.currentLevel = level_;
        return true;
    } else {
        return false;
    }
}


/** @brief Recupera a fase atual do jogo.
    @return A fase. */
int Game::getCurrentLevel( void ) const{
    return lv.currentLevel;
}

/** @brief Recupera o tabuleiro atual do jogo.
    @return O tabuleiro. */
std::vector<std::string> Game::getCurrentBoard( void ) const{
    return lv.currentBoard;
}

/** @brief Define o tabuleiro atual do jogo.
    @param level_ O tabuleiro
    @return True se tiver um tabuleiro; False otherwise. */
bool setCurrentBoard( std::vector<std::string> tabuleiro ){
    lv.currentBoard = tabuleiro;
}
