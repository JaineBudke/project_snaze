/**
 * @file    parser.h
 * @brief   Arquivo cabeçalho com a implementacao de funcoes que
            realizam o parsing
 * @author  Daniel Barbosa (nome@email.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   30/05/2017
 * @date    19/06/2017
 */

#ifndef _PARSER_H_
#define _PARSER_H_

#include <iostream> // cout, cin
#include <iterator> // std::distance()
#include <vector>   // std::vector
#include <sstream>  // std::istringstream

#include "token.h"  // struct Token.


/**
 *  Essa eh a classe Parser
 *  Aqui sao definidas as funcoes para fazer o parsing
 */
class Parser {
    public:
        /// Essa classe representa o resultado da operação parsing.
        struct ParserResult
        {

            // Lista de possíveis erros de sintaxe.
            enum code_t {
                BOARD_OK = 0,      // Arquivo lido corretamente
                MISSING_START,     // Não há posição inicial
                EXTRANEOUS_SYMBOL, // Encontrado símbolo diferente de '#', ' ', '*', '.'
                ARCHIVE_NOT_FIND   // Arquivo nao encontrado
            };

            //=== Membros (public).
            code_t type;      //<! Error code.

            // Por padrão, o resultado é positivo.
            explicit ParserResult( code_t type_=PARSER_OK )
                    : type{ type_ }
            { /* empty */ }
        };


        //==== Public interface

        /** @brief Realiza o parsing
            @param e_ Expressão.
            @return Resultado. */
        ParserResult parse( std::string e_ );

        /** @brief Recupera tokens.
            @return Lista de tokens. */
        std::vector< Token > get_tokens( void ) const;

        //==== Special methods
        /// Constutor default.
        Parser() = default;
        ~Parser() = default;
        /// Desligar cópia e atribuição.
        Parser( const Parser & ) = delete;  // Construtor cópia.
        Parser & operator=( const Parser & ) = delete; // Atribuição.

    private:

        //==== Private members.
        std::string line;                    //<! Linha do tabuleiro a ser parsed
        std::string::iterator it_curr_symb;  //<! Ponteiro para o atual char dentro da expressão.
        std::vector< Token > token_list;     //<! Resultado da lista de tokens extraído da expressão.


        //=== Support methods.
        
        /** @brief Iterador para avançar para próximo char na expressão. */
        void next_symbol( void );                

        /** @brief Tenta aceitar o símbolo solicitado.
            @param s_ Simbolo do terminal.
            @return 1 se aceitar 0 otherwise. */
        bool accept( char s_ );           

        /** @brief Verifica se chegamos ao final da sequência de expressão.
            @return 1 se chegou 0 otherwise. */
        bool end_input( void ) const;     


        //=== Methods for parsing.

        /** @brief Processa uma parede.
            @return Resultado do processamento. */ 
        ParserResult wall();

        /** @brief Processa uma parede invisivel.
            @return Resultado do processamento. */ 
        ParserResult invisible_wall();

        /** @brief Processa um lugar livre.
            @return Resultado do processamento. */ 
        ParserResult free();

};

#endif
