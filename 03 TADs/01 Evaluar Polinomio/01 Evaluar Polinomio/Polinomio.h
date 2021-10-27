#pragma once
#include <vector>
#include <math.h>
class Polinomio
{
public:
	Polinomio() {
		p = std::vector<int>(9, 0);
	}
	~Polinomio() {

	}
	void add(int b, int exp) {
		if (b != 0 || exp != 0)
			p[exp] += b;
	}
	int calculate(int val) {
		int total= 0;

		for(int i :p) {
			total += i* pow(val,i);
		}
		return total;


	}
private:
	std::vector<int> p;
};

