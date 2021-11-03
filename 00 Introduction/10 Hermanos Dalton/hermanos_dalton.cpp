#include <iostream>
#include <vector>
#include <fstream>

bool resuelve( const std::vector<int>& v) {
	
	int cont = 0, desc=0;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] < v[i + 1]) {
			cont++;
		}
		else if (v[i] > v[i + 1]) {
			desc++;
		}
	}
	
	
	return cont == v.size() - 1 || desc == v.size()-1;
	
}

bool result() {
	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	if (n <= 0) {
		return false;
	}
	else {
		//introducimos los datos en 1 vector O(n) donde n = nº de hermanos= tamaño del vector
		for (int i = 0; i < n; i++) {
			int d;
			std::cin >> d;
			vec[i] = d;
		}

		//coste total O(n)
		if (resuelve(vec)) {
			std::cout << "DALTON" << "\n";
		}

		else {
			std::cout << "DESCONOCIDOS" << "\n";
		}
		return true;
	}
}

int main() {
	
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


	while (result());


	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif

	return 0;


}