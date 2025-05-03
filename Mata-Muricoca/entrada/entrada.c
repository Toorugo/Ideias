#include "entrada.h"
#include "IncludesE.h"

//insere uma frase dentro de uma matriz** 
//cuidado overflow!
void inserirPalavra(char **matriz, int lin, int col, const char *palavra) {
    int len = strlen(palavra);
    for (int i = 0; i < len; i++) {
        matriz[lin][col + i] = palavra[i];
    }
}

int* Vetor(int quantidade, ...) {
    va_list args;
    va_start(args, quantidade);

    int *vetor = (int*) malloc(quantidade * sizeof(int));
    if (vetor == NULL) {
        perror("Erro ao alocar vetor");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < quantidade; i++) {
        vetor[i] = va_arg(args, int);
    }

    va_end(args);
    return vetor;
}

pp* criaPP(){
    pp* e = (pp*) malloc(1 * sizeof(pp));
    return e;
}
pp* encadeiaPP (int quantidade, ...){
    va_list args;
    va_start(args, quantidade);

    int *vetor = (int*) malloc(quantidade * sizeof(int));
    if (vetor == NULL) {
        perror("Erro ao alocar vetor");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < quantidade; i++) {
        vetor[i] = va_arg(args, int);
    }

    va_end(args);

    pp *primeiro = (pp*) calloc(1,sizeof(pp));
    primeiro->y = vetor[0];
    primeiro->x = 12;
    pp *anterior = primeiro;

    for (int i = 0; i < quantidade - 1; i++) {
        pp *novo = (pp*) calloc(1,sizeof(pp));
        novo->y = vetor[i+1];
        novo->x = 12;

        anterior->next = novo;
        novo->prev = anterior;
        anterior = novo;
        novo = novo->next;
    }
    anterior->next = primeiro;
    primeiro->prev = anterior;

    return primeiro;
}
void destroiLista(pp** f){
    pp* l;
    (*f)->prev->next = NULL;
    while(*f != NULL){
        l = *f;
        *f = (*f)->next;
        free(l);
    }
    free(f);
}
//atualiza a tela
void mostrar(char** m){
    system("cls");
    for(int y = 0;y < altura; y++){
        for(int x = 0;x < largura;x++){
            printf("\x1B[33m\e[?25l%c", m[y][x]);
        }
        puts("");
    }
}
    
//desenha a configuração de exibição do menu
char** exibicao(pp* p, const char* p1, const char* p2, const char* p3){
    char** matriz = (char**) malloc(altura * sizeof(char*));
    for(int a = 0; a < altura; a++){
        matriz[a] = (char*) malloc (largura * sizeof(char));
    }
    if(!matriz){
        fprintf(stderr,"na função exibição ha um erro de memoria");
        exit(EXIT_FAILURE);
    }
    //paredes laterais(limite do mapa)
    for(int x = 0;x < largura;x++){
        matriz[0][x] = '_';
    }
    for(int y = 1;y < altura - 1;y++){
        for(int x = 0;x < largura;x++){
                matriz[y][x] = ' ';
            }
    }
    for(int x = 0;x < largura;x++){
        matriz[altura - 1][x] = '-';
    }
    inserirPalavra(matriz,2,3,"MATA");
    inserirPalavra(matriz,3,1,"MURIÇOCA!");
    inserirPalavra(matriz,2,12,">");
    inserirPalavra(matriz,6,17,p3);
    inserirPalavra(matriz,4,14,p2);
    inserirPalavra(matriz,2,16,p1);
    p->x = 12;
    p->y = 2;

    return matriz;
}
// controla o ponteiro do menu e exibe a tela
//retorna 2 para jogar;1 para controles;0 para sair
int menu(){
    pp* ponteiro = encadeiaPP(3,2,4,6);
    char** menuE = exibicao(ponteiro,"JOGAR?&", "CONTROLES?&", "SAIR?&");
    char controle = ' ';
    int c = 0;
    mostrar(menuE);
    while(controle != '5'){
        if(_kbhit){
            controle = _getch();
            switch(controle){
                case '8':
                    menuE[ponteiro->y][ponteiro->x] = ' ';
                    ponteiro = ponteiro->prev;
                    menuE[ponteiro->y][ponteiro->x] = '>';
                break;
                case '2':
                    menuE[ponteiro->y][ponteiro->x] = ' ';
                    ponteiro = ponteiro->next;
                    menuE[ponteiro->y][ponteiro->x] = '>';
                break;
            }
            inserirPalavra(menuE,2 + c,3,"    ");
            inserirPalavra(menuE,3 + c,1,"          ");
            c = (c + 1)%3;
            inserirPalavra(menuE,2 + c,3,"MATA");
            inserirPalavra(menuE,3 + c,1,"MURIÇOCA!");
        }
        mostrar(menuE);
    }
    switch(ponteiro->y){
        case 2:
            destroiLista(&ponteiro);
            return 2;
        case 4:
            destroiLista(&ponteiro);
            return 1;
        case 6:
            destroiLista(&ponteiro);
            return 0;
    }
   
}

void controles(){
    system("cls");
    puts("________________________________________________");
    printf("7 8 9\n4   6 -> OS NUMEROS SÃO OS DIRECIONAIS\n1 2 3\n");
    puts("________________________________________________");
    puts("pressione qualquer tecla para continuar..");
    _getch();
    system("cls");
    puts("________________________________________________");
    puts("- VOCE E O 'K' E DEVE EVITAR OS ATAQUES DE 'N' E 'P' ENQUANTO TENTA ATRAVESAR A SALA");
    puts("________________________________________________");
    _getch();
    system("cls");
    puts("________________________________________________");
    puts("- 'N' ATACA EM LINHA RETA ENQUANTO 'P' ATACA NA DIAGONAL");
    puts("________________________________________________");
    _getch();
    system("cls");
    puts("________________________________________________");
    puts("- VC DEVE PASSAR POR CIMA DE CADA UM DELES E ATRAVESSAR A SALA ATE A OUTRA JANELA!");
    puts("________________________________________________");
    _getch();
    system("cls");
    puts("________________________________________________");
    puts("BOA SORTE!!  K K   K       K");
    _getch();
}

int dificuldades(){
    pp* ponteiro = encadeiaPP(3,2,4,6);
    char** dificuldade = exibicao(ponteiro, "NORMAL :|", "  fROXO /:(", "BRABO :)");
    char controle = ' ';
    int c = 0;
    mostrar(dificuldade);
    while(controle != '5'){
        if(_kbhit){
            controle = _getch();
            switch(controle){
                case '8':
                    dificuldade[ponteiro->y][ponteiro->x] = ' ';
                    ponteiro = ponteiro->prev;
                    dificuldade[ponteiro->y][ponteiro->x] = '>';
                break;
                case '2':
                    dificuldade[ponteiro->y][ponteiro->x] = ' ';
                    ponteiro = ponteiro->next;
                    dificuldade[ponteiro->y][ponteiro->x] = '>';
                break;
            }
            inserirPalavra(dificuldade,2 + c,3,"    ");
            inserirPalavra(dificuldade,3 + c,1,"          ");
            c = (c + 1)%3;
            inserirPalavra(dificuldade,2 + c,3,"MATA");
            inserirPalavra(dificuldade,3 + c,1,"MURIÇOCA!");
        }
        mostrar(dificuldade);
    }
    switch(ponteiro->y){
        case 2:
            destroiLista(&ponteiro);
            return 300;
        case 4:
            destroiLista(&ponteiro);
            return 1000;
        case 6:
            destroiLista(&ponteiro);
            return 100;
    }
}