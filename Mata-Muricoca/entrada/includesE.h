#ifndef INCLUDESE_H
#define INCLUDESE_H

#define largura 25
#define altura 9

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdarg.h>

//posição do ponteiro
typedef struct _PP{
    int x,y;
    struct _PP* next;
    struct _PP* prev;
}pp;

#endif