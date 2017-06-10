#include "manager.h"
#include "game.h"

Game gm;

/** @brief Inicializa lendo o arquivo de entrada fornecido pelo jogador.
    @param arq Nome do arquivo de entrada.
    @return Se arquivo foi lido corretamente ou aponta o erro identificado. */
Manager::SnakeError::error Manager::initialize( char * arq ){

    // cria input file stream (ifstream)
    std::ifstream arquivo;
    // abre arquivo passado por linha de comando
    arquivo.open( arq, std::ios::in );
    // verifica se houve algum erro ao abrir arquivo
    if (!arquivo.is_open()){
        return Manager::SnakeError::error::ARCHIVE_NOT_FIND;
    }
    // le qntidade de fases do jogo
    int levels_;
    arquivo >> levels_;

    std::vector<std::vector<std::string>> tabuleiro;
    std::vector<Game::Position> tamTabuleiros;

    Game::Position tamanho;
    std::string linhaBoard;

    // enquanto tiver coisa no arquivo
    for( int i=0; i<levels_; i++ ){

        std::vector<std::string> linhasTabuleiro;

        arquivo >> tamanho.y; // le quantidade de linhas
        arquivo >> tamanho.x; // le quantidade de colunas

        tamTabuleiros.push_back( tamanho );

        for( int j=0; j<=tamanho.y; j++ ){

            getline( arquivo, linhaBoard );
            linhasTabuleiro.push_back(linhaBoard);
        }

        tabuleiro.push_back( linhasTabuleiro ); // set tabuleiros

    }
   
    gm.setLevels( levels_ );           // set levels
    gm.setSizeBoards( tamTabuleiros ); // set tamanho dos tabuleiros
    gm.setBoards( tabuleiro );         // set tabuleiros

}


//** @brief Exibe as informações iniciais e condição geral do jogo.
void Manager::welcome(){

    int n_levels = gm.getLevels();

    std::cout << ">>> Bem-vindo ao Snake!\n";
    std::cout << ">>> Esta é uma simulação com os dados de entrada fornecidos.\n";
    std::cout << ">>> O jogo possui " << n_levels << " fases e você tem 10 vidas! Boa sorte!\n";
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
        return false;
    } 
    // - se numero de vidas for igual a 0
    else if ( life == 0 ){
        gm.setState( 0 ); // perdeu
        return false;
    }
    // - Otherwise: jogo continua
    else {
        return true;
    }

}

//** @brief Faz a chamada da próxima rodada do jogo.
void Manager::process_events(){

    // TODO
    // - se passou pro proximo nivel apresenta novas informacoes

}

//** @brief Atualiza o estado do jogo.
void Manager::update(){

    // TODO

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