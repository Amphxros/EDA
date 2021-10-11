

#include <iostream>
#include <vector>
#include <iomanip>
#include<fstream>
#define DOMJUDGE 
int busca_impar(const std::vector<int>& v, int ini, int fin, int& impar) {
	if (fin - ini == 1) {
		if (v[ini] % 2 != 0) {
			impar = v[ini];
		}
		return impar;
	}
	else {
		int mit = (fin + ini) / 2;
		if (v[mit] % 2 != 0) {
			impar = v[mit];
		}
		else {
			int i= busca_impar(v, 0, mit, impar);
			int d= busca_impar(v, 0, mit +1 , impar);

			if (i != 0)
				return i;
			else if (d != 0)
				return d;
			else
				return 0;
			
		}
	}
		
	
}

bool resuelveCaso() {
	int n; 
	std::cin >> n;

	if (n <= 0) {
		return false;
	}
	else {
		std::vector<int> v(n);
		int impar = 0;
		for (int i = 0; i < n; i++) {
			int c;
			std::cin >> c;
			v[i] = c;
		}

		std::cout << busca_impar(v, 0, n, impar) << "\n";
		return true;
	}
}
int main() {
	// Para la entrada por fichero.
   // Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}