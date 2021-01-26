#include "imports.h"
#include "ponto.h"
#include "letra.h"
#include "palavra.h"
#include "tabuleiro.h"
#include "jogador.h"

Jogador::Jogador() {
	this->nome = "a";
	this->idade = 0;
	this->pontos = 0;
}

Jogador::~Jogador() {

}

Jogador::Jogador(string nomeP, int idadeP, int pontosP) {
	this->nome = nomeP;
	this->idade = idadeP;
	this->pontos = pontosP;
}

Jogador::Jogador(string nomeP, int idadeP) {
	this->nome = nomeP;
	this->idade = idadeP;
	this->pontos = 0;
}

bool Jogador::existeJogador() {
	char caminho[80];

	strcpy_s(caminho, "./Saves/");
	strcat_s(caminho, this->nome.c_str());
	int check = _mkdir(caminho);

	if (check == -1) {
		return true;
	}
	else {
		return false;
	}
}

void Jogador::saveScore() {
	char caminho[80];
	char caminhoScore[90];
	strcpy_s(caminho, "./Saves/");
	strcat_s(caminho, this->nome.c_str());

	int check = _mkdir(caminho);

	if (check == -1) {
		// Já existe
	}
	else {
		// Nao existe
	}

	strcpy_s(caminhoScore, caminho);
	strcat_s(caminhoScore, "/");
	strcat_s(caminhoScore, "score.db");
	ofstream os	{caminhoScore, std::ios_base::app };

	os << this->pontos << endl;

	os.close();

}

int* Jogador::loadScore() {
	int* scores;
	int aux = 1;
	string laux;
	char caminho[80];
	char caminhoScore[90];
	strcpy_s(caminho, "./Saves/");
	strcat_s(caminho, this->nome.c_str());

	int check = _mkdir(caminho);

	if (check == -1) {
		strcpy_s(caminhoScore, caminho);
		strcat_s(caminhoScore, "/");
		strcat_s(caminhoScore, "score.db");
		ifstream is;
		is.open(caminhoScore);
		while (getline(is, laux)) {
			aux++;
			// cout << aux << endl;
		}
		is.close();

		scores = new int(aux);
		scores[0] = aux;

		is.open(caminhoScore);
		for(int j = 1; j < aux; j++) {
			is >> scores[j];
		}
		is.close();

		return scores;
	}
	else {
		// Nao existe
	}

}

void Jogador::showScore() {
	int b = loadScore()[0];
	int* a;
	a = new int(b);
	a = loadScore();
	for (int i = 1; i < b; i++) {
		cout << "Pontuacao " << i << " : " << a[i] << endl;
	}
}

void Jogador::saveInfo() {
	char caminho[80];
	char caminhoInfo[90];
	strcpy_s(caminho, "./Saves/");
	strcat_s(caminho, this->nome.c_str());

	int check = _mkdir(caminho);

	if (check == -1) {
		// Já existe
	}
	else {
		// Nao existe
	}

	strcpy_s(caminhoInfo, caminho);
	strcat_s(caminhoInfo, "/");
	strcat_s(caminhoInfo, "info.db");
	ofstream os;
	os.open(caminhoInfo);

	os << this->nome << endl << this->idade << endl << this->pontos;

	os.close();
}

void Jogador::loadInfo(string a) {
	char caminho[80];
	char caminhoInfo[90];
	strcpy_s(caminho, "./Saves/");
	strcat_s(caminho, a.c_str());

	int check = _mkdir(caminho);

	if (check == -1) {
		strcpy_s(caminhoInfo, caminho);
		strcat_s(caminhoInfo, "/");
		strcat_s(caminhoInfo, "info.db");
		ifstream is;
		is.open(caminhoInfo);
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				getline(is, this->nome);
			}
			else {
				if (i == 1) {
					is >> this->idade;
				}
				else {
					is >> this->pontos;
				}
			}
		}
		
		is.close();

	}
	else {
		// Nao existe
	}

}

bool Jogador::inArray(string* arr, string a, int n) {
	bool retorno = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] == a) {
			retorno = true;
		}
	}
	return retorno;
}

bool Jogador::inArray(Palavra* arr, string a, int n) {
	bool retorno = false;
	for (int i = 0; i < n; i++) {
		if (arr[i].getVetLetrasStr() == a) {
			retorno = true;
		}
	}
	return retorno;
}

string Jogador::readPlayOpt(int c) {
	bool a = true;
	string b;
	cout << "Escreva a palavra do caca palavras ('sair' para sair): " << endl;
	if (c == 0) {
		cin.ignore(256, '\n');
		getline(cin, b);
	}
	else{
		getline(cin, b);
	}
	
	
	return b;
}

bool Jogador::tryWord(Tabuleiro tl, string a) {
	if (inArray(tl.getPalavras(), a, tl.getNPalavras())) {
		return true;
	}
	else {
		return false;
	}
}