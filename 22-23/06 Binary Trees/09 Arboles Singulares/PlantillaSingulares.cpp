//Amparo Rubio Bellon
//VJ54
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


int nodoSingular(bintree<int>tree, int anteriores, int& singulares) {
    if (!tree.empty()) {
        anteriores += tree.root();
        int izq = nodoSingular(tree.left(), anteriores, singulares);
        int der = nodoSingular(tree.right(), anteriores, singulares);

        if (izq + der == anteriores - tree.root()) singulares++;
        return izq + der + tree.root();
    }
    else
        return 0;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    int s = 0;
    int sing = nodoSingular(tree, 0, s);
    cout << s << "\n";
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
