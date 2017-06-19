#include <iostream>

#include "manager.h"


int main( int argc, char * argv[] ){

	Manager mg;
	auto result = mg.initialize( argv[1] );

	if(result != Manager::SnakeError::BOARD_OK ){ // Se o resultado não for 'ok'
		if( result == Manager::SnakeError::ARCHIVE_NOT_FIND){
			std::cout << "O arquivo com as informações do jogo não foi encontrado.\n";
		} else if( result == Manager::SnakeError::MISSING_START){
			std::cout << "Alguns labirintos não possuem uma posição inicial da Snake.\n";
		} else if( result == Manager::SnakeError::EXTRANEOUS_SYMBOL){
			std::cout << "Foram encontrados simbolos não identificados nos labirintos.\n";
			std::cout << "Na descrição do labirinto, você só pode utilizar os caracteres: '#', ' ', '*', '.'";
		} else {
			std::cout << "Houve um erro ao longo do processo.";
		}
		return 0;
	}


	// Initial message
    	mg.welcome();

	// The game loop
	while(not mg.gameOver()){
		mg.process_events();
		mg.update();
		mg.render();
	}

	mg.render_log();

	return 0;
}