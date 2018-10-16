#include <iostream>
#include <windows.h>
#include <conio.h> // Para utilizar mgotoxy()

#define L 16
#define C 34

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

void mgotoxy(int x, int y)
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
			if (m[i][j] == 0)
			{
				// Caminho Livre
				cout << " ";
			}
            else if (m[i][j] == 1)
			{
				// (char)178 Monta uma "parede" utilizando caractere ASCII
                cout << (char)178;
            }
			else if (m[i][j] == 8)
			{
				// Formiga sem carregar alimento
				cout << "f";
			} 
			else if (m[i][j] == 9)
			{
				// Formiga carregando alimento
				cout << "F";
			}
			else if (m[i][j] == 5)
			{
				// Armazém disponível
				cout << "A";
			}
			else if (m[i][j] == 6)
			{
				// Armazém comprometido
				cout << "C";
			}
		}
		cout << "\n";
    }
}

void move_formiga(int m[L][C])
{
    static int x = 1, y = 1;
    char p;

	// Aguarda uma tecla ser pressionada
     if (_kbhit())
	 {
		// Captura a última tecla pressionada sem necessidade de pressionar Enter
		p = getche();

        m[x][y] = 0;

		// Além de identificar se tecla pressionada, é validado se caminho está livre
		// ou seja, posição igual 0
        switch(p)
        {
            case 'w':
			case 'W':
				if (x > 0 && m[x--][y] != 0)
					return;
				x--;
				break;      
            case 's':
			case 'S':
				if (x <= L && m[x++][y] != 0)
					return;
				x++;
				break;     
            case 'a':
			case 'A':
				if (y > 0 && m[x][y--] != 0)
					return;
				y--; 
				break;
            case 'd':
			case 'D':
				if (y <= C && m[x][y++] != 0)
					return;
				y++;
				break;
			default: 
				return;
        }

        m[x][y] = 9;

        Sleep(100);
        mgotoxy(0, 0);
        Imprime(m);
     }
}

int main()
{
	//// ToDo
    // m[L][C] = Cenário

    hidecursor();

    Imprime(m);

	//// ToDo
	// Motor do Jogo
	
	return 0;
}
