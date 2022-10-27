// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list.h"

template <class T>
class list_plus: public list<T>{
public:
    void adelanta(int tam,int pos, int lon,int k){
     auto ini = l.begin(), end = l.end();
    
    for (int i = 0; i < pos - 1; i++)
        ini++;

    for (int j = l.size(); j > pos + lon - 2; j--)
        end--;

    if (ini != end) {
        //O(n/2)
        for (int i = lon / 2; i > 0; i--) {
            swap(*ini, *end); //O(2)
            ini++;
            end--;
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
 
    int tam, pos, lon, k;
    std::cin>> tam>>pos>>lon>>k;
    list_plus<char> list;

    for(int i=0;i<tam;i++){
        int c;
        std::cin>>c;
        list.push_back(c);
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