//AMPARO RUBIO BELLON

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

//coste O(n) donde n= v.size()
int isCharEqual(const std::vector<char>& v, char c) {
	int i = 0;
	while (i < v.size() && v[i] != c)
		i++;
	return i;
}

//coste O(n) donde n= msg.size()
bool estaEquilibrado(const std::vector<char>& ini, const std::vector<char>& fin, std::string msg) {
	std::stack<char> mStack;

	for (int i = 0; i < msg.size(); i++) {
		char c = msg[i];
		int in = isCharEqual(ini, c);
		int fi = isCharEqual(fin, c);
		if (in < ini.size()) {
			mStack.push(c);
		}
		else if (fi < fin.size()) { 
			if (!mStack.empty() &&isCharEqual(ini, mStack.top()) == fi) // si los indices de la pila coinciden () [] {}
			{
				mStack.pop();
			}
			else {
				return false;
			}
		}

	}

	return mStack.empty(); // si no quedan parentesis en la pila pues esta equilibrado

}

bool resuelveCaso() {
	std::vector <char> ini = { '(', '[', '{'};	
	std::vector <char> fin = { ')', ']', '}'};
	std::string in;
	std::getline(std::cin, in);
	if (!std::cin)
		return false;

	else {

		if (estaEquilibrado(ini, fin, in))
			std::cout << "SI" << "\n";
		else
			std::cout << "NO" << "\n";
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}