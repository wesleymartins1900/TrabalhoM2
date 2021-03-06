/*
	DESCRIÇÃO: Jogo criado para a disciplina de Algoritmos e Programação, referente à A1.M2.
	AUTORES:
		cout << "Alecsandra Tomasi";
		cout << "Herikc Brecher";
		cout << "Wesley Martins";
	Link para Repositório GitHub: https://github.com/wesleymartins1900/TrabalhoM2
*/

// Bibliotecas
#pragma once
#include "libMapa.h"
#include "libEventosJogo.h"
#include "libArmazem.h"
#include "libFormiga.h"

using namespace std;

//Motor principal do jogo, onde todo o jogo ficara em looping rodando.
void MotorJogo(int mapa[23][30], vector<vector<int>> &pino, int contador_evento)
{ 
	static int tamanho_comida = 0;
	
	char p = 1;

	while (true)
	{
		switch (p)
		{
			case 1:
				ExibeMenu();
				MoveFormiga(mapa, pino, tamanho_comida);
				break;
			case 2:
				system("close");
				break;
			default:
				break;
		}

		if (FimGame)
		{
			system("cls");
			cout << "FIM DE JOGO, VOCÊ PERDEU";
			break;
		}
	}
}

bool FimGame(vector<vector<int>> &pino, int indiceArmazem) {
	int verificador = 1;
	if (indiceArmazem == POSICAO_INICIAL) {
		return false;
	}
	for (int i = 0; i < QUANTIDADE_ARMAZEM; i++) {
		if (pino[indiceArmazem][i] == verificador) {
			verificador++;
		}
		else {
			return false;
		}
	}
	return true;
}

int main()
{
	construtor();

	//Inicia o jogo;
	system("cls");
	MotorJogo(start, mapa, pino, contador_evento, tempo_inicial);

	system("Pause");
	return 0;
}