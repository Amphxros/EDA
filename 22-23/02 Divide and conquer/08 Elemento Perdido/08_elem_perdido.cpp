// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// O(n)
int resolver(const std::vector<int>& v, const std::vector<int>& w, int ini, int fin) {
  if(fin-ini==0){ //caso base 
    return v[ini];
  }

  if(v[ini] - w[ini]==0){ //si es igual pasamos al siguiente
    return resolver(v,w,ini+1,fin);
  }
  else{
    return v[ini];
  }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin>>n;

    std::vector<int>v(n);
    std::vector<int>w(n-1);
    
    for(int i=0;i<n;i++)
        std::cin>>v[i];

    for(int i=0;i<n-1;i++)
        std::cin>>w[i];

    // escribir sol
    std::cout << resolver(v, w, 0, n - 1)<<"\n";
    
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