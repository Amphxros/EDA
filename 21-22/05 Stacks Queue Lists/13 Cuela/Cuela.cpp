#include <iostream>
#include <iomanip>
#include <fstream>
//AMPARO RUBIO BELLON

#include "queue_eda.h"
#include <stack>
using namespace std;


template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:

    //coste O(2*n) donde n= tam cola
    void cuela(const T& a, const T& b) {
        // Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult
        queue<T>q;
        bool found = false;
        while (!this->empty()) {
            if (this->front() != b) {
                if(this->front() !=b)
                q.push(this->front());
                cout << this->front() << "#";
            }
            else {
                if (found) {
                    q.push(this->front());
                }
                found = true;
            }
            this->pop();
        }

        cout << "\n";
        found = false;
        while (!q.empty()) {
            this->push(q.front());
            if (q.front() == a) {
                if (!found) {
                    this->push(b);
                    found = true;
                }
            }
            q.pop();
        
        }


    }

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, b;
    queue_plus<int> q;
    cin >> n;
    if (n == -1) return false;
    while (n != -1) {
        q.push(n);
        cin >> n;
    }
    cin >> a >> b;

    // llamada a metodo
    q.cuela(a, b);

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i) {
        n = q.front();
        q.pop();
        q.push(n);
    }
    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
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
