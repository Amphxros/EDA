// Amparo Rubio
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"
#include <vector>
#define DOMJUDGE
// O(k) donde k son los k elems
std::vector<int> resolver(Set<int> s, int k) {
    
     std::vector<int> v(k);
    for(int i=0; i<k;i++){
        int n = s.getMin();
        v[i] = n;
        std::cout << n << " ";
        s.removeMin();
    }
    std::cout << "\n";
    
    return v;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int k;
    std::cin>>k;

    if (!std::cin || k<=0)
        return false;
    Set<int> s= Set<int>();
    
    int n=0;
    std::cin>>n;
    s.add(n);
    while(n!=-1){
        std::cin>>n;
        s.add(n);
    }
    s.remove(-1);
    resolver(s, k);
    // escribir sol
    
    return true;
    
}

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
