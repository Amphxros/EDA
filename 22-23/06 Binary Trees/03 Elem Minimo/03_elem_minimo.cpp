//Amparo Rubio Bellon
//VJ54

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <algorithm> 
#include <string>
using namespace std;

template<typename T>
void resolver(bintree<T> tree, T& min){
    if(tree.root() < min)
        min= tree.root();
   
    if(!tree.left().empty())
        resolver(tree.left(),min);
    if(!tree.right().empty())
        resolver(tree.right(),min);
    
}
#define DOMJUDGE
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string aux;
    std::cin>>aux;
    if (!std::cin)
    {
        return false;
    }
    
    if(aux=="P"){
        std::string s = "#";
        bintree<std::string> treeC = leerArbol(s);
        if(!treeC.empty()){
            std::string min= treeC.root();
            resolver(treeC, min);
            std::cout<<min;
        }
    }
    else if(aux=="N"){

        bintree<int> treeN= leerArbol(-1);

        if(!treeN.empty()){
            int min= treeN.root();
            resolver(treeN, min);
            std::cout<<min;
        }
    }
    std::cout<<"\n";
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
    //system("PAUSE");
#endif

    return 0;
}
