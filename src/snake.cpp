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



/** @brief Tenta encontrar caminho para chegar na maçã.
    @return 1 se for possível, 0 se for impossível. */
bool Snake::solveMaze(){


    // TODO
    // FAZER ESSA PARTE ACHANDO REALMENTE DIRECAO VALIDA PARA A SNAKE

    // recuperar a posicao inicial automaticamente tbm

    /* 
    Game::Position posInicial;
    posInicial.x = 3;  // coluna
    posInicial.y = 5;  // linha

    Game::Direction dir1;
    Game::Direction dir2;

    dir1.x = posInicial.x + 1;
    dir1.y = posInicial.y;

    dir2.x = posInicial.x + 2;
    dir2.y = dir1.y;

    listDirections.push_back( dir1 );
    listDirections.push_back( dir2 );
    */

 


    // VER JEITO DE RECUPERAR ISSO
    //std::vector<Game::Position> tamanhos = gm.getSizeBoards();
    //Game::Position tam = tamanhos[ gm.getCurrentLevel() ];



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

    Game::Position maca;
    maca.y = 6;
    maca.x = 38;


    int visited = 110;


    Game::Position posInicial;
    posInicial.x = 3;  // coluna
    posInicial.y = 5;  // linha

    std::stack< Game::Position > marked;

    Game::Position currentPosition;

    // Tornar initialPosition a celula atual e marcar como visitada
    currentPosition = posInicial;
    map[posInicial.y][posInicial.x] = 1;
    visited += 1;

    // buscar celulas ainda não visitadas
    while( visited <= 44*13 ){

        // verifica se os vizinhos estao livres ou tem maçã
        // Vizinhos:
        Game::Position north, south, east, west;
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
            Game::Position vizinho;
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
            Game::Position newPosition = marked.top();

            // torna nova célula a atual
            currentPosition = newPosition;
            std::cout << "TESTE6\n";

        } else if( currentPosition.x == maca.x and currentPosition.y == maca.y ){
            
            while( !(marked.empty()) ){
                // ve quem é o prox 
                Game::Position dir = marked.top();

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

    return false;

}