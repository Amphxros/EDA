//VJ 50 AMPARO RUBIO BELLON

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include "Horas.h"

bool resuelveCaso() {
	int nHoras, nCasos;
	std::cin >> nHoras >> nCasos;
	if (nHoras <= 0 && nCasos <= 0) {
		return false;
	}
	else {
		std::vector<Horas> h(nHoras);
		std::vector<Horas> c(nCasos);

		for (int i = 0; i < nHoras; i++) {
			std::cin >> h[i];
		}

		for (int i = 0; i < nCasos; i++) {
			std::cin >> c[i];
		}

		for (int i = 0; i < nCasos; i++) {
			if (c[i].isCorrect()) {
				auto p = std::lower_bound(h.begin(), h.end(), c[i]);

				if (p == h.end()) {
					std::cout << "NO" << "\n";
				}
				else {
					std::cout << *p << "\n";
				}
			}
			else {
				std::cout << "ERROR" << "\n";
			}
		}
		std::cout << "---" << "\n";

		return true;
	}
}

//#define DOMJUDGE
int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	// Resolvemos
	while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}