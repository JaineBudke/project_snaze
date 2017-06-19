#ifndef _MASTER_H_
#define _MASTER_H_

#define direction_t short int

#include <iostream>


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
	int x;   /*<! linha da posição */
	int y; /*<! coluna da posição */

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
			case Direction::NORTH:
				x -= 1;
				break;
				
			case Direction::SOUTH:
				x += 1;
				break;

			case Direction::WEST: 
				y -= 1;
				break;
				
		  	case Direction::EAST: 
				y += 1;
				break;
			default:
				cout << "Invalid Direction!";
		}
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

#endif