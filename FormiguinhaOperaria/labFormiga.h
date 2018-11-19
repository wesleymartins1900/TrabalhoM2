//BIBLIOTECA SECUNDARIA ESCRITA EM CONJUNTO ENTRE ALECSANDRA E WESLEY.
#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h> // Para utilizar mgotoxy()
#include "mypart.h"
#include <stdio.h>

#pragma region Posições do Cenário
#define CAMINHO_LIVRE 0
#define CAMINHO_PAREDE 1
#define FORMIGA_SEM_ALIMENTO 8
#define FORMIGA_COM_ALIMENTO 9
#define ARMAZEM_LIVRE_1 4
#define ARMAZEM_LIVRE_2 5
#define ARMAZEM_COMPROMETIDO 6
#pragma endregion

#pragma region Armazem
#define QUANTIDADE_ARMAZEM 3 //Quantidade de armazéns PINO A, B, C
#define QUANTIDADE_POSICAO 4 //Quantidade de espaço disponível em cada armazém
#define POSICAO_INICIAL 0  // Pino no qual inicia as comidas 
#pragma endregion

using namespace std;

//PARTE DO CÓDIGO ESCRITA POR WESLEY.
// Ocultar o cursor do mouse
void hidecursor()
{
	// Armazena o estado atual do console
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Contém informações sobre o cursor do console
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;

	//Define o tamanho e a visibilidade do cursor para o buffer de tela do console especificado.
	SetConsoleCursorInfo(consoleHandle, &info);
}

void mgotoxy(short x, short y)
{
	// Move o cursor para determinada posição
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ x, y });
}

//Nessa função a matriz é percorrida e os números são substituidos
void Imprime(int m[LI][CO])
{
	// A partir dos dados preenchidos na matriz
	// é criado e exibido o mapa
	for (int i = 0; i < LI; i++)
	{
		for (int j = 0; j < CO; j++)
		{
			if (m[i][j] == CAMINHO_LIVRE)
			{
				cout << " ";
			}
			else if (m[i][j] == CAMINHO_PAREDE)
			{
				cout << char(178);
			}
			else if (m[i][j] == FORMIGA_SEM_ALIMENTO)
			{
				cout << char(167);
			}
			else if (m[i][j] == FORMIGA_COM_ALIMENTO)
			{
				cout << char(233);
			}
			else if (m[i][j] == ARMAZEM_LIVRE_1 || m[i][j] == ARMAZEM_LIVRE_2)
			{
				cout << "A";
			}
			else if (m[i][j] == ARMAZEM_COMPROMETIDO)
			{
				cout << char(232);
			}
		}

		// Próxima linha da exibição
		cout << "\n";
	}
}
//FIM DA PARTE DO CÓDIGO ESCRITA POR WESLEY.

//PARTE DO CÓDIGO ESCRITA POR ALECSANDRA.
//Função que irá validar se a comida é maior ou menor do que a já colocada, evitando fraude no jogo.

bool checkFimGame(vector<vector<int>> &pino, int indiceArmazem) {
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

//Inserção da comida no armazem.
bool inserirComida(vector<vector<int>> &pino, int indiceArmazem, int tamanhoComida) {
	int indicePosicao = retonarIndicePosicao(pino, indiceArmazem); // retorna indice do topo.
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

void AlteraPosicao(int m[LI][CO], vector<vector<int>> &pino, int &tamanho_comida, int &xAtual, int &yAtual, int xAnterior, int yAnterior)
{
	switch (m[xAtual][yAtual])
	{
	case ARMAZEM_COMPROMETIDO:
		xAtual = xAnterior;
		yAtual = yAnterior;

		if (m[xAtual][yAtual] == FORMIGA_SEM_ALIMENTO)
		{
			tamanho_comida = removerComida(pino, 0);

			m[xAtual][yAtual] = FORMIGA_COM_ALIMENTO;
		}
		else if (m[xAtual][yAtual] == FORMIGA_COM_ALIMENTO)
		{
			m[xAtual][yAtual] = inserirComida(pino, 0, tamanho_comida) ? FORMIGA_SEM_ALIMENTO : FORMIGA_COM_ALIMENTO;
		}
		break;
	case ARMAZEM_LIVRE_1:
	case ARMAZEM_LIVRE_2:
		// Caso a formiga chegue a um Armazém Livre carregando algum alimento
		// retorna para posição anterior sem o alimento
		if (m[xAnterior][yAnterior] == FORMIGA_COM_ALIMENTO)
		{
			m[xAnterior][yAnterior] = inserirComida(pino, m[xAtual][yAtual] - 3, tamanho_comida) ? FORMIGA_SEM_ALIMENTO : FORMIGA_COM_ALIMENTO;
		}
		else if (m[xAnterior][yAnterior] == FORMIGA_SEM_ALIMENTO)
		{
			tamanho_comida = removerComida(pino, m[xAtual][yAtual] - 3);

			m[xAnterior][yAnterior] = FORMIGA_COM_ALIMENTO;
		}

		xAtual = xAnterior;
		yAtual = yAnterior;
		break;
	case CAMINHO_PAREDE:
		xAtual = xAnterior;
		yAtual = yAnterior;
		break;
	case CAMINHO_LIVRE:
		m[xAtual][yAtual] = m[xAnterior][yAnterior];

		m[xAnterior][yAnterior] = CAMINHO_LIVRE;
		break;
	default:
		break;
	}
}
//FIM DA PARTE DO CÓDIGO ESCRITA POR ALECSANDRA.

//PARTE DO CÓDIGO ESCRITA POR WESLEY.
//Função que irá realizar toda movimentação e validação da mesma, sobre a formiga.
void move_formiga(int m[LI][CO], vector<vector<int>> &pino, int &tamanho_comida)
{
	static int x = 1, y = 2;
	char p = 0;

	if (_kbhit()) 
	{
		// Captura a última tecla pressionada
		p = _getch();

		int _valorXAnterior = x;
		int _valorYAnterior = y;
		
		// É validado se caminho está livre
		// Levamos em consideração que as bordas do mapa (linhas e colunas dos cantos) são paredes
		switch (p)
		{
			case 'w':
			case 'W':
				if (x >= 1) x--;
				break;
			case 's':
			case 'S':
				if (x < LI) x++;
				break;
			case 'a':
			case 'A':
				if (y >= 1) y--;
				break;
			case 'd':
			case 'D':
				if (y < CO) y++;
				break;
			default:
				return;
		}

		AlteraPosicao(m, pino, tamanho_comida, x, y, _valorXAnterior, _valorYAnterior);
		
		mgotoxy(0, 0);
		Imprime(m);
		hidecursor();
		Sleep(100);
	}
	//FIM DA PARTE DO CÓDIGO ESCRITA POR WESLEY.
}