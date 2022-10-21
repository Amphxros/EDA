//Amparo Rubio Bellon
//VJ54

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue.h"



class queue_plus : public queue<int> {

	using Nodo = typename queue<int>::Nodo;

public:
	//O(2n) donde n= elem de cada una de las colas
	void mezcla(queue<int>* cola) {
		if (!this->empty() || !cola->empty()) {
			int posA = 0, posB = 0, tamA = size(), tamB = cola->size();
			Nodo* nA = prim;
			Nodo* nB = cola->prim;
			Nodo* nPrincipal = nullptr;
			this->nelems = tamA + tamB;
			if (nB == nullptr || (nA != nullptr && nA->elem < nB->elem)) {
				nPrincipal = nA;
				nA = nA->sig;
				posA++;
			}
			else {
				prim = nB;
				nPrincipal = nB;
				nB = nB->sig;
				posB++;
			}

			while (posA < tamA || posB < tamB) {

				if (nA == nullptr) {
					nPrincipal->sig = nB;
					nPrincipal = nPrincipal->sig;
					nB = nB->sig;
					posB++;
				}

				else if (nB == nullptr) {
					nPrincipal->sig = nA;
					nPrincipal = nPrincipal->sig;
					nA = nA->sig;
					posA++;
				}

				else {
					if (nA->elem < nB->elem) {
						nPrincipal->sig = nA;
						nPrincipal = nPrincipal->sig;
						nA = nA->sig;
						posA++;
					}
					else {
						nPrincipal->sig = nB;
						nPrincipal = nPrincipal->sig;
						nB = nB->sig;
						posB++;
					}
				}
			}
			ult = nPrincipal;
			cola->prim = nullptr;
			cola->ult = nullptr;
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    queue_plus q1;
    queue<int> q2;
    std::cin >> n;

    while (n != 0) {
        q1.push(n);
        std::cin >> n;
    }

    std::cin>>n;
    while(n!=0){
        q2.push(n);
        std::cin>>n;
    }

    // llamada a metodo
    q1.mezcla(&q2);

    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q1.empty()) {
        std::cout << q1.front() << " ";
        q1.pop();
    }
    std::cout << "\n";
    
}

#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    int nCasos = 0;
    std::cin >> nCasos;
   
    for (int i = 0; i < nCasos; i++) {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
