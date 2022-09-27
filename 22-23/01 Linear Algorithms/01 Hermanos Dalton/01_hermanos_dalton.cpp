// VJ 54 Amparo Rubio Bellon


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>

// o(n)
bool resolver(const std::vector<int>& v) {
   
    bool asc = true, desc=true;

    int i = 1;
    while(i < v.size() && (asc || desc)){
        asc &= v[i - 1] < v[i];
        desc &= v[i - 1] > v[i];
        i++;
    }
  
    return asc || desc;

    
}

bool resuelveCaso() {
    // leer los datos de la entrada
    
    int n;
    std::cin>>n;

    if (! std::cin|| n<=0)
        return false;
    else{
        std::vector<int> v(n);
        
        for(int i=0;i<n;i++)
            std::cin>>v[i];
    
        if(resolver(v)){
            std::cout << "DALTON" << "\n";
        }
        else{
            std::cout << "DESCONOCIDOS" << "\n";
        }
    }
    
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
     system("PAUSE");
     #endif
    
    return 0;
}