// Amparo rubio
// Vj54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
void resolver(const std::vector<int>& v,int h ) {
   
    std::vector<int> sumas = std::vector<int>();
   
 
    bool init = false;
    for (int i = 0; i < v.size(); i++) {
        if ( v[i] > h && !init) {
            init = true;
            sumas.push_back(i);
            
        }
        else if (v[i]<=h && init) {
            sumas.push_back(i-1); //ultimo visible
            
            init = false;
        }
  
    }
    
    int ini = 0;
    int fin = 0;
    int mayor = 0;
    for (int i = 1; i < sumas.size(); i +=2) {
        
        if (sumas[i] - sumas[i-1] > mayor) {
            ini = sumas[i-1];
            fin = sumas[i];
            mayor = sumas[i] - sumas[i-1];
        }
       
        
    }

    std::cout << ini << " " << fin << "\n";


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escri>biendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, h;
    std::cin >> n >> h;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    resolver(v,h);
    
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