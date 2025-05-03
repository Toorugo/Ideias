#include "entrada.h"

int main(){
    int resposta;
    do{
        resposta = menu();
        switch(resposta){
            case 2:
                dificuldades();
            case 1:
                controles();
            break;
        }

    }while(resposta);
    return 0;
}