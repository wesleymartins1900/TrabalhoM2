#pragma once
#include <fstream>

#define LI 16
#define CO 34

using namespace std;

void leitura_txt(int m[LI][CO]) {
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

void evento(int m[LI][CO]) {
	srand(time(NULL));
	int s[2], cont = 0, contador_evento = 0;
	bool ver = false;

	do { //Contador de paredes quebradas (vai até 3).
		do { //Verificador se a posição sorteada esta livre para ser quebrada.
			s[0] = rand() % LI + 1;
			s[1] = rand() % CO + 1;
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

int evento_de_risco(int m[LI][CO], int n) {
	int sorteio = 0;
	n++;
	if (n > 3) {
		sorteio = rand() % 101;
		if (n == 8) {
			if (sorteio <= 75) {
				for (int i = 0; i < LI; i++) {
					for (int j = 0; j < CO; j++) {
						m[i][j] = 1;
					}
				}				
			}
		}
		else if ((n - 3) * 15 >= sorteio) {
			for (int i = 0; i < LI; i++) {
				for (int j = 0; j < CO; j++) {
					m[i][j] = 1;
				}
			}
		}
	}

	return n;
}