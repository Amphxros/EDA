// Amparo Rubio Bellon
// VJ 54 


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

bool elemento_situado(const std::vector <int>& v, int ini, int fin) { // o(log n)
	if (fin - ini > 1) {
		int mit = fin + ini / 2;
		if (v[mit] > mit) {
			return elemento_situado(v, ini, mit);
		}
		else if (v[mit] < mit) {
			return elemento_situado(v, mit, fin);
		}
		else return true;
	}
	else if (fin - ini == 1) return v[ini] == ini;
	return false;
}
    
	

int main() {
	int casosPrueba = 0;
	std::cin >> casosPrueba;
	for (int i = 0; i < casosPrueba; i++) {
		std::vector<int> v;
	    int cant = 0;
	    std::cin >> cant;
	    for (int i = 0; i < cant; i++) {
		    int n;
		    std::cin >> n;
		    v.push_back(n);
	}
    	if (elemento_situado(v, 0, v.size())) //o(log n)
			std::cout << "SI" << "\n";
		else 
            std::cout << "NO" << "\n";
	}
	return 0;
}
	
