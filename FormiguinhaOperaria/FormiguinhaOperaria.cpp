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
#include "pch.h"
#include <vector>
#include <time.h>
#include "mypart.h"
#include "labFormiga.h"
#include <stdlib.h>

#define TEMPO_ENTRE_CHAMADA 40000 //em milisegundos

using namespace std;

//PARTE DO CÓDIGO ESCRITA POR HERIKC
//Motor principal do jogo, onde todo o jogo ficara em looping rodando.
void motorJogo(clock_t start, int mapa[23][30], vector<vector<int>> &pino, int contador_evento, clock_t tempo_inicial)
{ 
	static int tamanho_comida = 0;
	relogio tempo_geral;
	clock_t tempo_final, tempo_exe;

	while (true)
	{
		move_formiga(mapa, pino, tamanho_comida); //Função que irá movimentar a formiga.
		//Sequência de código que constroi a exibição do tempo.
		tempo_final = clock();
		tempo_exe = (tempo_final - tempo_inicial) / (double)CLOCKS_PER_SEC;
		tempo_real(tempo_exe, tempo_geral);
		cout << tempo_geral.minuto << ":" << tempo_geral.segundo << endl;
		cout << "Formiga com Alimento: " << tamanho_comida;
		//Limpa mapa desatualizado e o imprime novamente.
		system("cls");
		Imprime(mapa);
		if ((clock() - start) >= TEMPO_ENTRE_CHAMADA) //Verifica se atingiu o tempo para ocorrer evento.
		{
			evento(mapa);
			contador_evento = evento_de_risco(mapa, contador_evento);
			start = clock();
		}
	}
}
//FIM DA PARTE DO CÓDIGO ESCRITA POR HERIKC

//PARTE DO CÓDIGO ESCRITA POR WESLEY.
//Função para exibir menu do jogo.
void ExibeMenu()
{
	cout << "=============================================" << "\n";
	cout << "=========== FORMIGUINHA OPERARIA ============" << "\n";
	cout << "=============================================" << "\n";
	cout << "1) Novo Jogo" << "\n";
	cout << "2) Sair" << "\n";
	cout << "================================" << "\n";
	cout << "*          Instrucoes:        *" << endl;
	cout << "*                             *" << endl;
	cout << "*  O formigueiro esta caindo  *" << endl;
	cout << "*  retire todas as comidas    *" << endl;
	cout << "*  do dep. 1 e leve para o 3  *" << endl;
	cout << "*  As comidas possuem tamanho *" << endl;
	cout << "*  as maiores sempre em baixo *" << endl;
	cout << "* para não esmagar as menores *" << endl;
	cout << "*                             *" << endl;
	cout << "* Movimentacao - Teclas WASD  *" << endl;
	cout << "*                             *" << endl;
	cout << "********************************";
}
//FIM DA PARTE DO CÓDIGO ESCRITA POR WESLEY


int main()
{
	//PARTE DO CÓDIGO ESCRITA POR HERIKC
	//Inicialização de variaveis e controles básicos do jogo.
	ExibeMenu();

	int contador_evento = 0;
	clock_t start, tempo_inicial;

	tempo_inicial = clock();
	start = clock();	

	int mapa[23][30];
	leitura_txt(mapa);
	//FIM DA PARTE DO CÓDIGO ESCRITA POR HERIKC

	//PARTE DO CÓDIGO ESCRITA POR ALECSANDRA.
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
	}
	//FIM DA PARTE DO CÓDIGO ESCRITA POR ALECSANDRA
	//PARTE DO CÓDIGO ESCRITA POR WESLEY
	char rMenu;
	cin >> rMenu;

	//Inicia definitivamente o jogo;
	if (rMenu == '1')
		motorJogo(start, mapa, pino, contador_evento, tempo_inicial);

	//FIM DA PARTE DO CÓDIGO ESCRITA POR WESLEY
	system("Pause");
	return 0;
}