// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>


int numSols = 0;
int diag_asc(int x, int y) { return x + y; } // o(1)
int diag_desc(int x, int y) { return x - y; } // o(1)

// o(1)
bool no_ataca(const int N, const int* sol, const int index, const bool* filas, const bool* diags_asc, const bool* diags_desc) {
	return !filas[sol[index]] && !diags_asc[diag_asc(index, sol[index])] && !diags_desc[diag_desc(index, sol[index]) + N - 1];
}

// o(1)
bool es_solucion(const int N, const int* sol, const int index, const bool* filas, const bool* diags_asc, const bool* diags_desc) {
	return index == N - 1 && no_ataca(N, sol, index, filas, diags_asc, diags_desc);
}

// o(1)
bool es_completable(const int N, const int* sol, const int index, const bool* filas, const bool* diags_asc, const bool* diags_desc) {
	return index < N&& no_ataca(N, sol, index, filas, diags_asc, diags_desc);
}

void desmarca(bool* arr, int ini, int fin) {
	for (int i = ini; i < fin; i++) arr[i] = false;
}

void vueltaAtras(const int& n, int* sol, int index, bool* filas, bool* diags_asc, bool* diags_desc) {
	for (int i = 0; i < n; i++) {
		sol[index] = i;
		//si es solucion --> aumentamos 
		if (es_solucion(n, sol, index, filas, diags_asc, diags_desc)) {
			numSols++;
		}
		//si no marcamos, llamamos al siguiente y desmarcamos
		else if (es_completable(n, sol, index, filas, diags_asc, diags_desc)) {
			
			//marca
			filas[i] = true;
			diags_asc[diag_asc(index, i)] = true;
			diags_desc[diag_desc(index, i) + n - 1] = true;
			
			//siguiente
			vueltaAtras(n, sol, index + 1, filas, diags_asc, diags_desc);
			
			//desmarca
			filas[i] = false;
			diags_asc[diag_asc(index, i)] = false;
			diags_desc[diag_desc(index, i) + n - 1] = false;
		}
	}
}


void resolver(const int N) {
	
	int* sol = new int[N]; //marca columnas
	bool* diags_asc = new bool[N * 2 - 1]; //marcas diagonales ascendentes
	bool* diags_desc = new bool[N * 2 - 1]; //marcas diagonales descendientes
	bool* filas = new bool[N]; //marcas filas
	//inicializamos a falso todo
	desmarca(diags_asc, 0, N * 2 - 1);  
	desmarca(diags_desc, 0, N * 2 - 1);
	desmarca(filas, 0, N);
	//empieza la recursion
	vueltaAtras(N, sol, 0, filas, diags_asc, diags_desc);
	delete[] sol;
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (n == 0) {
		std::cout << 0 << "\n";
		numSols = 0;
		return;
	}
	// escribir sol
	resolver(n);
	std::cout << numSols << "\n";
	numSols = 0;

}

#define DOMJUDGE
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
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
