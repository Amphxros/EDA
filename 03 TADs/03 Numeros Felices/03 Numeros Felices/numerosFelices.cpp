
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>

bool esFeliz(int n, std::set<int> set) {
	
	//caso base
	if (n == 1)
		return true;
	//caso recursivo
	else {
		int aux = n;
		int k = 0;
		//sumamos cada cifra en k
		while (aux >= 0) { // partimos cada nº y lo elevamos al cuadrado
			int m = (aux % 10)*(aux % 10);
			k += m;
			aux /= 10;
			if (aux == 0)
				aux = -1;
		}

		auto it = set.find(k);
		set.insert(k);
		std::cout << k << " ";
		if (it != set.end()) { // si es != -> existe otro nº k en el set -> no es un nº feliz ya que nunca llegará a 1
			return false;
		}
		else {
			if (k <= 1) {
				return k == 1;
			}
			else {
				return esFeliz(k, set);
			}
		}
	}
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin) {
		return false;
	}
	else {
		std::set<int>s;
		std::cout << n << " ";
		if (esFeliz(n,s)) {
			std::cout << 1<<"\n";
		}
		else {
			std::cout << 0 << "\n";
		}
		return true;
	}
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif

	return 0;
}