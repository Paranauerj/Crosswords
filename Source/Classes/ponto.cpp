#include "imports.h"
#include "ponto.h"

Ponto::Ponto() {
	x = 0;
	y = 0;
}

Ponto::Ponto(int m_x, int m_y) {
	x = m_x;
	y = m_y;
};

Ponto::~Ponto() {

};

bool Ponto::equal(Ponto ponto) {
	bool retorno = false;
	if (x == ponto.getX() && y == ponto.getY()) {
		retorno = true;
	}
	else {
		retorno = false;
	}

	return retorno;
};

bool Ponto::IsValid(void) {
	bool retorno = false;

	if (x >= 0 && y >= 0) {
		retorno = true;
	}
	else {
		retorno = false;
	}

	return retorno;
};

void Ponto::ShowPonto() {
	cout << "X: " << x << "  Y: " << y;
};

void Ponto::Save(ofstream &os) {

};

void Ponto::Read(ifstream& is) {

};