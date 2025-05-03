E = ./entrada
J = ./jogatina
M = ./MAIN

ALL:
	gcc -c $(E)/entrada.c -o $(E)/entrada.o
	gcc -c $(J)/jogatina.c -o $(J)/jogatina.o
	gcc $(M)/principal.c $(E)/entrada.o $(J)/jogatina.o -I $(E) -I $(J) -o ./Mata_Muriçoca

