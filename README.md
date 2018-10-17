# TrabalhoM2
Jogo da Formiguinha Operária

UNIVALI
ESCOLA DO MAR, CIÊNCIA E TECNOLOGIA
CIÊNCIA DA COMPUTAÇÃO
DISCIPLINA: ALGORITMOS II

Jogo da Formiguinha Operária

O trabalho consiste no desenvolvimento de um jogo em que uma formiguinha tenta levar os alimentos que estão em um armazém que está desmoronando para um local seguro antes que seja tarde demais.

REGRAS DO JOGO

O jogo consiste de uma formiga, com aparência a ser escolhida pelos desenvolvedores, cujo objetivo é buscar os alimentos que estão no armazém comprometido e leva-los para um dos outros armazéns das formigas. Enquanto a formiga luta para levar os alimentos em segurança ocorrem terremotos que fazem com que o cenário mude. Além disso a formiga precisa estar atenta para não jogar um alimento grande em cima de um pequeno, pois isso estragaria aquele alimento na hora e as formigas morreriam de fome no inverno. O jogo termina quando a formiguinha conseguir levar todos os alimentos para um dos armazéns livres.

O jogo deve seguir as regras abaixo:

* O jogo deve possuir pelo menos 3 labirintos que serão escolhidos aleatoriamente quando ocorrer um terremoto. (exemplo de labirinto no material de apoio)

* A formiguinha deve ser capaz de se movimentar pelas áreas livres, sem ser capaz de atravessar paredes.

* A formiga deve ser capaz de buscar e soltar alimentos nos armazéns. (que são, as torres de Hanoi)

* Quando a formiga estiver carregando um alimento sua aparência deve mudar.

Formiga Formiga carregando alimento

* O jogo deve ser capaz de contar a passagem do tempo.

o A cada tempo X deve ocorrer um terremoto que irá modificar o cenário. Observe que a formiguinha é muito esperta e não fica soterrada quando ocorre um terremoto. (isso quer dizer que ela deve ficar em uma posição livre no novo cenário).

o Quando a formiguinha concluir sua tarefa o jogo deve encerrar e o tempo que a formiguinha levou para transportar os alimentos deve ser exibido.

* O cenário, os armazéns e a formiguinha devem estar sempre visíveis.

* Os Armazéns devem seguir as regras apresentadas no Capítulo Torre de Hanoi.

TORRE DE HANOI

A Torre de Hanói, jogo criado por os matemáticos franceses E. Lucas e De Parville em 1894, consiste num conjunto de três pinos fixos numa base comum. Num dos pinos, 7 peças furadas estão enfiadas em ordem decrescente de tamanho, de baixo para cima. O desafio consiste em transportar uma a uma essas sete peças para um dos outros pinos em um menor número possível de movimentos. Não é permitido, em nenhuma etapa, que uma peça fique pousada sobre outra de menor tamanho.

Na criação, foi apresentado como se fosse trazido de um mosteiro vietnamita, onde os monges passassem o tempo todo movendo 40 discos gigantes de bronze. A lenda afirmava que o último movimento seria o sinal do fim do mundo.

Definição do Problema:

O problema da Torre de Hanói envolve um ambiente formado por uma base, contendo 3 pinos, onde, m um deles, há uma pilha de discos furados no meio e de diâmetros diferentes ordenados de forma que o disco maior esteja em baixo e o menor esteja em cima, formando assim uma torre, conforme a figura a seguir:

O problema consiste em transferir a torre de um pino a outro obedecendo as seguintes restrições:

a) Só é possível movimentar-se um disco por vez para qualquer pino;

b) Um disco maior nunca poderá ser colocado sobre um menor; e

c) A solução deverá ser encontrada com o menor número de passos possível.

Deve ser implementado em C++ o jogo das Torres de Hanói para ser jogado por um usuário (mostrar os movimentos das torres no jogo).

Algumas regras:

* Utilize sub-rotinas e passagem de parâmetros.

* Utilize recursividade

* Não utilize variáveis globais.

Leia com atenção o que foi solicitado, desenvolva os algoritmos em C++ até a data marcada para entrega no Material Didático. Entregar o código fonte completo (com projeto).

Critérios de Avaliação:

1. Organização e clareza do código = 20% da nota.

2. Identificação dos autores e Comentários pertinentes e oportunos no código = 10% da nota.

3. Funcionamento correto conforme a especificação = 50% da nota.

4. Recursos da linguagem utilizados = 20% da nota
