#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool anagramas(const string& cad1, const string& cad2) {
	if (cad1.size() != cad2.size()) {
		return false;
	}
	else
	{
		int k = 0; //indice del nº letras encontradas
		int i = 0;
		std::vector<bool> found(cad1.size() , false); //vector de posiciones encontradas
		bool flag = false; //flag
		
		
		//coste O(n!) donde n=cad1.size() ya que como mucho la palabra está al reves (ej: arroz-zorra)
		while (k < cad2.size() && !flag) {
			if (!(found[i] || cad1[i] != cad2[k])) {
				found[i] = true;
				k++;
				i = 0;

			}
			else {
				i++;
			}
			
			if (i >= cad1.size()) {
				flag = true;
			}
		}

		return !flag && k>=cad2.size();

	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	string word1, word2;
	cin >> word1 >> word2;
	cout << (anagramas(word1, word2) ? "SI" : "NO") << endl;

	

}

//#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	//system("PAUSE");
//#endif

	return 0;
}