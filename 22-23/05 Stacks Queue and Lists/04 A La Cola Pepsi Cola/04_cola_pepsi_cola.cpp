// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include "queue.h" 

// función que resuelve el problema
void resolver(queue<int> v, queue<int> w, int col) {
    queue<int> result;
    queue<int> aux=v;

    //imprimimos la cola original O(n)
    while(!aux.empty()){
        std::cout<< aux.front()<< " ";
        aux.pop();
    }

    while (!v.empty() && col!=v.front())
    {
        result.push(v.front());
        v.pop();
    }
    

    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    queue<int>v;
    queue<int>w;
    int aux;
    std::cin>>aux;

    while (aux!=-1)
    {
        v.push(aux);
        std::cin>>aux;
        
    }
    
    int col=0;
    std::cin>>col;

    aux=0;
    std::cin>>aux;

    while (aux!=-1)
    {
        w.push(aux);
        std::cin>>aux;
        
    }

    
   
    // escribir sol
    
    
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