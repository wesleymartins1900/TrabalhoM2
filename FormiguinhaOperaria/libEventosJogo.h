#pragma once
#include <time.h> 
#include "libMapa.h"

//Evento de deforma��o do mapa a cada 40 segundos.
void evento(int m[LI][CO]) {
	srand(time(NULL));
	int s[2], cont = 0, contador_evento = 0;
	bool ver = false;

	do { //Contador de paredes quebradas (vai at� 3).
		do { //Verificador se a posi��o sorteada esta livre para ser quebrada.
			s[0] = rand() % LI + 1;
			s[1] = rand() % CO + 1;
			if (m[s[0]][s[1]] == 0) { //Verifica se a posi��o � caminho livre, para assim destruir a parede.				
				m[s[0]][s[1]] = 1;
				ver = true;
				cont++;
			}
		} while (ver == false);
		ver = false;
	} while (cont <= 3);
	cont = 0;

	return;
}

//Fun��o que ir� aumentar o grau de difuldade de acordo com a execu��o do jogo.
int evento_de_risco(int m[LI][CO], int n) {
	int sorteio = 0;
	n++; //contador de grau de dificultade;
	if (n > 3) { //Meidas ser�o implementas somente no quarto evento. (160 segundos de jogo).
		sorteio = rand() % 101;
		if (n >= 8) {
			if (sorteio <= 75) { //Criado um limitador de difuldade, de no m�ximo 75% de chance de perder no evento.
				for (int i = 0; i < LI; i++) {
					for (int j = 0; j < CO; j++) {
						if (m[i][j] == 6) {
							m[i][j] = 1; // Destr�i o armazem, dando fim de jogo.
						}
					}
				}
			}
		}
		else if ((n - 3) * 15 >= sorteio) { //Dificultade abaixo de 75% com incremendo de 15% por evento.
			for (int i = 0; i < LI; i++) {
				for (int j = 0; j < CO; j++) {
					if (m[i][j] == 6) {
						m[i][j] = 1; // Destr�i o armazem, dando fim de jogo.
					}
				}
			}
		}
	}

	return n;
}