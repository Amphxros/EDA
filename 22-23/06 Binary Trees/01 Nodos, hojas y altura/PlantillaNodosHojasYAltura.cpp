
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <algorithm> 
using namespace std;

template <class T>
int nodos(bintree<T> const& tree){
    if (tree.empty()) {
        return 0;
    }
    else {
        int n = !tree.left().empty() + !tree.right().empty();
        return n + nodos(tree.left()) + nodos(tree.right());
    }
}
#define DOMJUDGE
template <class T>
int hojas(bintree<T> const& tree){
    if (tree.empty()) {
        return 0;
    }
    else {
        if (tree.left().empty() && tree.right().empty()) {
            return 1;
        }
        else {
            return hojas(tree.left()) + hojas(tree.right());
        }
    }
}

template <class T>
int altura(bintree<T> const& tree, int h){
    if (tree.empty()) {
        return h;
    }
    else {
        h++;
        int auxl = 0;
        int auxr = 0;
        if (altura(tree.left(), h) > altura(tree.right(), h)) {
            h = altura(tree.left(), h);
        }
        else {
            h = altura(tree.right(), h);
        }
        
        return h;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<char> tree;
    tree = leerArbol('.');
    cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree,0) << "\n";
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
    //system("PAUSE");
#endif

    return 0;
}
