#include "jogatina.h"
#include "includesJ.h"

void mostrarj(char** m){
    system("cls");
    for(int y = 0;y < altura; y++){
        for(int x = 0;x < largura;x++){
                printf("\x1B[33m\e[?25l%c", m[y][x]);
        }
        puts("");
    }
}

void inserirPalavraj(char **matriz, int lin, int col, const char *palavra) {
    int len = strlen(palavra);
    for (int i = 0; i < len; i++) {
        matriz[lin][col + i] = palavra[i];
    }
}

char** exibicaoj(pj k,pe N,pe P){
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
            if(x == 0 || x == largura - 1){
                matriz[y][x] = '|';
                if(8 == y || y ==10 || y == 9) matriz[y][x] = ' ';
                if(y == 7 || y == 11) matriz[y][x] = 'o';
            }
            else matriz[y][x] = ' ';    
        }
    }
    for(int x = 0;x < largura;x++){
        matriz[altura - 1][x] = '-';
    }
    matriz[1][largura] = ' ';
    matriz[altura - 1][largura] = ' ';
    matriz[k.y][k.x] = 'k';
    matriz[N.y][N.x] = 'N';
    matriz[P.y][P.x] = 'P';
    char buffer[22];
    sprintf(buffer,"%d",k.stt);
    inserirPalavraj(matriz,0,0,"SCORE:");
    inserirPalavraj(matriz,0,6,buffer);
    return matriz;
}

void limpaBuffer(){
    int lixo;
    while((lixo = _getch()) != EOF && lixo != '\n') ;
}

void jogador(char** map,char ent,pj*k){
    switch(ent){
    case '4':
    if(k->x != 1){
        map[k->y][k->x] = ' ';
        k->x -= 2;
        if(map[k->y][k->x] != ' '){
            if(1<=k->x-2){
                if(map[k->y][k->x] == 'N'){
                k->stt +=3;
                }
                else if(map[k->y][k->x] == 'P'){
                k->stt +=4;
                } 
                k->x -= 2;
            }
        }
        map[k->y][k->x] = 'k';
    }
        break;
    case '6':
    if(k->x != (largura - 2)){
        map[k->y][k->x] = ' ';
        k->x += 2;
        if(map[k->y][k->x] != ' '){
            if(largura - 2>=k->x+2){
                if(map[k->y][k->x] == 'N'){
                    k->stt +=3;
                }
                else if(map[k->y][k->x] == 'P'){
                    k->stt +=4;
                }
                k->x += 2;
            }
        }
        map[k->y][k->x] = 'k';
    }
        break;
    case '8':
    if(k->y != 1){
        map[k->y][k->x] = ' ';
        k->y -= 1;
        if(map[k->y][k->x] != ' '){
            if(1<=k->y-1){
                if(map[k->y][k->x] == 'N'){
                    k->stt +=3;
                }
                else if(map[k->y][k->x] == 'P'){
                    k->stt +=4;
                }
                k->y -= 1;
            }
        }
        map[k->y][k->x] = 'k';
    }
        break;
    case '2':
    if(k->y != (altura - 2)){
        map[k->y][k->x] = ' ';
        k->y += 1;
        if(map[k->y][k->x] != ' '){
            if((altura-2)>=k->y+1){
                if(map[k->y][k->x] == 'N'){
                    k->stt +=3;
                }
                else if(map[k->y][k->x] == 'P'){
                    k->stt +=4;
                }
                k->y += 1;
            }
        }
        map[k->y][k->x] = 'k';
    }
        break;
    case '7':
    if(k->y != 1 && k->x != 1){
        map[k->y][k->x] = ' ';
        k->y -= 1;
        k->x -= 2;
        if(map[k->y][k->x] != ' '){
            if(1<=k->x-2 && 1 <= k->y-1){
                if(map[k->y][k->x] == 'N'){
                    k->stt +=3;
                }
                else if(map[k->y][k->x] == 'P'){
                    k->stt +=4;
                }
                k->x -= 2;
                k->y -= 1;
            }
        }
        map[k->y][k->x] = 'k';
    }
        break;
    case '9':
    if(k->y != 1 && k->x != (largura - 2)){
        map[k->y][k->x] = ' ';
        k->y -= 1;
        k->x += 2;
        if(map[k->y][k->x] != ' '){
            if((largura - 2)<=k->x+2 && 1 <= k->y-1){
                if(map[k->y][k->x] == 'N'){
                    k->stt +=3;
                }
                else if(map[k->y][k->x] == 'P'){
                    k->stt +=4;
                }
                k->x += 2;
                k->y -= 1;
            }
        }
        map[k->y][k->x] = 'k';
    }
        break;
    case '1':
    if(k->y != (altura - 2) && k->x != 1){
        map[k->y][k->x] = ' ';
        k->y += 1;
        k->x -= 2;
        if(map[k->y][k->x] != ' '){
            if(1<=k->x-2 && (altura - 2) >= k->y+1){
                if(map[k->y][k->x] == 'N'){
                    k->stt +=3;
                }
                else if(map[k->y][k->x] == 'P'){
                    k->stt +=4;
                }
                k->x -= 2;
                k->y += 1;
            }
        }
        map[k->y][k->x] = 'k';
    }
        break;
    case '3':
    if(k->y != (altura - 2) && k->x != (largura - 2)){
        map[k->y][k->x] = ' ';
        k->y += 1;
        k->x += 2;
        if(map[k->y][k->x] != ' '){
            if((largura - 2)<=k->x+2 && (altura - 2) <= k->y+1){
                if(map[k->y][k->x] == 'N'){
                    k->stt +=3;
                }
                else if(map[k->y][k->x] == 'P'){
                    k->stt +=4;
                }
                k->x -= 2;
                k->y -= 1;
            }
        }
        map[k->y][k->x] = 'k';
    }
        break;
    }
    char buffer[22];
    sprintf(buffer,"%d",k->stt);
    inserirPalavraj(map,0,0,"SCORE:");
    inserirPalavraj(map,0,6,buffer);
}
 
void fimdeJogo(int stt){
    if(stt){
        printf("\n");
        printf("███    ███  ██████  ███████ ███████ ██   ██  ██ ████████  ██████     ██████ ██   ██  █████  ████████  ██████  \n");
        printf("████  ████ ██    ██ ██      ██   ██ ██   ██  ██   ██    ██    ██    ██      ██   ██ ██   ██    ██    ██    ██ \n");
        printf("██ ████ ██ ██    ██ █████   ██   ██ ██   ██  ██   ██    ██    ██    ██      ███████ ███████    ██    ██    ██ \n");
        printf("██  ██  ██ ██    ██      ██ ██   ██ ██   ██  ██   ██    ██    ██    ██      ██   ██ ██   ██    ██    ██    ██ \n");
        printf("██      ██  ██████  ███████ ███████ ███████  ██   ██     ██████     ██████  ██   ██ ██   ██    ██     ██████  \n");
        printf("\n");
        printf("SCORE:%d",stt);
        printf("                                Pressione QUALQUER TECLA para sair...\n");
        _getch(); 
    }
    else{
        printf("  ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ \n");
        printf(" ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗\n");
        printf(" ██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝\n");
        printf(" ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\n");
        printf(" ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\n");
        printf("  ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");

        printf("\n\n           Pressione qualquer tecla para sair...\n");
        _getch();
    }
}

pj* criaPJ(){
    pj* p = (pj*) malloc(sizeof(pj));
    p->stt = 1;
    p->x = 1;
    p->y = 9;
}

pe* criaPE(int y,int x){
    pe* p = (pe*) malloc(sizeof(pe));
    p->x = x;
    p->y = y;
    return p;
}


void inimigoN(char** mapa,pj k,pe* N){
    int vy = k.y - N->y;
    int vx = k.x - N->x;
    mapa[N->y][N->x] = ' ';
    if(abs(vy) >= abs(vx)){
        if(vy > 0) N->y++;
        else N->y--;
    }
    if(abs(vx) >= abs(vy)){
        if(vx > 0) N->x+=2;
        else N->x-=2;
    }
    mapa[N->y][N->x] = 'N';
}

void inimigoP(char** mapa,pj k,pe* P){
    int vy = k.y - P->y;
    int vx = k.x - P->x;
    mapa[P->y][P->x] = ' ';
    if(vx == 0 && vy !=0) P->y += (vy/abs(vy));
    else if(vy == 0 && vx != 0) P->x += (vx/abs(vx));
    else{
    P->x += (vx/abs(vx));
    P->y += (vy/abs(vy));
    }
    mapa[P->y][P->x] = 'P';
}

int decideK (const char** mapa,pj* k,pe N,pe P){
    if(mapa[k->y][k->x] == mapa[N.y][N.x] || mapa[k->y][k->x] == mapa[P.y][P.x]){
        k->stt = 0;
        return 0;
    }
    pe kN;
    kN.x = (k->x - N.x)/2;
    kN.y = k->y - N.y;
    if(kN.x == 0 && abs(kN.y) <= 2){ 
        k->stt = 0;
        return 0;
    }
    if(kN.y == 0 && abs(kN.y)<= 2){
        k->stt = 0;
        return 0;
    }
    pe kP;
    kP.x = (k->x - P.x)/2;
    kP.y = k->y - P.y;
    if(abs(kP.x) == abs(kP.y) && abs(kP.x) + abs(kP.y) <= 6){ 
        k->stt = 0;
        return 0;
    }
    if( k->x == largura - 2 && 8<=k->y && k->y<=10 && k->stt >= 7)return 1;
    else return 0;
}

int voltaMenu(){
    puts("PAUSE");
    puts("digite 'P' para sair e qualquer outra tecla para continuar..");
    char controle = _getch();
    if(controle == 'p') return 1;
    else return 0;
}
void partida(funcao dificuldade){
    pj* k = criaPJ();
    pe* N = criaPE(1,largura - 1);
    pe* P = criaPE(altura - 2,largura - 1);
    char** mapa = exibicaoj(*k,*N,*P);
    char controle;
    int D = (*dificuldade)();
    while(k->stt){
        inimigoN(mapa,*k,N);
        inimigoP(mapa,*k,P);
        mostrarj(mapa);
        Sleep(D);
        if(kbhit()){
            controle = _getch();
            if(controle == 'p' && voltaMenu()) break;
            jogador(mapa,controle,k);
        }
        mostrarj(mapa); 
        if(decideK((const char**)mapa,k,*N,*P)) break;
    }
    fimdeJogo(k->stt);
}