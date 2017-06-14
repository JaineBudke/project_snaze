/**
 * @file    token.h
 * @brief   Arquivo cabeçalho com a implementacao de funcoes que
            realizam a tokenização.
 * @author  Daniel Barbosa (nome@email.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */

#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>   // std::string
#include <iostream> // std::ostream

/**
 *  Esse eh o struct Token
 *  Aqui sao definidas variáveis bases para  a tokenização
 */
struct Token{

    public:

        /**
         *  Esse eh o enum token_t
         *  Aqui é denominado o operando e operator
         */
        enum class token_t : int
        {
            
            WALL = 0,       // Parede normal.
            INVISIBLE_WALL, // Parede invisivel.
            FREE            // Espaço livre.
        };

        std::string value; //<! O valor original do token.
        token_t type;      //<! O tipo do token.

        /**
         *  Esse eh o construtor padrão Token
         */
        explicit Token( std::string v_="", token_t t_ = token_t::FREE )
            : value( v_ )
            , type( t_ )
        {/* empty */}

        /// Apenas para ajudar a debug o codigo.
        friend std::ostream & operator<<( std::ostream& os_, const Token & t_ )
        {
            std::string types[] = { "WALL", "INVISIBLE_WALL", "FREE" };

            os_ << "<" << t_.value << "," << types[(int)(t_.type)] << ">";

            return os_;
        }

};

#endif
