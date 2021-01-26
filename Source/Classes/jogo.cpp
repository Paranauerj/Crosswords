#include "imports.h"
#include "ponto.h"
#include "letra.h"
#include "palavra.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogo.h"

Jogo::Jogo() {
	
}

Jogo::~Jogo() {
	
}

int Jogo::getSizes() {
	bool loop = true;
	int resp, dimX, dimY;
	while (loop) {
		cout << "Digite o tamanho preferível:" << endl
			<< "1- 10 x 10" << endl
			<< "2- 12 x 12" << endl
			<< "3- 14 x 14" << endl
			<< "4- 16 x 16" << endl
			<< "5- 18 x 18" << endl
			<< "6- 20 x 20" << endl
			<< "7- 22 x 22" << endl
			<< "8- 24 x 24" << endl
			<< "9- 25 x 25" << endl;
		cin >> resp;
		if (resp < 1 || resp > 9) {
			cout << endl << "!! Entrada Invalida: Entrada Nao Listada !!" << endl;
			loop = true;
		}
		else {
			loop = false;
			if (resp == 1) {
				dimX = 10;
				dimY = 10;
			}
			if (resp == 2) {
				dimX = 12;
				dimY = 12;
			}
			if (resp == 3) {
				dimX = 14;
				dimY = 14;
			}
			if (resp == 4) {
				dimX = 16;
				dimY = 16;
			}
			if (resp == 5) {
				dimX = 18;
				dimY = 18;
			}
			if (resp == 6) {
				dimX = 20;
				dimY = 20;
			}
			if (resp == 7) {
				dimX = 22;
				dimY = 22;
			}
			if (resp == 8) {
				dimX = 24;
				dimY = 24;
			}
			if (resp == 9) {
				dimX = 25;
				dimY = 25;
			}
			
			Tabuleiro tt(dimX, dimY);
			this->tabuleiro = tt;

			return dimX;
		}
	}
}

void Jogo::getInfo() {
	bool loop = true;
	string nome;
	int age;
	while (loop) {
		cout << "Escreva seu nome: " << endl;
		cin.ignore(256, '\n');
		getline(cin, nome);
		cout <<  "Escreva sua idade: " << endl;
		cin >> age;

		if (nome.size() > 30) {
			cout << endl << "!! Entrada Invalida: Nome Muito Grande !!" << endl;
			loop = true;
		}
		else{
			loop = false;
			Jogador beta(nome, age);
			this->jogador = beta;
		}
	}
}

bool Jogo::endGame() {
	return false;
}

int Jogo::menu() {
	bool loop = true;
	int res;
	while (loop) {
		cout << "		Menu Principal" << endl
			<< "1- Novo Jogo" << endl
			<< "2- Carregar Jogo (em desenvolvimento)" << endl
			<< "3- Sair do Jogo" << endl;
		cin >> res;
		if (res < 1 || res > 3) {
			cout << endl << "!! Entrada Invalida: Nome Muito Grande !!" << endl;
		}
		else {
			loop = false;
			this->aux = res;
			return res;
		}
	}
}


void Jogo::clrScr() {
	system("CLS");
}

void Jogo::pause() {
	system("PAUSE");
}