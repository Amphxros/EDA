// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// O(log(n)) puesto que el vector está ordenado
bool resolver(std::vector<int> v, int ini, int fin) {

	if(fin-ini==0){
		return v[ini]==ini;
	}
	else{
		int mit= (ini+fin)/2;
		if(v[mit]==mit){
			return true;
		}
		else if(v[mit]>mit){
			return resolver(v,ini,mit-1);
		}
		else{
			return resolver(v,mit+1,fin);
		}
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int n;
	std::cin >> n;
	std::vector <int> v(n);
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}

	if(resolver(v,0,n-1)){
		std::cout << "SI" << "\n";
	}
	else{
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