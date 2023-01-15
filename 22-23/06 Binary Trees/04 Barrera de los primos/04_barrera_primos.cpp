// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// O(1) ya que en este ejercicio los resultados interesantes son los multiplos de 7
bool esPrimo(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i < 7; i++){
        if(n % i == 0) return false;
    }
    return true;

}

// función que resuelve el problema
int resolver(const bintree<int>& tree, int k, int& profMin, int& nodo) {
    if (tree.empty() || esPrimo(tree.root())) return -1;

    else {
        if (tree.root() % 7 == 0) {
            if (profMin == 0 || k < profMin) {
                profMin = k;
                nodo = tree.root();
            }
            return 1;

        }

        else {
            int izq = nodo, der = nodo;
            int nodoizq = nodo;
            int profIzq = k;
            
            der = resolver(tree.right(), k + 1, profMin, nodo);
            izq = resolver(tree.left(),  k + 1, profMin, nodo);
          

            if (izq == -1 && der == -1) {
                return -1;
            }

            else {
                return 1;
            }

        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1);
    int profMin=0, nodo=-1;

    if(tree.empty()|| esPrimo(tree.root())|| resolver(tree,0,profMin,nodo) ==-1){
        std::cout << "NO HAY"<<"\n";
    }
    else{
        std::cout << nodo << " " << profMin +1 << "\n";
    }
    
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