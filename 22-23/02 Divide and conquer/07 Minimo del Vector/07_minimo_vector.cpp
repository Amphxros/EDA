
// VJ 54 Amparo Rubio Bellon
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//O(log n)
int resolver(const std::vector<int>& v, int ini, int fin) {
  if (ini== fin - 1)
     return v[ini];

	if (v[ini] < v[(ini + fin) / 2]) 
        return resolver(v, ini, (ini + fin) / 2);
	else 
        return resolver(v, (ini + fin) / 2, fin);
}


bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (!std::cin) {
        return false;
    }
    std::vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    
    std::cout << resolver(v, 0, n)<<"\n";
    
    return true;
    
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
