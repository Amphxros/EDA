// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"

#define DOMJUDGE
// función que resuelve el problema
bool resolver(Set<int> s,int n) {
    std::vector<int>v;
    int aux=n;
    std::cout<<n<<" ";

    while (aux >= 0) {
        int p= aux % 10;
        v.push_back(p);
        aux /= 10;
        if (aux == 0) {
            aux -= 1;
        }
    }

    int m=0;
    for(int i=0;i<v.size();i++){
        int p=v[i]*v[i];
        m+=p;
    }

    if(m==1){
        return true;
    }
    else if(s.contains(m)){
        std::cout << m << " ";
        return false;
    }
    else{
        s.add(m);
        return resolver(s,m);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin>>n;
    if (! std::cin)
        return false;
    
    Set<int> s= Set<int>();
    s.add(n);
    // escribir sol
    if (resolver(s, n)) {
        std::cout << 1 << "\n";
    }
    else {
        std::cout<<0<<"\n";
    }
    
    
    return true;
    
}

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
     system("PAUSE");
     #endif
    
    return 0;
}