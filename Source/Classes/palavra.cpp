#include "imports.h"
#include "ponto.h"
#include "letra.h"
#include "palavra.h"

Palavra::Palavra() {
	nLetras = 0;
}

Palavra::~Palavra() {

}

Palavra::Palavra(string orientacaoP, string estadoP, Ponto pontoP, string vetLetrasP) {
	this->orientacao = orientacaoP;
	this->estado = estadoP;
	this->ponto = pontoP;
	this->nLetras = vetLetrasP.size();

	for (int i = 0; i <= nLetras; i++) {
		Letra aux(vetLetrasP[i]);
		this->vetLetras[i] = aux;
		if (this->orientacao == "horizontal") {
			Ponto Pteste(pontoP.getX(), pontoP.getY() + i);
			this->vetLetras[i].setPonto(Pteste);
		}
		else {
			Ponto Pteste(pontoP.getX() + 1, pontoP.getY());
			this->vetLetras[i].setPonto(Pteste);
		}
	
	}

}

Palavra::Palavra(string orientacaoP, string estadoP, Ponto pontoP, Letra *vetLetrasP) {
	this->orientacao = orientacaoP;
	this->estado = estadoP;
	this->ponto = pontoP;
	int cont = 0;
	
	while(vetLetrasP[cont] != 'Y'){
		this->vetLetras[cont] = vetLetrasP[cont];
		if (this->orientacao == "horizontal") {
			Ponto Pteste(pontoP.getX(), pontoP.getY() + cont);
			this->vetLetras[cont].setPonto(Pteste);
		}
		else {
			Ponto Pteste(pontoP.getX() + 1, pontoP.getY());
			this->vetLetras[cont].setPonto(Pteste);
		}
		cont++;
	}

	this->nLetras = cont;

}

bool Palavra::equal(Palavra pl) {
	bool retorno = false;

	if (this->estado == pl.getEstado() && this->nLetras == pl.getNLetras() && this->orientacao == pl.getOrientacao() && this->ponto == pl.getPonto()) {
		retorno = true;
		for (int i = 0; i < 30; i++) {
			if (this->vetLetras[i] != pl.getVetLetras()[i]) {
				retorno = false;
			}
		}
	}
	else {
		retorno = false;
	}

	return retorno;

}

/*

	Se for pra pegar só a palavra, sem ligar pra posição e tal:

	bool Palavra::equal(Palavra pl) {
	bool retorno = true;

	for (int i = 0; i < 30; i++) {
		if (this->vetLetras[i] != pl.getVetLetras()[i]) {
			retorno = false;
		}
	}

		return retorno;

	}

*/

bool Palavra::equalStr(string a) {
	bool retorno = true;
	if (this->nLetras != a.size()) {
		retorno = false;
	}
	else {
		for (int i = 0; i < a.size(); i++) {
			if (this->vetLetras[i] != a[i]) {
				retorno = false;
			}
		}
	}
	
	return retorno;

}

ostream& operator << (ostream& os, const Palavra& pl)
{
	for (int i = 0; i < pl.nLetras; i++) {
		os << pl.vetLetras[i];
	}
	return os;
}

/*istream& operator>> (istream& is, Palavra& pl)
{

	is >> str.

	return is;
}*/