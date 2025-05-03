#include "tudoJunto.h"

int main(){
    int resposta;
    funcao f = dificuldades;
    do{
        resposta = menu();
        switch(resposta){
            case 2:
                partida(f);
            break;
            case 1:
                controles();
            break;
        }
    }while(resposta);
    return 0;
}