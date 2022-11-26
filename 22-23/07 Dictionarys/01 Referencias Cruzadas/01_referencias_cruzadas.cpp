// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "list_eda.h"

#include "treemap_eda.h"

typedef map<std::string, list<int>*> Diccionario;

// función que resuelve el problema
void resolver() {
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin>>n;
    if (! std::cin || n<=0)
        return false;

    Diccionario dic;
    std::string palabra;
    std::getline(std::cin,palabra);

    map<std::string, list<int>*>::iterator it= dic.begin();

    while (it!=dic.end()){
        std::cout<<it->first<<" ";
        it++;
    }
    {
        /* code */
    }
    
    
    
    
    // escribir sol
    
    
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
     system("PAUSE");
     #endif
    
    return 0;
}