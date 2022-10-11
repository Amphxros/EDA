// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>
#include "Polinomio.h"




// función que resuelve el problema
int resolver(const Polinomio& p, int val) {
    
    return p.resolver(val);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int base = 0;
    int exp = 0;

    std::cin >> base;

    if (! std::cin)
        return false;
    std::cin >> exp;

    Polinomio p = Polinomio();
    while (base!=0||exp!=0)
    {
        p.add(base, exp);
        std::cin >> base >> exp;
    }

    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        // escribir sol
        std::cout << resolver(p, val)<<" ";
    }
    std::cout << "\n";
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