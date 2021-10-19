
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esFeliz(int n) {
	
	//sumamos cada cifra
		int aux = n;
		int k = 0;
		while (aux >= 0) {
			int m = std::powf(aux % 10,2);
			k += m;
			aux /= 10;
			if (aux == 0)
				aux = -1;
		}
	
		std::cout << k << " ";

		if (k <= 1) {
			
			return k==1;
		}
		else {
			return esFeliz(k);
		}

	

		

	
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n < 0)
		return false;
	else {
		if (esFeliz(n)) {
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