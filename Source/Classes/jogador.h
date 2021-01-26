#pragma once
#include "imports.h"

class Jogador
{
private:
	string nome;
	int idade;
	int pontos;

public:
	Jogador();
	~Jogador();

	Jogador(string nomeP, int idadeP, int pontosP);
	Jogador(string nomeP, int idadeP);

	// Getters
	string getNome() { return nome; }
	int getIdade() { return idade; }
	int getPontos() { return pontos; }

	// Setters
	void setNome(string a) { nome = a; }
	void setIdade(int a) { idade = a; }
	void setPontos(int a) { pontos = a; }

	// Funções suporte
	bool existeJogador();
	void saveScore();
	void saveInfo();
	int* loadScore();
	void loadInfo(string a);
	void showScore();
	bool inArray(string* a, string b, int c);
	bool inArray(Palavra* a, string b, int c);
	string readPlayOpt(int c);
	bool tryWord(Tabuleiro tl, string a);

	// Sobrecargas
	inline void operator = (Jogador jg) {
		this->nome = jg.getNome();
		this->idade = jg.getIdade();
		this->pontos = jg.getPontos();
	};

};

