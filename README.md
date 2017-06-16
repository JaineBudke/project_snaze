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

    g++ -std=c++11 src/manager.cpp src/main.cpp src/game.cpp src/snake.cpp -I include -o snake
    

Comando para executar o programa
    
    ./snake data/tab1


## TODO

- [ ] Receber dados via leitura de arquivo.
- [ ] Validar dados recebidos e detectar erros especificados.
- [ ] Determinar um conjunto de direções corretamente (IA).
- [ ] Trabalhar corretamente com os estados do jogo.


Programa desenvolvido por _Daniel Barbosa_ (< *email@email.com* >) e _Jaine Budke_ (< *jainebudke@hotmail.com* >), 2017.1
