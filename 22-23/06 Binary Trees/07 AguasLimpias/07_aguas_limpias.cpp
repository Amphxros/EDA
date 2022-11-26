// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


// función que resuelve el problema
int resolver(const bintree<int>& tree,int& tramo) {
    if(tree.left().empty() && tree.right().empty()){
        if(tree.root() !=0 ) return 1-tree.root();
        else return 1;
    }
    else{
        int iz=0, der=0, res=0;
        if(!tree.left().empty()){
            iz = resolver(tree.left(),tramo);
        }
        if(!tree.right().empty()){
            der = resolver(tree.right(),tramo);
        }

        res= iz+der;
        if(tree.root() != 0 ) res-=tree.root();
        if(res<0) res=0;
        else if(res>3) tramo++;
        return res;

    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1); 
    int tramo = 0;

    if (!tree.empty()) {
		int sol = resolver(tree, tramo);
		if (sol >= 3) tramo--;
	}
    
    // escribir sol 
    std::cout<<tramo<<"\n";
  
    
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
     system("PAUSE");
     #endif
    
    return 0;
}