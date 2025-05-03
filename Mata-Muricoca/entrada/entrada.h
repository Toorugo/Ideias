#ifndef ENTRADA_H
#define ENTRADA_H

//exibe o menu interativo e retorna um valor 'int' igual a
//0 quando o ponteiro estiver em 'sair'; 1 quando em 'controles'; 2 quando em 'jogar'.
int menu ();

//exibe uma a configuração dos controles e o objetivo do jogo
void controles();

//exibe as tres dificuldades e retorna valor 'int' igual a
//0 quando o ponteiro estiver em 'normal'; 1 quando em 'froxo'; 2 quando em 'brabo'.
int dificuldades();

#endif