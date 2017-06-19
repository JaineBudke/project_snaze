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
        case Direction::NORTH:
            pos.set(Direction::NORTH);
            break;

        case Direction::SOUTH:
            pos.set(Direction::SOUTH);
            break;

        case Direction::WEST:
            pos.set(Direction::WEST);
            break;

        case Direction::EAST:
            pos.set(Direction::EAST);
            break;
    }

    return pos;
}


/** @brief Tenta encontrar caminho para chegar na maçã.
    @return 1 se for possível, 0 se for impossível. */
bool Snake::solveMaze(){

    Position p(2,2);
    std::cout << "P("<<p.x<<","<<p.y<<")\n";
    p = adjacent_position(p, Direction::NORTH);
    std::cout << "P("<<p.x<<","<<p.y<<")\n";
    p = adjacent_position(p, Direction::SOUTH);
    std::cout << "P("<<p.x<<","<<p.y<<")\n";
    p = adjacent_position(p, Direction::WEST);
    std::cout << "P("<<p.x<<","<<p.y<<")\n";
    p = adjacent_position(p, Direction::EAST);



    // TODO
    // FAZER ESSA PARTE ACHANDO REALMENTE DIRECAO VALIDA PARA A SNAKE

    // recuperar a posicao inicial automaticamente tbm

    // VER JEITO DE RECUPERAR ISSO
    //std::vector<Position> tamanhos = gm.getSizeBoards();
    //Position tam = tamanhos[ gm.getCurrentLevel() ];

    /*
    int map[13][44];  // criando um mapa do labirinto
    for( int i=0 ; i < 13 ; i++ ){
        for( int j=0 ; j < 44 ; j++ ){
            map[i][j] = 0;
        }
    }

    for( int i=0 ; i < 13 ; i++ ){
        map[i][0] = 1;
        map[i][43] = 1;
    }

    for( int j=0 ; j < 44 ; j++ ){
        map[0][j] = 1;
        map[12][j] = 1;
    }

    Position maca;
    maca.y = 6;
    maca.x = 38;


    int visited = 110;


    Position posInicial;
    posInicial.x = 3;  // coluna
    posInicial.y = 5;  // linha

    std::stack< Position > marked;

    Position currentPosition;

    // Tornar initialPosition a celula atual e marcar como visitada
    currentPosition = posInicial;
    map[posInicial.y][posInicial.x] = 1;
    visited += 1;

    // buscar celulas ainda não visitadas
    while( visited <= 44*13 ){

        // verifica se os vizinhos estao livres ou tem maçã
        // Vizinhos:
        Position north, south, east, west;
        north.x = currentPosition.x;     // persiste coluna
        if( (currentPosition.y)+1 == 0 or (currentPosition.y)+1 == 1 ){
            north.y = (currentPosition.y)+1;  // incrementa linha
        } else {
            north.x = 0;
            north.y = 0;
        }


        south.x = currentPosition.x;     // persiste coluna
        if( (currentPosition.y)-1 == 0 or (currentPosition.y)-1 == 1 ){
            south.y = (currentPosition.y)-1; // decrementa linha
        } else {
            south.x = 0;
            south.y = 0;
        }


        if( (currentPosition.x)-1 == 0 or (currentPosition.x)-1 == 1 ){
            east.x = (currentPosition.x)-1; // decrementa coluna
        } else {
            east.x = 0;
            east.y = 0;
        }
        east.y = currentPosition.y;     // persiste linha


       if( (currentPosition.x)+1 == 0 or (currentPosition.x)+1 == 1 ){
            west.x = (currentPosition.x)+1; // incrementa coluna
        } else {
            west.x = 0;
            west.y = 0;
        }
        west.y = currentPosition.y;     // persiste linha


        if(    map[north.y][north.x] == 0
            or map[south.y][south.x] == 0
            or map[east.y][east.x]   == 0
            or map[west.y][west.x]   == 0 ){ // vizinhos não sao parede nem foram visitados

            // escolhe um dos vizinhos
            Position vizinho;
            if( map[north.y][north.x] == 0 ){
                vizinho = north;
                visited += 1;
                map[north.y][north.x] = 1;
                std::cout << "TESTE1\n";
            } else if( map[south.y][south.x] == 0 ){
                vizinho = south;
                visited += 1;
                map[south.y][south.x] = 1;
                std::cout << "TESTE2\n";
            } else if( map[east.y][east.x]   == 0 ){
                vizinho = east;
                visited += 1;
                map[east.y][east.x] = 1;
                std::cout << "TESTE3\n";
            } else if( map[west.y][west.x]   == 0 ){
                vizinho = west;
                visited += 1;
                map[west.y][west.x] = 1;
                std::cout << "TESTE4\n";
            }

            std::cout << "TESTE5\n";

            // dá o push da posicao atual pra pilha
            marked.push( currentPosition );

            // posicao atual agora é o vizinho escolhido
            currentPosition = vizinho;

        } else if( !(marked.empty()) ){ // se a pilha não estiver vazia

            // tira o ultimo elemento da pilha
            marked.pop();

            // vê e salva quem é o proximo
            Position newPosition = marked.top();

            // torna nova célula a atual
            currentPosition = newPosition;
            std::cout << "TESTE6\n";

        } else if( currentPosition.x == maca.x and currentPosition.y == maca.y ){

            while( !(marked.empty()) ){
                // ve quem é o prox
                Position dir = marked.top();

                std::cout << dir.y << " ; " <<dir.x << " - ";
                // add na lista
                listDirections.push_back( dir );
                // tira ele
                marked.pop();

            }
            std::cout << "TESTE7\n";

            return true;
        }


    }
    */
    return false;

}


