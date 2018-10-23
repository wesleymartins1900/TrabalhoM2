#pragma once
#include "pch.h"
#include <vector>
#include <time.h>
#include "mypart.h"
#include "labFormiga.h"

using namespace std;

#define TEMPO_ENTRE_CHAMADA 40000 //em milisegundos

void motorJogo(clock_t start, int mapa[16][34], vector<vector<int>> &pino, int contador_evento)
{ 
	while (true)
	{
		move_formiga(mapa, pino);


		if ((clock() - start) >= TEMPO_ENTRE_CHAMADA) 
		{
			evento(mapa);
			contador_evento = evento_de_risco(mapa, contador_evento);
			start = clock();
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int contador_evento = 0;
	clock_t start, tempo_global;

	tempo_global = clock();
	start = clock();

	int mapa[16][34];
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
		inserirComida(pino, indiceArmazem, tamanhoComida);

		cout << "\n";
		for (int i = 0; i < QUANTIDADE_ARMAZEM; i++) {
			cout << i << " -> " << "\t";
			for (int j = 0; j < QUANTIDADE_POSICAO; j++) {
				cout << pino[i][j] << "\t";
			}
			cout << "\n";
		}
	}

	motorJogo(start, mapa, pino, contador_evento);

	system("Pause");
	return 0;
}