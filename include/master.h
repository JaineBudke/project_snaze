/**
 * @file    master.h
 * @brief   Arquivo cabeçalho com a definição do struct Position.
 * @author  Edivania Pontes (edivaniap@ufrn.edu.br)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    21/06/2017
 */

#ifndef _MASTER_H_
#define _MASTER_H_

#include <iostream>

using direction_t = short int;

using namespace std;


/*! enumeração de direções

			 north
	    west __|__ east
		       |
		     south
	*/
enum Direction
{
	NORTH = 0, //<! (-1, 0)
	SOUTH = 1, //<! ( 1, 0)
	WEST = 2,  //<! ( 0,-1)
	EAST = 3   //<! ( 0, 1)
};

struct Position
{
	int x;   //<! coluna da posição
	int y;   //<! linha da posição

	/*! inicializador */
	Position( int x_=0, int y_=0 )
		: x(x_)
		, y(y_)
	{ /*empty*/ }

	/*! configurador: muda a posição de acordo com uma direção */
	void set( const direction_t& dir )
	{
		switch( dir )
		{
			case NORTH:
				y -= 1;
				break;

			case SOUTH:
				y += 1;
				break;

			case WEST:
				x -= 1;
				break;

		  	case EAST:
				x += 1;
				break;
			default:
				cout << "Invalid Direction!";
		}
	}

	/*! sobrecarga de operador == */
	bool operator==( const Position& rhs ) const
	{
		return (y == rhs.y and x == rhs.x );
	}
};

/*! estrutura que vai definir o significado de cada caracter no mapa/labirinto */
struct Map
{
	char init    = 'i'; /*<! Caracter que define local inicial da snake */
	char wall    = '#'; /*<! Caracter que define uma parede */
	char way     = ' '; /*<! Caracter que define um caminho aberto */
	char spawn   = '*'; /*<! Caracter que define um local da comida */
	char marker  = '.'; /*<! Caracter que define um marcador */
};


#endif