#pragma once
#include "imports.h"

class Ponto
{
private:
	int x; //1 -- 3
	int y; //1 -- 3

public:

	// Constructors
	Ponto();
	Ponto(int m_x, int m_y);

	// Setters
	inline bool Set_x(int m_x) {
		x = m_x;
	};

	inline bool Set_y(int m_y) {
		y = m_y;
	};

	inline void Set_P(int m_x, int m_y) {
		x = m_x;
		y = m_y;
	};

	// Getters
	inline int getX(void) const { return x; }
	inline int getY(void) const { return y; }
	

	bool Ask2Set_P(void);

	bool equal(Ponto ponto);
	bool IsValid(void);

	void ShowPonto();

	// Sobrecarga
	inline bool operator == (Ponto ponto) {
		return equal(ponto);
	};

	inline bool operator != (Ponto ponto) {
		return !equal(ponto);
	};

	inline void operator = (Ponto pt) {
		x = pt.getX();
		y = pt.getY();
	};

	// IO Files
	void Save(ofstream &os);
	void Read(ifstream &is);

	~Ponto();

};