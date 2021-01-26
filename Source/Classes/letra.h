#pragma once
#pragma once
#include "imports.h"

class Letra
{
private:
	char letra;
	Ponto ponto;
	int codASCII;
	string tipo;

	char generateChar();

	int getASCIIFromChar(char a);

	string readType(char a);

public:

	// Constructors
	Letra(char let, Ponto point);

	Letra(Ponto point);

	Letra(char let);

	Letra();


	// Getters
	inline char getLetra() {
		return letra;
	};

	inline string getTipo() {
		return tipo;
	};

	inline int getAsc() {
		return codASCII;
	};

	inline Ponto getPonto() {
		return ponto;
	};


	// Setters
	inline void setLetra(char l) {
		letra = l;
	};

	inline void setTipo(string t) {
		tipo = t;
	};

	inline void setAsc(int as) {
		codASCII = as;
	};

	inline void setPonto(Ponto p) {
		ponto = p;
	};

	
	void setAll(char letra, Ponto pont);


	bool equal(Letra letre);

	// Sobrecargas
	inline bool operator == (Letra letre) {
		return equal(letre);
	};

	inline bool operator != (Letra letre) {
		return !equal(letre);
	};

	inline void operator = (Letra le) {
		letra = le.getLetra();
		ponto = le.getPonto();
		codASCII = le.getAsc();
		tipo = le.getTipo();
	};

	inline void operator = (char a) {
		letra = a;
		codASCII = getASCIIFromChar(a);
		tipo = readType(a);
	};

	~Letra() {

	};

	void Save(ofstream &os);
	void Read(ifstream &is);

	friend ostream& operator << (ostream& os, const Letra& lt);

	friend istream& operator>>(istream& input, Letra& lt) {

		input >> lt.letra;
		return input;

	}
};