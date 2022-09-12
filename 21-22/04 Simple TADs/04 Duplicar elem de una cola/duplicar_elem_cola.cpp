// VJ50 AMPARO RUBIO BELLON
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>


void duplicate(std::queue<int>& queue) {
	
	int j = queue.size();
	for (int i = 0; i < j; i++) {
		int k = queue.front();
		queue.pop();
		queue.push(k);
		queue.push(k);
		std::cout << k << " " << k << " ";
	}
	std::cout << "\n";
	


}

bool resuelveCaso() {
	std::queue<int> mQueue;
	int n;
	std::cin >> n;
	if (!std::cin) {
		return false;
	}
	else {
		while (n != 0) {
			mQueue.push(n);
			std::cin >> n;
		}
		duplicate(mQueue);


		return true;
	}
}

#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}