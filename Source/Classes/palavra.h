#pragma once
#include "imports.h"

class Palavra
{
private:
	string orientacao;
	string estado;
	Ponto ponto;
	Letra vetLetras[30];
	int nLetras;

public:
	Palavra();
	~Palavra();

	Palavra(string orientacao, string estado, Ponto ponto, string vetLetras);
	Palavra(string orientacao, string estado, Ponto ponto, Letra *vetLetras);



	// Getters
	string getOrientacao() {
		return orientacao;
	};

	string getEstado() {
		return estado;
	};

	Ponto getPonto() {
		return ponto;
	};

	Letra* getVetLetras() {
		return vetLetras;
	};

	string getVetLetrasStr() {
		string aux;
		aux.resize(nLetras);
		for (int i = 0; i < nLetras; i++) {
			aux[i] = vetLetras[i].getLetra();
		}
		return aux;
	};

	int getNLetras() {
		return nLetras;
	};



	// Setters
	void setOrientacao(string a) {
		orientacao = a;
	};

	void setEstado(string a) {
		estado = a;
	};

	void setPonto(Ponto a) {
		ponto = a;
	};

	void setVetLetras(Letra* a, int A) {
		for (int i = 0; i < 30; i++) {
			vetLetras[i] = a[i];
		}
		nLetras = A;
	};

	void setVetLetrasStr(string a) {
		for (int i = 0; i < a.size(); i++) {
			vetLetras[i] = a[i];
		}
		nLetras = a.size();
	};

	void setNLetras(int a) {
		nLetras = a;
	};

	bool equal(Palavra pl);
	bool equalStr(string a);



	// Sobrecargas
	inline void operator = (Palavra pl) {
		this->estado = pl.getEstado();
		this->nLetras = pl.getNLetras();
		this->orientacao = pl.getOrientacao();
		this->ponto = pl.getPonto();
		for (int i = 0; i < 30; i++) {
			this->vetLetras[i] = pl.getVetLetras()[i];
		}
	};

	inline void operator = (string a) {
		for (int i = 0; i < a.size(); i++) {
			this->vetLetras[i] = a[i];
		}
	};

	inline bool operator == (Palavra pl) {
		return equal(pl);
	};

	inline bool operator == (string a) {
		return equalStr(a);
	};

	inline bool operator != (Palavra pl) {
		return !equal(pl);
	};

	inline bool operator != (string a) {
		return !equalStr(a);
	};

	friend ostream& operator << (ostream& os, const Palavra& pl);
	/*friend istream& operator>>(istream& input, Palavra& pl) {
		string a;
		input >> a;
		pl.setVetLetrasStr(a);
		return input;

	}*/
	
};