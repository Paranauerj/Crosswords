#include "imports.h"
#include "ponto.h"
#include "letra.h"

Letra::Letra() {
	letra = 'Y';
	codASCII = getASCIIFromChar(letra);
	this->tipo = readType(letra);
}

char Letra::generateChar() {
	char retorno;
	int aux = rand() % 2;
	if (aux == 0) {
		retorno = 'A' + (rand() % 26);
	}
	else {
		retorno = 'a' + (rand() % 26);
	}

	return retorno;
}

int Letra::getASCIIFromChar(char a) {
	int converted = (int)a;
	return converted;
}

Letra::Letra(char let) {
	letra = let;
	codASCII = getASCIIFromChar(letra);
	tipo = readType(letra);
}

Letra::Letra(Ponto point) {
	ponto = point;
	letra = generateChar();
	codASCII = getASCIIFromChar(letra);
	tipo = readType(letra);
};

Letra::Letra(char let, Ponto point) {
	ponto = point;
	letra = let;
	ponto.Set_P(point.getX(), point.getY());
	codASCII = getASCIIFromChar(let);
	tipo = readType(letra);
};

void Letra::setAll(char let, Ponto point) {
	ponto = point;
	letra = let;
	ponto.Set_P(point.getX(), point.getY());
	codASCII = getASCIIFromChar(let);
	tipo = readType(letra);
};


void Letra::Save(ofstream& os) {

}
void Letra::Read(ifstream& is) {

}

bool Letra::equal(Letra letre) {
	bool retorno = false;
	if (letre.getLetra() == letra) {
		retorno = true;
	}
	return retorno;
}

string Letra::readType(char a) {
	string retorno;
	codASCII = getASCIIFromChar(a);
	if (codASCII >= 65 && codASCII <= 90) {
		retorno = "maiusculo";
	}
	else {
		retorno = "minusculo";
	}
	return retorno;
}

ostream& operator << (ostream& os, const Letra& lt)
{
	os << lt.letra;

	return os;
}