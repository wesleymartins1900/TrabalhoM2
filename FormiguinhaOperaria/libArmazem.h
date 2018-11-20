#pragma once
#include <vector>

#pragma region Armazem
#define QUANTIDADE_ARMAZEM 3 //Quantidade de armaz�ns PINO A, B, C
#define QUANTIDADE_POSICAO 4 //Quantidade de espa�o dispon�vel em cada armaz�m
#define POSICAO_INICIAL 0  // Pino no qual inicia as comidas 
#pragma endregion


//Fun��o que ir� validar se a comida � maior ou menor do que a j� colocada, evitando fraude no jogo.
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

//Retorna indice do armazem para controlar as comidas.
int retonarIndicePosicao(vector<vector<int>> &pino, int indiceArmazem) {
	for (int i = 0; i < QUANTIDADE_POSICAO; i++) {
		if (pino[indiceArmazem][i] != 0) {
			return i;
		}
	}
	return int(QUANTIDADE_POSICAO);
}

//Inser��o da comida no armazem.
bool inserirComida(vector<vector<int>> &pino, int indiceArmazem, int tamanhoComida) {
	int indicePosicao = retonarIndicePosicao(pino, indiceArmazem); // retorna indice do topo.
	//Verifica se pode ser adicionada a comida no armaz�m
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

void construtor()
{
	//Cria um vetor dentro de outro vetor
	vector<vector<int>> pino;

	// Cadastra os 3 armaz�ns A,B,C
	for (int i = 0; i < QUANTIDADE_ARMAZEM; i++) {
		// Cria o vetor de posi��o
		pino.push_back(vector<int>());
		// Reserva tamanho 4 de posi��o p/ cada vetor
		pino[i].reserve(QUANTIDADE_POSICAO);

		//Posi��o na qual o jogo inicia com as comidas
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
	}

}
