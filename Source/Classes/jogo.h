#pragma once
#include "imports.h"

class Jogo
{
private:
	Jogador jogador;
	Tabuleiro tabuleiro;
	int aux;

public:
	Jogo();
	~Jogo();
	// Jogo(string nome, int idade, int dimX, int dimY, string mode);

	// Getters
	Jogador getJogador() { return jogador; }
	Tabuleiro getTabuleiro() { return tabuleiro; }

	// Setters
	void setJogador(Jogador a) { jogador = a; }
	void setTabuleiro(Tabuleiro a) { tabuleiro = a; }

	// Funções suporte
	int getSizes();
	void getInfo();
	int menu();
	bool endGame();
	void clrScr();
	void pause();

	// Sobrecargas
	inline void operator = (Jogo jg) {
		this->jogador = jg.getJogador();
		this->tabuleiro = jg.getTabuleiro();
	};
};

