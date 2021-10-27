#include "Polinomio.h"
#include<vector>
#include<iomanip>
#include<iostream>
#include<fstream>

bool resuelveCaso() {
	int b, exp;
	std::cin >> b;
	if (!std::cin)
		return false;
	else {
		Polinomio p;
		std::cin >> exp;
		while (b != 0 || exp != 0) {
			p.add(b, exp);
			std::cin >>b>> exp;
		}

		int n = 0;
		std::cin >> n;
		if (!std::cin || n <= 0) {
			return false;
		}
		else {
			std::vector<int> val(n);
			for (int i = 0; i < n; i++) {
				std::cin >> val[i];
			}
			for (int i = 0; i < n; i++) {
				std::cout << p.calculate(val[i]) << " ";
			}
			std::cout << "\n";

		return true;
		}
	}
}

int main() {
	// Para la entrada por fichero.
   // Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif

	return 0;
}