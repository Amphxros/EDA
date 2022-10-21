// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list.h"


// O(n*k)
void resolver(list<int>& list, const int& frecuencia) {
    auto it=list.begin();

    while(list.size() > 1){
        for(int k=0;k<frecuencia;k++){
            ++it;
            if(it==list.end()){
                it=list.begin();
            }
        }
        it=list.erase(it);
        if(it==list.end()){
            it=list.begin();
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nAlumnos_;
    int mFrecuencia_;
    std::cin>>nAlumnos_>>mFrecuencia_;
    if (!std::cin|| nAlumnos_==0||mFrecuencia_==0)
        return false;
    
    list<int> alumnos= list<int>();
    for(int i=0;i<nAlumnos_;i++){
        alumnos.push_back(i+1);
    }

    resolver(alumnos,mFrecuencia_);

    std::cout<<alumnos.front()<< "\n";

    // escribir sol
    
    
    return true;
    
}
#define DOMJUDGE
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
     system("PAUSE");
     #endif
    
    return 0;
}