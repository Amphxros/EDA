

#include <iostream>
#include <vector>
#include <iomanip>
#include<fstream>
//#define DOMJUDGE

int busca_impar(const std::vector<int>& v, int ini, int fin) {
	int impar = 0;
	if (fin - ini == 1) {	//asumimos que existe un nº impar
		if (v[ini] % 2 != 0)
			impar = v[ini];
		else
			impar = v[fin];
	}

	else {
		int mit = (fin + ini) / 2;
		if (v[mit] % 2 != 0)
			impar = v[mit];
		else {
			int impIzq = busca_impar(v, ini, mit);
			int impDer = busca_impar(v, mit,fin);

			if (impIzq % 2 != 0)
				impar = impIzq;
			else
				impar = impDer;

		}
	}
	return impar;
			
}

bool resuelveCaso() {
	int n; 
	std::cin >> n;

	if (n <= 0) {
		return false;
	}
	else {
		std::vector<int> v(n);
		for (int i = 0; i < n; i++) {
			int c;
			std::cin >> c;
			v[i] = c;
		}

		std::cout << busca_impar(v, 0, n-1) << "\n";
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