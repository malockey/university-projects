#include <iostream>
#include <time.h>
#include <string>
using namespace std;

struct Time {
	string nome;
	int pote, forca, pontos = 0;
};

struct Grupo {
	char nome;
	Time times[4];
};

struct Jogo {
	Time times[2];
	int gols[2], resultado;
};

struct Copa {
	Time times[32];
	Grupo grupos[8];
};

void SortearGrupos(Copa &copa) {
	
	// recebe a variável 'Copa' por parâmetro e sorteia os 32 times para os 8 grupos.

	int indices[32]; // guarda os índices aleatórios
	bool naoOcupado;
	for (int i = 0; i < 32; i++) {
		int aleatorio;
		aleatorio = rand() % 32;
		naoOcupado = true;
		for (int j = 0; j < 32; j++) {
			if (aleatorio != indices[j] && naoOcupado) { // se número aleatório já não foi armazenado
				naoOcupado = true;
			}
			else {
				naoOcupado = false;
			}
		}
		if (naoOcupado) {
			indices[i] = aleatorio; // guardar número aleatório
		}
		else { // repetir o i caso o número aleatório seja o mesmo
			i--;
		}
	}
	int vezes = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			copa.grupos[i].times[j] = copa.times[indices[j + 4 * vezes]];
			copa.grupos[i].times[j].pote = j + 1;
			// Imprime os potes dos times
			//cout << copa.grupos[i].times[j].nome << " " << copa.grupos[i].times[j].pote << endl;
		}
		vezes++;
	}

}

Jogo SimularJogo(Time t1, Time t2) {
	
	// recebe dois times como parâmetros e retorna uma variável do tipo 'Jogo' preenchida, com o número de gols e o resultado.

	Jogo jogo;
	jogo.times[0] = t1;
	jogo.times[1] = t2;

	for (int i = 0; i < 2; i++) {
		jogo.gols[i] = rand() % 5;
	}
	if (jogo.gols[0] > jogo.gols[1]) {
		jogo.resultado = 1;
	}
	else if (jogo.gols[0] < jogo.gols[1]) {
		jogo.resultado = 2;
	}
	else {
		jogo.resultado = 0;
	}

	return jogo;
}

void SimularGrupo(Grupo &grupo) {
	
	// pega um grupo e simula as três rodadas dos grupos.
	
	int auxiliar = 0;
	for (int i = 1; i < 4; i++) {
		Jogo jogo = SimularJogo(grupo.times[0 + auxiliar], grupo.times[i]);
		if (jogo.resultado == 1) {
			grupo.times[0 + auxiliar].pontos += 3;
		}
		else if (jogo.resultado == 2) {
			grupo.times[i].pontos += 3;
		}
		else {
			grupo.times[0 + auxiliar].pontos += 1;
			grupo.times[i].pontos += 1;
		}
		// Imprime os gols do jogo
		// cout << jogo.times[0].nome << " " << jogo.gols[0] << "   -   " << jogo.gols[1] << " " << jogo.times[1].nome << endl;
		if (i == 3 && auxiliar != 3) {
			i = 1 + auxiliar;
			auxiliar++;
		}
	}
	//Imprime os pontos do time
	/* cout << grupo.nome << endl;
	for (int i = 0; i < 4; i++) {
		cout << grupo.times[i].nome << " " << grupo.times[i].pontos << endl;
	}
	cout << endl; */
}

void SimularPlayoffs(Grupo grupos[]) {
	
	// encontrar os dois times com maior quantidade de pontos de cada grupo e imprimir.

	for (int i = 0; i < 8; i++) {
		Time maisPontos[2];
		maisPontos[0] = grupos[i].times[0];
		maisPontos[1] = grupos[i].times[1];
		for (int j = 1; j < 4; j++) {
			if (maisPontos[0].pontos < grupos[i].times[j].pontos && maisPontos[1].nome != maisPontos[0].nome) {	
				maisPontos[1] = maisPontos[0];
				maisPontos[0] = grupos[i].times[j];
			}
			else if (maisPontos[1].pontos < grupos[i].times[j].pontos && maisPontos[1].nome != maisPontos[0].nome) {
					maisPontos[1] = grupos[i].times[j];
			}
		}
		 cout << endl << grupos[i].nome << endl << maisPontos[0].nome << " - " << maisPontos[0].pontos <<
			 endl << maisPontos[1].nome << " - " << maisPontos[1].pontos << endl;

	}
}

void SimularCopa(Copa &copa) {
	
	// recebe a 'copa' como parâmetro e gerencia as funções anteriores, sorteando os grupos, simulando estes grupos e depois os playoffs.

	for (int i = 0; i < 8; i++) {
		copa.grupos[i].nome = char(i + 65);
		// cout << copa.grupos[i].nome;
	}
	for (int i = 0; i < 32; i++) {
		if (i + 65 <= 90) {
			copa.times[i].nome = char(i + 65);
		}
		else {
			copa.times[i].nome = char(i + 71);
		}
		copa.times[i].forca = rand() % 101;
		// cout << copa.times[i].nome << " " << copa.times[i].forca << endl;
	}
	SortearGrupos(copa);
	for(int i = 0; i < 8; i++) {
		SimularGrupo(copa.grupos[i]);
	}
	SimularPlayoffs(copa.grupos);
}

int main() {
	srand(time(NULL));
	Copa copa;
	SimularCopa(copa);
}

// PARTE 1

// DESENVOLVIDO POR: Jonathan Meine, Mateus Silva e Nicolas Garcia.
