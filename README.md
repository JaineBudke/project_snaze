# PROJETO-SNAZE


## Sobre o projeto:

O Snaze é uma simulação do jogo clássico Snake.


## Erros tratados:

- Board_ok;
- Missing_start;
- Extraneous symbol;
- Archive_not_find.


## Como compilar:

Para compilar o projeto, basta digitar, pelo terminal, o comando abaixo

	make

ou

    g++ -std=c++11 src/manager.cpp src/main.cpp src/game.cpp src/snake.cpp -I include -o snake
    

Comando para executar o programa
    
    ./bin/snake data/tab1


## TODO

- [x] Receber dados via leitura de arquivo.
- [x] Validar dados recebidos e detectar erros especificados.
- [x] Determinar um conjunto de direções corretamente (IA).
- [ ] Trabalhar corretamente com os estados do jogo.


Programa desenvolvido por _Edivania Pontes_ (< *edivaniap@ufrn.edu.br* >) e _Jaine Budke_ (< *jainebudke@hotmail.com* >), 2017.1
