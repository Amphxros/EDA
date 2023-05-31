// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(const std::vector<int> & v, int ini, int fin) {
    
    if(fin-ini <=1){
     return v[fin] - v[ini] >=0;
    }
    else{
        int mit = (ini+fin)/2;
        return resolver(v,ini,mit) && resolver(v,mit,fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> v;
    int n=0;
   do{
        std::cin>>n;
        v.push_back(n);
   } while (n != 0 && !std::cin);
    v.pop_back(); //eliminamos el 0
    
    // escribir sol
    n=(int)(v.size()-1);

    if(resolver(v,0,n)){
        std::cout <<"SI"<< "\n";
    }
    else{
          std::cout <<"NO"<< "\n";
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