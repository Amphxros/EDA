//Amparo Rubio Bellon
//VJ54
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <algorithm> 
#include <vector>
using namespace std;


void resolver(bintree<int> tree, std::vector<int>& sol){
    if(tree.empty()){
        return;
    }
    else{
        if(tree.left().empty() && tree.right().empty()){
            sol.push_back(tree.root());
        }
        else{
            if(!tree.left().empty()){
                resolver(tree.left(), sol);
            }
            if(!tree.right().empty()){
                resolver(tree.right(), sol);
            }
        }
    }
}
#define DOMJUDGE
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<int> tree;
    tree = leerArbol(-1);
    std::vector<int> sol;
    resolver(tree, sol);

    for(int i=0; i< sol.size(); i++){
        std::cout<< sol[i]<<" ";
    }
    std::cout<<"\n";
    
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
