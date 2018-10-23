#pragma once
#include "string"
#include <iostream>
#include "mypart.h"
#include <iomanip>
#include <fstream>
#include <stdlib.h> 
#include <time.h> 
#define L 16
#define C 34

using namespace std;

void leitura_txt(int m[L][C]) {
	ifstream txtFile;
	int l, c;

	txtFile.open("mapa_principal.txt");
	txtFile >> l >> c;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			txtFile >> m[i][j];
		}
	}
	return;
}

void evento(int m[L][C]) {
	srand(time(NULL));
	int s[2], cont = 0, contador_evento = 0;
	bool ver = false;

	do { //Contador de paredes quebradas (vai até 3).
		do { //Verificador se a posição sorteada esta livre para ser quebrada.
			s[0] = rand() % L + 1;
			s[1] = rand() % C + 1;
			if (m[s[0]][s[1]] == 0) {
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

int evento_de_risco(int m[L][C], int &n) {
	int sorteio = 0;
	n++;
	if (n > 3) {
		sorteio = rand() % 101;
		if (n == 8) {
			if (sorteio <= 75) {
				for (int i = 0; i < L; i++) {
					for (int j = 0; j < C; j++) {
						m[i][j] = 1;
					}
				}				
			}
		}
		else if ((n - 3) * 15 >= sorteio) {
			for (int i = 0; i < L; i++) {
				for (int j = 0; j < C; j++) {
					m[i][j] = 1;
				}
			}
		}
	}

	return n;
}