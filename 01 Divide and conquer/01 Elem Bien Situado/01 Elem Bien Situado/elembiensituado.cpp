// Amparo Rubio Bellon
// VJ50

#include <iostream>
#include <iomanip>
#include <fstream>

#include<vector>

// función que resuelve el problema
bool elemento_situado(const std::vector<int>& v, int ini, int fin) {

	if (fin - ini == 1) {
		return v[ini] == ini;
	}
	else {
		int mit = (ini + fin) / 2; //mitad

		//como está ordenado podemos comprobar por donde buscar

		if (v[mit] > mit) {		//si es mayor v[mit] buscamos por la derecha
			return  elemento_situado(v, mit, fin);
		}
		else if (v[mit] < mit) { // si es menor por la izquierda
			return elemento_situado(v, ini, mit);
		}
		else //si no se cumple que v[mit] == mit
			return true;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;

	std::vector<int> v(n);

	for (int i = 0; i < n; i++) {
		int c;
		std::cin >> c;
		v[i] = c;
	}

	// escribir sol
	if (elemento_situado(v, 0, n)) {
		std::cout << "SI" << "\n";
	}
	else {
		std::cout << "NO" << "\n";
	}

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}