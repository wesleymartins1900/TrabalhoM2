#pragma once
#include <fstream>

#define LI 23
#define CO 30

#define TEMPO_ENTRE_CHAMADA 60000 //em milisegundos

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

void arrumaAquiHerikc()
{
	relogio tempo_geral;
	clock_t tempo_final, tempo_exe;


	//Sequência de código que constroi a exibição do tempo.
	tempo_final = clock();
	tempo_exe = (tempo_final - tempo_inicial) / (double)CLOCKS_PER_SEC;
	tempo_real(tempo_exe, tempo_geral);
	cout << tempo_geral.minuto << ":" << tempo_geral.segundo << endl;
	cout << "Formiga com Alimento: " << tamanho_comida;
	//Limpa mapa desatualizado e o imprime novamente.
	mgotoxy(0, 0);
	Imprime(mapa);
	if ((clock() - start) >= TEMPO_ENTRE_CHAMADA) //Verifica se atingiu o tempo para ocorrer evento.
	{
		evento(mapa);
		contador_evento = evento_de_risco(mapa, contador_evento);
		start = clock();
	}
}

void ExibeMenu()
{
	cout << "=============================================" << "\n";
	cout << "=========== FORMIGUINHA OPERARIA ============" << "\n";
	cout << "=============================================" << "\n";
	cout << "1) Novo Jogo" << "\n";
	cout << "2) Sair" << "\n";
	cout << "\n";
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


void construtor()
{
	//Inicialização de variaveis e controles básicos do jogo.

	int contador_evento = 0;
	clock_t start, tempo_inicial;

	tempo_inicial = clock();
	start = clock();

	int mapa[23][30];
	leitura_txt(mapa);

}



// HERIKC - EXEMPLO DE THREAD

// #include "thread.h"

void foo()
{
	// do stuff...
}

void bar(int x)
{
	// do stuff...
}

int main()
{
	thread first(foo);     // spawn new thread that calls foo()
	thread second(bar, 0);  // spawn new thread that calls bar(0)

	std::cout << "main, foo and bar now execute concurrently...\n";

	// synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	std::cout << "foo and bar completed.\n";

	return 0;
}








