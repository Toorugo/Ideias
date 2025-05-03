#ifndef INCLUDESJ_H
#define INCLUDEJ_H

#define largura 29
#define altura 17

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdarg.h>

//posição e status do jogador
typedef struct _PJ{
    int x,y;
    int stt;
}pj;
//posicao do inimigo
typedef struct _PE{
    int x,y;
}pe;


#endif