//TODA BIBLIOTECA "mypart.h" FOI MANIPULADA E ESCRITA POR HERIKC.
#pragma once
#include "string"
#include <iostream>
#include "mypart.h"
#include <iomanip>
#include <fstream>
#include <stdlib.h> 
#include <time.h> 

#define LI 23
#define CO 30

using namespace std;
//leitura do arquivo externo, da matriz.
void leitura_txt(int m[LI][CO]) {
	ifstream txtFile;
	int l, c;

	txtFile.open("mapa_principal.txt");
	txtFile >> l >> c;

	//percorre o arquivo, preenchendo a matriz.
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			txtFile >> m[i][j];
		}
	}
	return;
}

//Evento de deformação do mapa a cada 40 segundos.
void evento(int m[LI][CO]) {
	srand(time(NULL));
	int s[2], cont = 0, contador_evento = 0;
	bool ver = false;

	do { //Contador de paredes quebradas (vai até 3).
		do { //Verificador se a posição sorteada esta livre para ser quebrada.
			s[0] = rand() % LI + 1;
			s[1] = rand() % CO + 1;
			if (m[s[0]][s[1]] == 0) { //Verifica se a posição é caminho livre, para assim destruir a parede.				
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

//Função que irá aumentar o grau de difuldade de acordo com a execução do jogo.
int evento_de_risco(int m[LI][CO], int n) {
	int sorteio = 0;
	n++; //contador de grau de dificultade;
	if (n > 3) { //Meidas serão implementas somente no quarto evento. (160 segundos de jogo).
		sorteio = rand() % 101;
		if (n >= 8) {
			if (sorteio <= 75) { //Criado um limitador de difuldade, de no máximo 75% de chance de perder no evento.
				for (int i = 0; i < LI; i++) {
					for (int j = 0; j < CO; j++) {
						if (m[i][j] == 6) {
							m[i][j] = 1; // Destrói o armazem, dando fim de jogo.
						}
					}
				}
			}
		}
		else if ((n - 3) * 15 >= sorteio) { //Dificultade abaixo de 75% com incremendo de 15% por evento.
			for (int i = 0; i < LI; i++) {
				for (int j = 0; j < CO; j++) {
					if (m[i][j] == 6) {
						m[i][j] = 1; // Destrói o armazem, dando fim de jogo.
					}
				}
			}
		}
	}

	return n;
}

//Struct usada para exibição de horário
struct relogio {
	int minuto;
	int segundo;
};

void tempo_real(int tempo_global, relogio &tempo_geral) {
	int minuto = tempo_global / 60; //Atribuição do valor do minuto;
	int segundo = tempo_global;

	if (segundo % 60 != 0) { //Verifica se no momento que converter segundo para minuto o resultado é inteiro.
		segundo -= (minuto * 60);
	}
	else {
		segundo = 0;
	}

	//Atribui os valores de tempo a struct relogio.
	tempo_geral.minuto = minuto;
	tempo_geral.segundo = segundo;
}