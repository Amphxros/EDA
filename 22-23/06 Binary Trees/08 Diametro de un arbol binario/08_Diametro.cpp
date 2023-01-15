// Amparo Rubio Bellon
// VJ54 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"


// función que resuelve el problema
int resolver(const bintree<char>& tree, int& altura) {
    if(tree.empty()){
        altura=0;
        return 0;
    }
    else{
        int izq=0, der=0;
        int diamIzq=-1, diamDer=-1;
      
        diamIzq = resolver(tree.left(), izq);
        diamDer = resolver(tree.right(), der);
      
        altura = std::max(izq, der) + 1;
        int diam=std::max(diamIzq,diamDer);

        return std::max(diam, izq + der + 1);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree = leerArbol('.');
    int altura=0;
    std::cout << resolver(tree, altura) << "\n";
    
}
#define DOMJUDGE
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