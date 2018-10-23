#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h> // Para utilizar mgotoxy()
#include "mypart.h"

#pragma region Posições do Cenário
#define CAMINHO_LIVRE 0
#define CAMINHO_PAREDE 1
#define FORMIGA_SEM_ALIMENTO 8
#define FORMIGA_COM_ALIMENTO 9
#define ARMAZEM_LIVRE_1 4
#define ARMAZEM_LIVRE_2 5
#define ARMAZEM_COMPROMETIDO 6
#pragma endregion

using namespace std;

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
void Imprime(int m[L][C])
{
	// A partir dos dados preenchidos na matriz
	// é criado e exibido o mapa

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (m[i][j] == CAMINHO_LIVRE)
			{
				cout << " ";
			}
			else if (m[i][j] == CAMINHO_PAREDE)
			{
				cout << (char)178;
			}
			else if (m[i][j] == FORMIGA_SEM_ALIMENTO)
			{
				cout << "f";
			}
			else if (m[i][j] == FORMIGA_COM_ALIMENTO)
			{
				cout << "F";
			}
			else if (m[i][j] == ARMAZEM_LIVRE_1 || m[i][j] == ARMAZEM_LIVRE_2)
			{
				cout << "A";
			}
			else if (m[i][j] == ARMAZEM_COMPROMETIDO)
			{
				cout << "C";
			}
		}

		// Próxima linha da exibição
		cout << "\n";
	}
}

bool inserirComida(vector<vector<int>> &pino, int indiceArmazem, int tamanhoComida) {
	indiceArmazem = indiceArmazem - 4;
	
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
	indiceArmazem = indiceArmazem - 4;
	
	int indicePosicao = retonarIndicePosicao(pino, indiceArmazem); // retorna indice do topo
	int tamanhoComida = pino[indiceArmazem][indicePosicao]; //salva comida
	pino[indiceArmazem][indicePosicao] = 0; //zera comida
	return tamanhoComida;
}

void move_formiga(int m[L][C], vector<vector<int>> &pino)
{
	static int x = 1, y = 1;
	static int tamanho_comida =	1;
	char p;

	// Captura a última tecla pressionada sem necessidade de pressionar Enter
	p = _getche();

	int _valorXAnterior = x;
	int _valorYAnterior = y;

	// É validado se caminho está livre
	// Levamos em consideração que as bordas do mapa (linhas e colunas dos cantos) são paredes
	switch (p)
	{
		case 'w':
		case 'W':
			if (x > 1 && m[x--][y] == CAMINHO_LIVRE) x--;
			break;
		case 's':
		case 'S':
			if (x < L - 1 && m[x++][y] == CAMINHO_LIVRE) x++;
			break;
		case 'a':
		case 'A':
			if (y > 1 && m[x][y--] == CAMINHO_LIVRE) y--;
			break;
		case 'd':
		case 'D':
			if (y < C - 1 && m[x][y++] == CAMINHO_LIVRE) y++;
			break;
		default:
			return;
	}

	// Valida posição com Armazém
	if (m[x][y] == ARMAZEM_COMPROMETIDO)
	{
		// Pega um alimento
		x = _valorXAnterior;
		y = _valorYAnterior;

		tamanho_comida = removerComida(pino, ARMAZEM_COMPROMETIDO);

		m[x][y] = FORMIGA_COM_ALIMENTO;
	}
	else if (m[x][y] == ARMAZEM_LIVRE_1 || m[x][y] == ARMAZEM_LIVRE_2)
	{
		// Caso a formiga chegue a um Armazém Livre carregando algum alimento
		// retorna para posição anterior sem o alimento
		if (m[_valorXAnterior][_valorYAnterior] == FORMIGA_COM_ALIMENTO)
		{
			inserirComida(pino, m[x][y], tamanho_comida); 
		}

		x = _valorXAnterior;
		y = _valorYAnterior;

		m[x][y] = FORMIGA_SEM_ALIMENTO;
	}
	// Valida posição sem Armazém
	else if (m[_valorXAnterior][_valorYAnterior] == FORMIGA_COM_ALIMENTO)
	{
		m[x][y] = FORMIGA_COM_ALIMENTO;
		m[_valorXAnterior][_valorYAnterior] = CAMINHO_LIVRE;
	}
	else if (m[_valorXAnterior][_valorYAnterior] == FORMIGA_SEM_ALIMENTO)
	{
		m[x][y] = FORMIGA_SEM_ALIMENTO;
		m[_valorXAnterior][_valorYAnterior] = CAMINHO_LIVRE;
	}

	mgotoxy(0, 0);
	Imprime(m);
	Sleep(500);	
}