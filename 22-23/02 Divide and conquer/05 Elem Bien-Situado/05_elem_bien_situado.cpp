// Amparo Rubio Bellon
// VJ 54 


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

// O(log2(n))
bool resolver(const std::vector<int>& v, int ini, int fin) {
    
    if(fin-ini==1){
        return v[ini]==ini;
    }
    else{
        int mit= (ini + fin)/2;
        if(v[mit]==mit){
            return true;
        }
        else{
            if(v[mit] < mit){
                return resolver(v,mit+1,fin);
            }
            else{
                return resolver(v, ini,mit-1);
            }
        }

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   int n;
	std::cin >> n;
	if (n >= 1) { //caso especial
		std::vector<int> v(n);

		for (int i = 0; i < n; i++) {
			int c;
			std::cin >> c;
			v[i] = c;
		}

		// escribir sol
		if (resolver(v, 0, n-1)) {
			std::cout << "SI" << "\n";
		}
		else {
			std::cout << "NO" << "\n";
		}
	}
	else {
		std::cout << "NO" << "\n";
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
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}