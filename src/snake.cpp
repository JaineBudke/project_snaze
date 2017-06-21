/**
 * @file    snake.cpp
 * @brief   Arquivo com as funcoes que implementam
             a resolucao do labirinto.
 * @author  Edivania Pontes (edivaniap@ufrn.edu.br)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    21/06/2017
 */

#include "snake.h"

Position Snake::adjacent_position( Position pos, direction_t dir )
{
    switch( dir )
    {
        case NORTH:
            pos.set( NORTH );
            break;

        case SOUTH:
            pos.set( SOUTH );
            break;

        case WEST:
            pos.set( WEST );
            break;

        case EAST:
            pos.set( EAST );
            break;
    }

    return pos;
}

bool Snake::is_valid_position( Position pos, Position size )
{
    return (pos.x >= 0 and pos.x < size.x and pos.y >= 0 and pos.y < size.y );
}

/* not working */
bool Snake::is_snakeBody(const Position & pos) const
{
    std::cout << "TO TENTANDO SABER SE " << pos.y <<" "<< pos.x << " é body? " << "\n";
    std::cout << "TAM SNAKE = " << snakeBody.size() << "\n";
    std::cin.ignore(); //esperar enter
    int i(snakeBody.size()-1); //nao precisa comparar o rabo
    while( i >= 0 )
    {
        if( snakeBody[i] == pos )
            return true;
        i--;
    }
    return false;
}

/** @brief Tenta encontrar caminho para chegar na maçã.
    @return 1 se for possível, 0 se for impossível. */
bool Snake::solveMaze( std::vector<std::string> currentBoard, Position initialPosition, Position sizeBoard, Position apple ){

    // TODO
    // FAZER ESSA PARTE ACHANDO REALMENTE DIRECAO VALIDA PARA A SNAKE

    Game gm; // instancia apenas para acessar funcoes de auxilio

    int freeSpaces = 0; // espacos livres no tabuleiro
    std::stack< Position > marked; // pilha
    Position currentPosition; // variavel que controla a posicao atual do backtracking

    // criando um mapa de posicoes -- (1) ocupado ; (0) livre
    int map[sizeBoard.y][sizeBoard.x];
    for( int i=0 ; i < sizeBoard.y ; i++ ){
        for( int j=0 ; j < sizeBoard.x; j++ ){
            if( gm.isWall( currentBoard[i][j] ) ){ // se a posicao atual eh uma parede, tá ocupado
                map[i][j] = 1;
            } else if( gm.isInvisibleWall( currentBoard[i][j] ) ){  // se a posicao atual eh uma parede invisivel, tá ocupado
                map[i][j] = 1;
            } else { // se tiver livre
                map[i][j] = 0; // inicializa tudo com 0
                freeSpaces+=1; // encontra o numero de espacos livres
            }

        }
    }

    // sentando posicoes iguais a do corpo do snake como ocupadas
/*    for (auto i = 0u; i < snakeBody.size(); ++i)
        map[snakeBody[i].y][snakeBody[i].x] = 1;*/


    // =========== BACKTRACKING ============ //

    // 1. Tornar initialPosition a celula atual e marcar como visitada
    currentPosition = initialPosition;
    map[initialPosition.y][initialPosition.x] = 1; // torna espaco ocupado
    freeSpaces -= 1; // diminui um espaco livre

    // 2. Buscar celulas ainda não visitadas
    while( freeSpaces > 0 ){ // vai rodar enquanto tiver espaco vazios no mapa

        /* DIMINUINDO LINHAS DE CODIGOS */
        /* SE MUDAR A ORDEM DOS VIZINHOS DÁ FALHA DE SEG. (WHY)*/
        std::vector<Position> neighbourhood; //<! visinhos
        neighbourhood.push_back(adjacent_position(currentPosition, NORTH));//[0]
        neighbourhood.push_back(adjacent_position(currentPosition, SOUTH));//[1]
        neighbourhood.push_back(adjacent_position(currentPosition, EAST)); //[3]
        neighbourhood.push_back(adjacent_position(currentPosition, WEST)); //[2]


        // se a posicao for invalida:
        // muda posicao pra inicial, que sabe q tá ocupada (foi ocupada no passo 1)
        // isso evita ele tentar acessar em algum momento um valor que nao existe - falha de segmentacao
        for (auto i = 0u; i < neighbourhood.size(); i++)
            if( not is_valid_position( neighbourhood[i], sizeBoard ) ) // se a posicao do visinho for invalida
                neighbourhood[i] = initialPosition;

        // verifica se a posicao atual eh a maca
        if( currentPosition == apple ){

            // dá o push da maca pra pilha
            marked.push( currentPosition );

            while( !(marked.empty()) ){

                // ve quem é o prox
                Position dir = marked.top();

                // add na lista
                listDirections.push_front( dir );
                // tira ele
                marked.pop();
            }

            return true;

        }
        // 3. Verifica se os vizinhos estão livres (e se sao validos) ou tem maçã
        else if( map[neighbourhood[0].y][neighbourhood[0].x] == 0
            or map[neighbourhood[1].y][neighbourhood[1].x]   == 0
            or map[neighbourhood[2].y][neighbourhood[2].x]   == 0
            or map[neighbourhood[3].y][neighbourhood[3].x]   == 0 ){ // vizinhos livres (não sao parede nem foram visitados)

            // // 4. escolhe um dos vizinhos (em um deles vai entrar obrigatoriamente)
            Position vizinho;
            for (auto i = 0u; i < neighbourhood.size(); i++)
            {
               // std::cout << neighbourhood[i].y <<" "<< neighbourhood[i].x << " é body? " << is_snakeBody(neighbourhood[i]) << "\n";
                /* se posicao vizinha está livre e nao é corpo da cobra... */
                if( map[neighbourhood[i].y][neighbourhood[i].x] == 0 ){
                    vizinho = neighbourhood[i];   // determina quem eh o vizinho
                    freeSpaces -= 1; // diminui um espaco livre
                    map[neighbourhood[i].y][neighbourhood[i].x] = 1; // marca no map que a posicao tá ocupada
                    break;
                }
            }

             // dá o push da posicao atual pra pilha
             marked.push( currentPosition );

             // posicao atual agora é o vizinho escolhido
             currentPosition = vizinho;

        } else if( !(marked.empty()) ){ // 5. Se nenhum vizinho estiver livre, mas a pilha ainda não estiver vazia
            // tira o ultimo elemento da pilha
            marked.pop();

            // vê e salva quem é o proximo
            Position newPosition = marked.top();

            // torna nova célula a atual
            currentPosition = newPosition;
        }

    }

    return false;
}
