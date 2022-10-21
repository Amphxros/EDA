// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list.h"

class list_plus: public list<int>{
public:
    //O(n2)
    void elimina(int elem){
        if (!empty()) {
            auto it = begin();
            while (it != end())
            {
                auto aux = it;
                if (*aux == elem) {
                    erase(it);
                    it = begin();
                }
                else {
                    it++;
                }
            }
        }
    }

    void print(){
        for(auto it= begin(); it!=end();++it){
            std::cout<< *it<<" ";
        }
        std::cout << "\n";
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    list_plus list;
    int n;
    std::cin>>n;
    while(n!=-1){
        list.push_back(n);
        std::cin>>n;
    }

    int elem;
    std::cin >> elem;
    
    list.print();
    list.elimina(elem);
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