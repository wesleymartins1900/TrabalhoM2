// FormiguinhaOperaria.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "stdafx.h"
#include "string"
#include <iostream>
#include "mypart.h"
#include <iomanip>
#include <fstream>
#include <time.h>
#define TEMPO_ENTRE_CHAMADA 40000 //em milisegundos

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	clock_t start, tempo_global;
	int mapa[16][34], contador_evento = 0;

	leitura_txt(mapa);
	tempo_global = clock();
	start = clock();
	while (true) {
		if ((clock() - start) >= TEMPO_ENTRE_CHAMADA) {
			evento(mapa);
			//contador_evento = evento_de_risco(mapa,contador_evento); //função incompleta, tem que passar posição do armazem.
			start = clock();
		}
	}

	system("Pause");
	return 0;
}
