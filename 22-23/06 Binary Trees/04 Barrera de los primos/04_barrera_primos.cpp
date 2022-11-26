// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// coste constante ya que en este ejercicio los resultados interesantes son los multiplos de 7
bool esPrimo(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i < 7; i++){
        if(n % i == 0) return false;
    }
    return true;

}

// función que resuelve el problema
int resolver(const bintree<int>& tree,int padre, int k) {
    if(tree.empty()){
        return -1;
    }
    else{
        k++;
        if(!esPrimo(padre)){
            padre=tree.root();
            int kL=k;
            int kR=k;
            int izq = resolver(tree.left(),padre,kL);
            int der = resolver(tree.right(),padre,kR);
           
            if (izq == -1 && der == -1) return padre;
            
            if(kL<kR){
                if (der != -1) return der;
                else return izq;
            }
            else{

                if (izq != -1) return izq;
                else return der;
            }

        }
        else{
            return padre;
        }
       
      
    }
    return -1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1);
    int k = 0;
    int res= resolver(tree,1,k); //1 para forzar que la raiz sea el proximo padre
    if(res==-1){
        std::cout<<"NO HAY\n";
    }
    else{
        std::cout<<res<<" "<< k << "\n";
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