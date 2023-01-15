// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

bool esSolucion(const int& n, std::vector<int>sol) {
    return sol[n-1] != -1;
}

// función que resuelve el problema
void resolver(int k,int n,std::vector<int> sol, std::vector<std::string> colors) {
    if(esSolucion(n,sol)){
        for(int k = 0; k<n; k++){
            std::cout << (colors[sol[k]])<< " ";
        }
        std::cout << "\n";
    }
    else{
        for(int i=0; i<colors.size(); i++){
            sol[k]=i; //marcamos
            resolver(k+1,n,sol,colors); //vamos al siguiente
            sol[k]=-1; //desmarcamos
        }
    } 
    
}
#define DOMJUDGE
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n<=0)
        return false;
    

    std::vector <std::string> colors = { "azul", "rojo", "verde"};  
    std::vector<int> sol(n,-1);
    // escribir sol
    resolver(0, n, sol, colors);
    
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
