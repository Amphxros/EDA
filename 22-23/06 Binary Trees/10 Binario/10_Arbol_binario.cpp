//Amparo Rubio Bellon
//VJ54
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

#define DOMJUDGE
//O(2*k) donde k = profundidad del arbol
template <class T>
bool esBinario(bintree<T> const& tree) {
    if (tree.empty())
        return true;
    else {
        bool l = tree.left().empty() || tree.left().root() < tree.root();
        bool r = tree.right().empty() || tree.right().root() > tree.root();

        return l && r && esBinario(tree.left()) && esBinario(tree.right());
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    cout << (esBinario(tree) ? "SI" : "NO" )<< "\n";
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
