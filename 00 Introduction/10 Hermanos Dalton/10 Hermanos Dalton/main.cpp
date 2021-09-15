#include <iostream>
#include <vector>
#include <fstream>


void result() {
	int n;
	std::cin >> n;
	std::vector<int> vec(n);

	//introducimos los datos en 1 vector O(n) donde n = nº de hermanos= tamaño del vector
	for (int i = 0; i < n; i++) {
		int d;
		std::cin >> d;
		vec[i] = d;
	}


	int j = 1;

	bool crec = vec[j] > vec[j - 1];

	// O(n-1) donde n= nºhermanos 
	while ( j < n && ((crec && vec[j] > vec[j - 1]) || (!crec && vec[j] < vec[j - 1]))) {
		j++;   
	}
	j++;
	//constante en este caso
	if (j <= n) {
		std::cout << "DESCONOCIDOS" << std::endl;
	}
	else {
		std::cout << "DALTON" << std::endl;
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
	for (int i = 0; i < numCasos; ++i)
		result();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;


}