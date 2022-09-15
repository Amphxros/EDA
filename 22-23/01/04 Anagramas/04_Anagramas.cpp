//Amparo Rubio
// VJ54

#define DOMJUDGE

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

// O(N*log2(N))
bool resolver(std::string a, std::string b) {
   
    if (a.size() != b.size()) {
        return false;
    }

    //ordenamos las strings O(N*log2(N))
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());


    //comparamos O(n)
    int i = 0;
    while (i<a.size() && a[i]==b[i])
    {
        i++;
    }


    return i==a.size();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::string a,b;
    std::cin>>a>>b;

    // escribir sol
    if(resolver(a,b)){
        std::cout<<"SI"<<"\n";
    }
    else{
        std::cout << "NO" << "\n";
    }
    
    
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