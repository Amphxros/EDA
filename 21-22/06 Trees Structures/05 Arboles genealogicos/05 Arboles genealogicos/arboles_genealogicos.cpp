//VJ50 AMPARO RUBIO BELLON

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"


void arbolValido(bintree<int>tree, bool& valido,int prof, int& profinal) {
    if (!tree.empty()) {
        int pad = tree.root();
        int iz = 1, dr=-1;
        if (!tree.left().empty()) iz = tree.left().root();
        if (!tree.right().empty()) dr = tree.right().root();

        if (iz != -1) {
            if (pad >= iz + 18) {
                if (dr != -1) {
                    valido = iz >= dr + 2; //hijos con menos de 2 años de dif
                }
                else valido = true; //1 hijo mayor de edad
            }
            else valido = false; //hijos con menos de 18 años de dif
        }
        //sin hijo izquierdo, pero si hijo derecho
        else if(dr!=-1) {
            valido = false;
        }
        //sin hijos
        else {
            valido = true;
        }

        if (valido) {
            arbolValido(tree.left(), valido, prof + 1, profinal);
       
            if (valido) {
                arbolValido(tree.right(), valido, prof + 1, profinal);
            }
            if (profinal < prof) profinal = prof;
        
        }
        
    }
}

void resuelveCaso() {
    bintree<int> tree_;
    tree_ = leerArbol(-1);

    bool isValid = true;
    int prof = 1;
    int profinal = 0;

    arbolValido(tree_, isValid, prof, profinal);

    isValid ? std::cout << "SI "<< profinal : std::cout<< "NO" << "\n";
}

int main() {
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