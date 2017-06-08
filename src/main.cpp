#include <iostream>
#include "manager.h"


int main( int argc, char * argv[] ){

	Manager mg;
	auto result = mg.initialize( argv[1] );
	
	if(result.type != Manager::SnakeError::BOARD_OK ){ // Se o resultado não for 'ok'
		std::cerr << "Encontramos um erro na leitura dos tabuleiros: \n";
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