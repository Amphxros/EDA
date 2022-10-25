// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list.h"
#include <algorithm>

template <class T>
class list_plus: public list<T>{
public:
    void adelanta(int tam,int pos, int lon,int k){
        if (!this->empty() && lon!=0 &&k!=0) {
            auto itA = this->begin();
            auto itB = this->begin();
            if (pos + lon > tam) {
                //sgmentos n-pos
                for (int i = 0; i < tam - pos; i++) {
                    itA++;
                    itB++;
                }
                for (int i = 0; i < k; i++)
                    itB++;

            }
            else {
                for (int i = 0; i < pos; i++) {
                    itA++;
                    itB++;
                }
                for (int i = 0; i < k; i++)
                    itB++;
            }

            for (int i = 0; i < lon; i++) {

                auto aux = *itA;
                *itA = *itB;
                *itB = aux;
                
                itA++;
                itB++;

            }
        }
    }
    
    void print(){
        for(auto it= this->begin(); it!=this->end();++it){
            std::cout<< *it<<" ";
        }
        std::cout << "\n";
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
 
    int tam, pos, lon, k;
    std::cin>> tam>>pos>>lon>>k;
    list_plus<char> list;

    for(int i=0;i<tam;i++){
        int c;
        std::cin>>c;
        list.push_back(c);
    }

    list.adelanta(tam, pos, lon, k);
    list.print();
    
    
    
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