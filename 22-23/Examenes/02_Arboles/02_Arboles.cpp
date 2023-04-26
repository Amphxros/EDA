//Amparo Rubio Bellon
// Vj54

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include <climits>


//O(2*n + 1) donde n es la profundidad del arbol
int camino(bintree<int> tree, int& nodo, int k,int& numDragones){
    //caso nodo vacio
    if(tree.empty()){
        return -1;
    }
    //caso nodo hoja
    else if(tree.root()>=3){ //si el nodo es un nodo hoja que nos interesa
        nodo=tree.root();
        return 1;
    }
    //caso recursivo
    else{
        if(tree.root()==1){ // si en este nodo hay dragon 
            numDragones++;
        }

        int nododer=0;
        int dragDer=numDragones;
        int izq= camino(tree.left(),nodo,k+1,numDragones);
        int der= camino(tree.right(),nododer,k+1,dragDer);

       
        if(izq==-1 && der==-1){ //si no hay camino no es valido
            return -1;
        }
        else if(izq==-1||dragDer<numDragones){ //si el camino derecho es mas viable o es el unico que existe
                numDragones=dragDer;
                nodo=nododer;
        }
    
        return 1;
    }
}


void resuelveCaso(){
    bintree<int> arbol;
    arbol = leerArbol(-1); // -1 es la repr. de arbol vacio
    int nodo=0;
    int nDrag=0;
    int prof=0;
    if(camino(arbol,nodo,prof,nDrag)!=-1){
        std::cout<<nodo<<"\n";
    }
}

#define DOMJUDGE
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
