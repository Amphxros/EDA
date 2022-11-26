#include "Fecha.h"
#include <iostream>
Fecha::Fecha(int d, int h, int m):
	dia(d), hora(h), min(m)
{
}

Fecha::~Fecha()
{
}

void Fecha::print()const 
{
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
