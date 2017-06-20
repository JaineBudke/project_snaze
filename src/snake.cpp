/**
 * @file    snake.cpp
 * @brief   Arquivo com as funcoes que implementam
            a resolucao do labirinto.
 * @author  Daniel Barbosa (nome@email.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */

#include "snake.h"

Position adjacent_position( Position pos, direction_t dir )
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

/** @brief determina se uma posição é válida e relação a um tabuleiro
    @param pos posição a ser analisada
    @param size dimensoes do tabuleiro 
    @return true se a posição for válida, false caso contrário */
bool is_valid_position( Position pos, Position size )
{
    return (pos.x >= 0 and pos.x < size.x and pos.y >= 0 and pos.y < size.y );
}


/** @brief Tenta encontrar caminho para chegar na maçã.
    @return 1 se for possível, 0 se for impossível. */
bool Snake::solveMaze( std::vector<std::string> currentBoard, Position initialPosition, Position sizeBoard, Position apple ){

    std::cout << "TESTE1\n";



    // ========= COMO USAR O ADJACENT_POSITION ===========
    // Position p(2,2);
    // p = adjacent_position(p, Direction::NORTH);

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


    // =========== BACKTRACKING ============ //


    // 1. Tornar initialPosition a celula atual e marcar como visitada
    currentPosition = initialPosition;
    map[initialPosition.y][initialPosition.x] = 1; // torna espaco ocupado
    freeSpaces -= 1; // diminui um espaco livre

    // 2. Buscar celulas ainda não visitadas
    while( freeSpaces > 0 ){ // vai rodar enquanto tiver espaco vazios no mapa

        Position neigh_north, neigh_south, neigh_east, neigh_west; //<! posicoes dos vizinhos

        // define posicoes dos vizinhos
        neigh_north = adjacent_position(currentPosition, NORTH);
        neigh_south = adjacent_position(currentPosition, SOUTH);
        neigh_east  = adjacent_position(currentPosition, EAST);
        neigh_west  = adjacent_position(currentPosition, WEST);

        // se a posicao for invalida:
        // muda posicao pra inicial, que sabe q tá ocupada (foi ocupada no passo 1)
        // isso evita ele tentar acessar em algum momento um valor que nao existe - falha de segmentacao
        if( not is_valid_position( neigh_north, sizeBoard ) ){ // se a posicao for invalida
            neigh_north = initialPosition;
        }
        if( not is_valid_position( neigh_south, sizeBoard ) ){ // se a posicao for invalida
            neigh_south = initialPosition;
        }
        if( not is_valid_position( neigh_east, sizeBoard ) ){ // se a posicao for invalida
            neigh_east = initialPosition;
        }
        if( not is_valid_position( neigh_west, sizeBoard ) ){ // se a posicao for invalida
            neigh_west = initialPosition;
        }

        // verifica se a posicao atual eh a maca
        if( currentPosition.x == apple.x and currentPosition.y == apple.y ){

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
        else if( map[neigh_north.y][neigh_north.x] == 0
            or map[neigh_south.y][neigh_south.x]   == 0
            or map[neigh_east.y][neigh_east.x]     == 0
            or map[neigh_west.y][neigh_west.x]     == 0 ){ // vizinhos livres (não sao parede nem foram visitados)

            
            //=== AS VEZES ACHA MENOR CAMINHO 

            //tentando achar caminho menor:
            //ex: se a cobra esta disposta abaixo e ao lado esquerdo da maça ela tem que tentar primeir ir pro norte e leste
            // std::deque<Position> best_neigh;
            // //best_position_togo(best_neigh, currentPosition, apple); //seta a pilha best_neigh
            // if( currentPosition.y <= apple.y )
            // {
            //     best_neigh.push_front( neigh_east );
            //     best_neigh.push_back( neigh_west );
            // }
            // else
            // {
            //     best_neigh.push_front( neigh_west );
            //     best_neigh.push_back( neigh_east );
            // }

            // if( currentPosition.x <= apple.x )
            // {
            //     best_neigh.push_front( neigh_south );
            //     best_neigh.push_back( neigh_north );
            // }
            // else
            // {
            //     best_neigh.push_front( neigh_north );
            //     best_neigh.push_back( neigh_south );
            // }

            // // 4. escolhe um dos vizinhos (em um deles vai entrar obrigatoriamente)
            Position vizinho;
            // for (auto i = 0u; i < best_neigh.size(); i++)
            // {
            //     if( map[best_neigh[i].y][best_neigh[i].x] == 0 ){
            //         vizinho = best_neigh[i];   // determina quem eh o vizinho
            //         freeSpaces -= 1; // diminui um espaco livre
            //         map[best_neigh[i].y][best_neigh[i].x] = 1; // marca no map que a posicao tá ocupada
            //         break;
            //     }
            // }

            //CAMINHO MAIOR
            
            if( map[neigh_north.y][neigh_north.x] == 0 ){
                vizinho = neigh_north;   // determina quem eh o vizinho
                freeSpaces -= 1; // diminui um espaco livre
                map[neigh_north.y][neigh_north.x] = 1; // marca no map que a posicao tá ocupada
            } else if( map[neigh_south.y][neigh_south.x] == 0 ){
                vizinho = neigh_south;
                freeSpaces -= 1;
                map[neigh_south.y][neigh_south.x] = 1;
            } else if( map[neigh_east.y][neigh_east.x]   == 0 ){
                vizinho = neigh_east;
                freeSpaces -= 1;
                map[neigh_east.y][neigh_east.x] = 1;
            } else if( map[neigh_west.y][neigh_west.x]   == 0 ){
                vizinho = neigh_west;
                freeSpaces -= 1;
                map[neigh_west.y][neigh_west.x] = 1;
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
