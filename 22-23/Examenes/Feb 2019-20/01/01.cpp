// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// función que resuelve el problema
int resolver(std::vector<int> const& v, const int& n, const int& l) {
    int left=0, num=0;

    for(int i=1;i<v.size();i++){
        if (std::abs(v[i] - v[i - 1]) <= 1) {
            num += (i - left) == (l - 1);
        }
        else {
            left = n;
        }
    }

    return num;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,l;
    std::cin >> n >> l;
    if (! std::cin || n==0 || l==0)
        return false;
    
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    
    // escribir sol
    std::cout << resolver(v,n,l) << "\n";
    
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