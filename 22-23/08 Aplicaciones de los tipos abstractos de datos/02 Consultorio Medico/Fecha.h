#pragma once
#include <iostream>

class Fecha
{
public:
	Fecha(int d, int h, int m) :
		dia(d), hora(h), min(m) {}
	~Fecha() {}

	void print() const {
		if (hora == 0) {
			std::cout << "00";
		}
		else if (hora < 10) {
			std::cout << "0" << hora;
		}
		else {
			std::cout << hora;
		}

		std::cout << ":";

		if (min == 0) {
			std::cout << "00";
		}
		else if (min < 10) {
			std::cout << "0" << min;
		}
		else {
			std::cout << min;
		}
	}
	
	int getDia() const { return dia; };
	int getHora() const { return hora; };
	int getMin() const { return min; };


	bool operator < (const Fecha& f)const {
		if (dia < f.dia) {
			return true;
		}
		else if (dia == f.dia) {
			if (hora < f.hora) {
				return true;
			}
			else if (hora == f.hora) {
				if (min < f.min) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

private:
	int dia;
	int hora;
	int min;
};

