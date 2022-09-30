// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
// O(n/2)
int resolver(const std::vector<int>& v,int ini,int fin) {
    //caso base
    if(fin-ini<=1){
        return ini;
    }

    //caso recursivo

    int l= v[ini+1]-v[ini];
    if (l != 0) {
        return ini;
    }
  
    return resolver(v,ini+2,fin);

}

#define DOMJUDGE
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin>>n;

    std::vector<int>v(n);
    for(int i=0;i<n;i++)
        std::cin>>v[i];
    
    // escribir sol
    std::cout<<resolver(v,0,n-1)<<"\n";
    
    
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