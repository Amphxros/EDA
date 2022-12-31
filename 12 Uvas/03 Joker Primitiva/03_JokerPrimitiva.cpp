// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

bool resolver (int num, int boleto){
    //descomponer los num en sus digitos
    int aux=num;
    int aux2=boleto;
    std::vector<int> v;
    std::vector<int> v2;
    while (aux >= 0) {
        v.push_back(aux % 10);
        v2.push_back(aux2 % 10);

        aux /= 10;
        aux2/=10;
        if (aux == 0) {
            aux -= 1;
        }
    }

    //ordenamos
    std::sort(v.begin(), v.end());
    std::sort(v2.begin(), v2.end());
    
    //comparamos
    int i=0;

    while(i<v.size() && v[i]==v2[i]){
        i++;
    }

    return i==v.size();
        
    }




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    int boleto;

    std::cin >> num;
    std::cin >> boleto;

    if (resolver(num, boleto)) {
        std::cout << "GANA"<< "\n";
    }
    else {
        std::cout << "PIERDE" << "\n";
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