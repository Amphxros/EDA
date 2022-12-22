// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#define DOMJUDGE

bool esSolucion(const int& n, std::vector<int>sol) {
    return sol[n-1] != -1;
}

void resolver(int k, const int&n, const int&m, std::vector<int>& sol) {
    if(esSolucion(n,sol)){
        for(int k = 0; k<n; k++){
            std::cout << (char)('a' + sol[k]);
        }
        std::cout << "\n";
    }
    else{
        for(int i=0; i<m; i++){
            sol[k]=i;
            resolver(k+1,n,m,sol);
            sol[k]=-1;
        }
    }
}

// función que resuelve el problema
void resolver(const int& n, const int& m) {
     //n = tamaño de la combinacion
    //m = elementos disponibles
    std::vector<int> sol(n,-1);
    resolver(0, n, m, sol);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int n,m;
    std::cin >> m >> n;
    if (!std::cin)
        return false;
    resolver(n,m);
    std::cout << "\n";
    
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