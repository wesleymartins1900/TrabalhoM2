
#include "string"
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <time.h>
#include "mypart.h"
#include <time.h>


#define QUANTIDADE_ARMAZEM 3 //Quantidade de armazéns PINO A, B, C
#define QUANTIDADE_POSICAO 4 //Quantidade de espaço disponível em cada armazém
#define POSICAO_INICIAL 0  // Pino no qual inicia as comidas 

using namespace std;

#include "mypart.h"
#include <iomanip>
#include <fstream>
#include <time.h>
#define TEMPO_ENTRE_CHAMADA 40000 //em milisegundos

bool verificaTamanhoComida(vector<vector<int>> &pino, int indiceArmazem, int tamanhoComida) 
{
	for (int i = 0; i < QUANTIDADE_POSICAO; i++) {
		if (pino[indiceArmazem][i] != 0) {
			if (pino[indiceArmazem][i] > tamanhoComida) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int retonarIndicePosicao(vector<vector<int>> &pino, int indiceArmazem) {
	for (int i = 0; i < QUANTIDADE_POSICAO; i++) {
		if (pino[indiceArmazem][i] != 0) {
			return i;
		}
	}
	return QUANTIDADE_POSICAO;
}

bool inserirComida(vector<vector<int>> &pino, int indiceArmazem, int tamanhoComida) {
	int indicePosicao = 3;//retonarIndicePosicao(pino, indiceArmazem); // retorna indice do topo.
	//Verifica se pode ser adicionada a comida no armazém
	if (verificaTamanhoComida(pino, indiceArmazem, tamanhoComida)) {
		if ((indicePosicao - 1) >= 0) {
			pino[indiceArmazem][indicePosicao - 1] = tamanhoComida;

			return true;
		}
	}
	return false;
}
//Remove a comida do topo do armazem e retorna seu valor
int removerComida(vector<vector<int>> &pino, int indiceArmazem) 
{
	int indicePosicao = retonarIndicePosicao(pino, indiceArmazem); // retorna indice do topo
	int tamanhoComida = pino[indiceArmazem][indicePosicao]; //salva comida
	pino[indiceArmazem][indicePosicao] = 0; //zera comida
	return tamanhoComida;
}

void motorJogo(clock_t start, int mapa[16][34])
{
	while (true)
	{
		


		if ((clock() - start) >= TEMPO_ENTRE_CHAMADA) 
		{
			evento(mapa);
			//contador_evento = evento_de_risco(mapa,contador_evento); //função incompleta, tem que passar posição do armazem.
			start = clock();
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	clock_t start, tempo_global;

	tempo_global = clock();
	start = clock();

	int mapa[16][34], contador_evento = 0;
	leitura_txt(mapa);

	//Cria um vetor dentro de outro vetor
	vector<vector<int>> pino;

	// Cadastra os 3 armazéns A,B,C
	for (int i = 0; i < QUANTIDADE_ARMAZEM; i++) {
		// Cria o vetor de posição
		pino.push_back(vector<int>());
		// Reserva tamanho 4 de posição p/ cada vetor
		pino[i].reserve(QUANTIDADE_POSICAO);

		//Posição na qual o jogo inicia com as comidas
		if (i == POSICAO_INICIAL) {
			for (int j = 1; j <= QUANTIDADE_POSICAO; j++) {
				pino[i].push_back(j);
			}
		}
		else {
			for (int j = 0; j < QUANTIDADE_POSICAO; j++) {
				pino[i].push_back(0);
			}
		}
		
		int tamanhoComida = removerComida(pino, 0);
		cout << tamanhoComida;

		int indiceArmazem = 1; //Informar o indice do armazem no qual vai ser colocado a comida
		//inserirComida(pino, indiceArmazem, tamanhoComida);

		cout << "\n";
		for (int i = 0; i < QUANTIDADE_ARMAZEM; i++) {
			cout << i << " -> " << "\t";
			for (int j = 0; j < QUANTIDADE_POSICAO; j++) {
				cout << pino[i][j] << "\t";
			}
			cout << "\n";
		}
	}

	motorJogo(start, mapa);

	system("Pause");
	return 0;
}