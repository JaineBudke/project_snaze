#include "manager.h"
#include "game.h"

Game gm;



/** @brief Analisa o tabuleiro e verifica se tem algum erro.
     @return Se labirinto está correto ou aponta o erro identificado. */
Manager::SnakeError Manager::parsing(  ){

    std::vector<std::vector<std::string>> boards_ = gm.getBoards(); // pega os tabuleiros do jogo


    //////////// QUE CODIGO HORRIVEEEEEEEL, AJEITA ISSO PLMDDSSSSSS


    // VERIFICAR SE TABULEIROS POSSUEM POSICAO INICIAL
    for( int i = 0 ; i < boards_.size() ;  i++ ){ // percorre cada um dos tabuleiros

        int inicial = 0;

        for( int j = 0 ; j < boards_[i].size() ; j++ ){ // percorre as linhas de um tabuleiro especifico

            for( int k = 0 ; k < boards_[i][j].size() ; k++ ){ // percorre as colunas de um tabuleiro especifico

                char carac = boards_[i][j][k];

                /* ISSO TÁ DANDO ERRADO
                if( !(gm.isWall( carac )) and !(gm.isInvisibleWall( carac )) and !(gm.isFree( carac )) and !(gm.isInitialPosition( carac )) ){
                    std::cout << "TESTE: '" << carac << "'\n";
                    return EXTRANEOUS_SYMBOL;
                } */

                if( gm.isInitialPosition( carac ) ){
                    inicial += 1;
                }

        } }
        if( inicial != 1 ){ // se tiver mais de 1 posicao ou nenhuma
            return MISSING_START;
        }
    }

    return BOARD_OK;

}


/** @brief Inicializa lendo o arquivo de entrada fornecido pelo jogador.
     @param arq Nome do arquivo de entrada.
     @return Se arquivo foi lido corretamente ou aponta o erro identificado. */
Manager::SnakeError Manager::initialize( char * arq ){

    // cria input file stream (ifstream)
    std::ifstream arquivo;
    // abre arquivo passado por linha de comando
    arquivo.open( arq, std::ios::in );
    // verifica se houve algum erro ao abrir arquivo
    if (!arquivo.is_open()){
        return SnakeError::ARCHIVE_NOT_FIND;
    }


    std::vector<std::vector<std::string>> tabuleiro;
    std::vector<Game::Position> tamTabuleiros;
    int levels_ = 0;


    Game::Position tamanho;
    std::string linhaBoard;
    std::string dummy;

    // enquanto tiver coisa no arquivo
    do {

        std::vector<std::string> linhasTabuleiro;

        arquivo >> tamanho.y; // le quantidade de linhas
        arquivo >> tamanho.x; // le quantidade de colunas

        tamTabuleiros.push_back( tamanho );

        getline( arquivo, dummy ); // eliminando linha
        for( int j=0 ; j<tamanho.y ; j++ ){

            getline( arquivo, linhaBoard );
            linhasTabuleiro.push_back(linhaBoard);

        }

        tabuleiro.push_back( linhasTabuleiro ); // set tabuleiros

        levels_ += 1;
        getline( arquivo, dummy ); // eliminando linha

    } while( arquivo.good() );

    gm.setLevels( levels_ );           // set levels
    gm.setSizeBoards( tamTabuleiros ); // set tamanho dos tabuleiros
    gm.setBoards( tabuleiro );         // set tabuleiros

    gm.levelUp(); // inicia o jogo com o level1

    auto result = parsing();

    return result;

}


//** @brief Exibe as informações iniciais e condição geral do jogo.
void Manager::welcome(){

    int n_levels = gm.getLevels();
    int n_lives  = gm.getLives();

    std::cout << ">>> Bem-vindo ao Snake!\n";
    std::cout << ">>> Esta é uma simulação com os dados de entrada fornecidos.\n";
    std::cout << ">>> O jogo possui " << n_levels << " fases e você tem " << n_lives << " vidas! Boa sorte!\n";
    std::cout << ">>> Pressione alguma tecla quando estiver pronto para começar.";
    std::string dummy;
    std::getline( std::cin, dummy );

}

/** @brief Verifica se o jogo ainda deve ou não continuar sendo executado.
    @return True se o jogo acabou; 0 jogo continua. */
bool Manager::gameOver(){

    int currentLevel_ = gm.getCurrentLevel();
    int levels_       = gm.getLevels();
    int life          = gm.getLives();

    // - se jogador passou de todos os niveis
    if( currentLevel_ > levels_ ){
        gm.setState( 1 ); // venceu
        return true;
    }
    // - se numero de vidas for igual a 0
    else if ( life == 0 ){
        gm.setState( 0 ); // perdeu
        return true;
    }
    // - Otherwise: jogo continua
    else {
        return false;
    }

}

//** @brief Faz a chamada da próxima rodada do jogo.
void Manager::process_events(){

    std::vector<std::string> currentBoard_ = gm.getCurrentBoard();
    Game::Position initial = gm.initialPosition();


    std::cout << "    =========== LEVEL "<< gm.getCurrentLevel() <<" ===========\n";
    std::cout << ">>> Voce possui " << gm.getLives() << " vidas e o tabuleiro desta fase está abaixo. Boa sorte!\n";

    for( int i=0; i < currentBoard_.size() ; i++ ){
    	std::cout << currentBoard_[i] << "\n";
    }
    std::cout << "\n";

}

//** @brief Atualiza o estado do jogo.
void Manager::update(){

    // TODO
    gm.levelUp();


}

//** @brief Exibe os resultados da rodada para o jogador.
void Manager::render(){

    // TODO
    // - Apresenta o tabuleiro com a posicao do snake e da maçã

}

//** @brief Exibe os resultados finais do jogo para o jogador.
void Manager::render_log(){

    std::cout << ">>> O jogo terminou!\n";
    // - recupera state do jogador
    bool result = gm.getState();

    // - se jogador venceu dá os parabens
    if( result == true ){
        std::cout << ">>> Parabéns! Você completou todos os níveis do jogo!\n";
    }
    // - se jogador perdeu propõe jogar novamente
    if( result == false ){
        std::cout << ">>> Que pena... Parece que suas vidas terminaram\n";
        std::cout << ">>> Que tal começar um novo jogo? Talvez você tenha mais sorte da próxima vez\n";
        std::cout << ">>> Boa sorte! ;)\n";
    }

}