//Amparo Rubio Bellon
//VJ54

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue.h"
#include <vector>
#include<algorithm>

class queue_int : public queue<int> {

    using Nodo = typename queue<int>::Nodo;

public:
    //O(2*n)
    void reordena() {
        if (!this->empty()) {
           std::vector<int> v; // vector de negativos
            int size = this->nelems;

            //colocamos en sus respectivos vectores O(n)
            for(int i=0;i<size; i++){
                Nodo* n= this->prim;
                v.push_back(n->elem);
                this->pop();
            }

            std::sort(v.begin(), v.end()); //ordenamos los negativos O(n*log n)
           
            //colocamos los positivos O(n)
            for(int i=0;i<v.size();i++){
                this->push(v[i]);
            }
          
           
        }

    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n=0;
    queue_int q;
    std::cin >> n;
    if (!std::cin) return false;
    while (n != 0) {
        q.push(n);
        std::cin >> n;
    }

    // llamada a metodo
    q.reordena();

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i) {
        n = q.front();
        q.pop();
        q.push(n);
    }
    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
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
    //system("PAUSE");
#endif

    return 0;
}
