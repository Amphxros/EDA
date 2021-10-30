#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


int isCharEqual(const std::vector<char>& v, char c) {
	int i = 0;
	while (i < v.size() && v[i] != c)
		i++;
	return i;
}

bool estaEquilibrado(const std::vector<char>& ini, const std::vector<char>& fin, std::string msg) {
	std::vector<int> chars = std::vector<int>(ini.size(), 0);

	for (int i = 0; i < msg.size(); i++) {
		int iniChar = isCharEqual(ini, msg[i]);
		if (iniChar < ini.size()) {
			chars[iniChar]++;
		}
		int finChar = isCharEqual(fin, msg[i]);
		if (finChar < fin.size() && chars[finChar]>0) {
			chars[finChar]--;
		}


	}
	int j = 0;
	while (j < chars.size() && chars[j] == 0)
		j++;

	return j == chars.size();

}

bool resuelveCaso() {
	std::vector <char> ini = { '(', '[', '{'};
	std::vector <char> fin = { ')', ']', '}'};

	std::string in;
	std::getline(std::cin, in);
	if (in=="") {
		return false;
	}
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