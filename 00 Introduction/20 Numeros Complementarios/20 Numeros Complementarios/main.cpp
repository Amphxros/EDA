#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <math.h>  
#include <cmath>

void result() {
	int num;
	std::cin >> num;

	int comp=0;
	int inv=0;
	std::vector<int> v;
	int aux = num;
	//partimos el nº coste O(m) donde m= nº de cifras que tiene num
	while (aux > 0) {
		v.push_back(aux % 10);
		aux /= 10;
	}

	//lo pasamos del vector al comp -> coste= O(m) donde m= nº de cifras que tiene num
	for (int i = 0; i < v.size(); i++) {
		int j = v[v.size() - 1 - i];
		comp += std::abs((9-v[i]) *pow(10,i));
		inv += std::abs((9 -j) * pow(10, i));
	}

	std::cout << comp << " " << inv << std::endl;

}

int main() {
	// Para la entrada por fichero.
   // Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream w("datos.txt");
	auto cinbuf = std::cin.rdbuf(w.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		result();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}