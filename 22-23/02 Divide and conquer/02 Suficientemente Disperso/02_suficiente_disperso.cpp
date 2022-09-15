// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

// función que resuelve el problema
bool resolver(const std::vector<int>& v, int k, int ini, int fin) {
    if(fin-ini==1){
        return std::abs(v[fin] - v[ini])>=k;
    }
    else{
        int mit= (fin + ini)/2;

        bool iz= resolver(v,k,ini,mit);
        bool de= resolver(v,k,mit+1,fin);

        return std::abs(v[fin] - v[ini])>=k && iz && de;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    std::cin>>n;
    if (! std::cin)
        return false;
    
    std::cin>>k;
    std::vector<int> v(n);
  
    for(int i=0;i<n;i++)
        std::cin>>v[i];
    
    
    // escribir sol
    if(n==1 || resolver(v,k,0,n-1)){
         std::cout << "SI" << "\n";
    }
    else{
         std::cout << "NO" << "\n";
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