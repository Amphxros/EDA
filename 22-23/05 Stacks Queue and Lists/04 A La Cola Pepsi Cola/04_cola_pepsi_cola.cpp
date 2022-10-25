// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include "queue.h" 



#define DOMJUDGE
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada 
    queue<int>v;
    queue<int>w;

    int aux;
    std::cin >> aux;
    while (aux != -1)
    {
        v.push(aux);
        std::cin >> aux;

    }

    int col = 0;
    std::cin >> col;

    aux = 0;
    std::cin >> aux;

    while (aux != -1)
    {
        w.push(aux);
        std::cin >> aux;

    }
    
    v.print();
    // escribir sol
    v.cola(col, w);
    v.print();

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