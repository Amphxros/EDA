#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void imprimeSol(std::vector<int> sol, int n) {
	for (int i = 0; i < n; i++) {
		switch (sol[i]) {
		case 0:
			std::cout << "azul ";
			break;
		case 1:
			std::cout << "rojo ";
			break;
		default:
			std::cout << "verde ";
			break;
		}
	}
	std::cout << "\n";
}

void torresColores(std::vector<int>& sol, std::vector<int>& disp, int n, std::vector<int>&col,int k, bool result) {
	
	//probamos azul
	if (disp[0] > col[0]) {
		col[0]++;
		sol[k] = 0;
		if (k < n) {
			torresColores(sol, disp, n, col, k + 1, result);
		}
		else if (col[0] + col[2] < col[1]) {
			result = true;
			imprimeSol(sol, n);
		}
		col[0]--;
	}

	//probamos rojo

	if (disp[1] > col[1]) {
		col[1]++;
		sol[k] = 1;

		if (k < n) {
			torresColores(sol, disp, n, col, k + 1, result);
		}
		else if (col[0] + col[2] < col[1]) {
			result = true;
			imprimeSol(sol, n);
		}
		col[1]--;
	}

	//probamos verde

	if (disp[2] > col[2] && col[2] < col[0] && sol[k - 1] != 2) {
		col[2]++;
		sol[k] = 2;
		
		if (k < n) {
			torresColores(sol, disp, n, col, k + 1, result);
		}
		else if (col[0] + col[2] < col[1]) {
			result = true;
			imprimeSol(sol, n);
		}
		col[2]--;
	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n, r,g,b;
	std::cin >> n;
	if (n <= 0) {
		return false;
	}
	else {
		
		bool rst = false;
		std::cin >> b >> r >> g;
		std::vector<int> sol(n);
		std::vector<int> disp(r + g + b);
		std::vector<int> col(r + g + b);

		torresColores(sol, disp, n, col, 0, rst);

		return true;
	}
}
int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif



#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}