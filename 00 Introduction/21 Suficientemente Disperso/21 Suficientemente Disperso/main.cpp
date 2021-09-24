// Amparo Rubio Bellon
// VJ50


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<math.h>

// función que resuelve el problema
bool resolver(std::vector<int> datos, int k,int ini, int fin) {

	if ( fin - ini == 1) {
		return ((datos[fin] - datos[ini] >= k) || (datos[ini] - datos[fin]>=k));
	}
	else {
		if (datos[fin] - datos[ini] >= k) {
			int mit = (ini + fin) / 2;
			//std::cout << datos[mit] << " ";
			return resolver(datos, k, mit + 1, fin)&& resolver(datos, k, ini, mit);
		}
		return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int n, k;
	std::cin >> n;
	std::cin >> k;
	
	std::vector<int> datos(n);
	for (int i = 0; i < n; i++) {
		int j;
		std::cin >> j;
		datos.push_back(j);
	}
	// escribir sol

	if (resolver(datos, k, 0, n)) {
		std::cout << "SI" << "\n";
	}
	else {
		std::cout << "NO" << "\n";
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 
//
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif

	return 0;
}