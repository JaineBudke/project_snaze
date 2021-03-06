/**
 * @file    game.h
 * @brief   Arquivo com a implementacao de funcoes
                que controlam o jogo.
 * @author  Edivania Pontes (edivaniap@ufrn.edu.br)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    21/06/2017
 */


#include "game.h"
#include "snake.h"

Level lv; // instanciando classe level
Snake sk; // instanciando classe snake

// ======================================================
// ACTIONS
// ======================================================

/** @brief Identifica a posicao inicial da Snake no tabuleiro.
    @return Posicao inicial da Snake */
Position Game::initialPosition(){

    // Percorre board tentando encontrar inicio
    for( int i = 0 ; i < lv.currentBoard.size() ; i++ ){        // Percorre cada pos do vector
        for( int j=0 ; j < lv.currentBoard[i].length() ; j++ ){ // Percorre cada pos da string
            if( lv.currentBoard[i][j] == '*' ){
                Position inicial;
                inicial.x = j; // coluna
            	inicial.y = i; // linha
                lv.initial = inicial;
            	   return inicial;
            }
        }
    }

}


/** @brief Lança uma maçã no jogo, dentro das coordenadas do tabuleiro da fase.
    @return Posicao em que a maçã foi lançada */
Position Game::throwApple(){

    bool invalido = true;

    std::srand(std::time(0)); // semente do rand
    Position tamanho = sizesBoards[lv.currentLevel-1]; // pega tamanho do level atual

    // sorteia a maçã até cair num espaço livre
    do{

        int menor = 1;
        int maiorLinha  = tamanho.y -1;
        int maiorColuna = tamanho.x -1;

        Position pos;

        pos.y = rand()%(maiorLinha-menor+1) + menor;  // sorteia um numero aleatorio para a linha
        pos.x = rand()%(maiorColuna-menor+1) + menor; // sorteia um numero aleatorio para a coluna

        if( isFree(lv.currentBoard[pos.y][pos.x]) ){
            invalido = false;
            lv.currentBoard[pos.y][pos.x] = 'a';
            maca = pos;
        }

    } while( invalido );

}

void Game::paint_snake_on_board()
{
    lv.currentBoard[sk.snakeBody[0].y][sk.snakeBody[0].x] = '@'; //desenha a cabeça
    for(auto i = 1u; i < sk.snakeBody.size(); i++)
        lv.currentBoard[sk.snakeBody[i].y][sk.snakeBody[i].x] = '0';
}

void Game::clear_snake_of_board()
{
    for(auto i = 0u; i < sk.snakeBody.size(); i++)
        lv.currentBoard[sk.snakeBody[i].y][sk.snakeBody[i].x] = ' ';
}


/** @brief Move a cobra de acordo com as coordenadas passadas.
     @return 1 se cobra chegou na maca, bateu na parede ou rabo. 0 otherwise. */
bool Game::moveSnake(){
    //std::cin.ignore(); //esperar enter

    /* apaga desenho das antigas posicoes da cobra */
    clear_snake_of_board();

    Position dir = sk.listDirections[sk.currentDirection];
    sk.snakeBody.push_front( dir );
    sk.snakeBody.pop_back();

    /* pintar toda a cobra no tab */
    paint_snake_on_board();

    // se chegou na maçã
    if( eatingApple() ){
        currentState = EXPAND;
        lv.eatenApples += 1;
        return true; // muda stop pra true
    }

    if( sk.listDirections.size() == sk.currentDirection ){
        return true;
    }

    sk.currentDirection += 1;

    return false; // muda stop pra false - continua rodando
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


/** @brief Verifica se a snake chegou na maca.
     @return 1 se chegou, 0 otherwise */
bool Game::eatingApple( ){

    Position pos = sk.snakeBody.front();

    if( pos == maca ){
        return true;
    } else {
        return false;
    }

}


// ======================================================
// ESTADOS
// ======================================================

/** @brief Aumenta o tamanho da cobra. */
void Game::expandSnake(){

    Position pos = initialPosition();

    throwApple();


    // SE tamanho da snake for 1 ela é transformada na cobra
    if( sk.sizeSnake == 0 ){
        lv.currentBoard[pos.y][pos.x] = '@';
        sk.snakeBody.push_front( pos );

        sk.sizeSnake += 1; // snake cresce
    }

    // SE tamanho da snake for maior a 1 ela cresce
    if( sk.sizeSnake >= 1 ){
        sk.listDirections.clear();
        sk.currentDirection = 0;
        lv.initial = sk.snakeBody.front();

        /*AQUI NA VERDADE TENHO QUE GERAR UMA NOVA PÓS VALIDA !!!!!!!!1 PRA HEAD*/
        sk.snakeBody.push_front( sk.snakeBody.front() ); // add nova posição para uma nova parte do corpo

        sk.sizeSnake += 1; // snake cresce
    }

    // SE qntidade de maçãs comidas for o total -> STATE = LEVEL_UP
    if( lv.eatenApples == lv.totalApples ){
        currentState = LEVEL_UP;
    }

    // SE qntidade de maçãs comidas for menor que o total -> STATE = RUN e lança maçã
    if( lv.eatenApples < lv.totalApples ){
        currentState = RUN;
    }

}


/** @brief Faz a chamada da próxima fase do jogo setando os valores da classe Level. */
void Game::levelUp(){

    lv.currentLevel += 1; // em level é acrescentado um nível

    if( lv.currentLevel <= levels ){
        lv.currentBoard = boards[lv.currentLevel-1]; // recupera o tabuleiro do level
    }

    // zera tudo das classes level e snake
    lv.eatenApples = 0;
    sk.snakeBody.clear();
    sk.sizeSnake = 0;

    currentState = EXPAND;

}


/** @brief Verifica se a cobra teve alguma colisão. */
bool Game::crashSnake(){

    std::cout << "Oh no! You're crash!\n";
    currentState = DEAD;

}


/** @brief Simula a morte da cobra (diminui uma vida). */
void Game::deadSnake(){

    lives -= 1;

    std::cout << ">>> Pressione <ENTER> quando estiver pronto para continuar.";
    std::string dummy;
    std::getline( std::cin, dummy );

    currentState = RUN;

}

/** @brief A cobra anda a quantidade de vezes até chegar na maçã. */
void Game::runSnake(){

    bool solve = sk.solveMaze( lv.currentBoard, lv.initial, sizesBoards[ lv.currentLevel - 1 ], maca );

    bool stop = moveSnake();

    // se não há solução, execução para e vai pro estado CRASH
    if( solve == false ){
    	currentState = CRASH;
    	return;
    }

    // verifica se a condicao de parada foi acionada
    if( stop == false ){
        currentState = RUN;
    }


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
std::vector<Position> Game::getSizeBoards( void ) const{
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

/** @brief Recupera as macas comidas do jogo.
     @return A quandiade de macas. */
int Game::getEatenApples( void ) {
    return lv.eatenApples;
}