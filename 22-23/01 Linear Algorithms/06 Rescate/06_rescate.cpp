// Amparo rubio
// Vj54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(const std::vector<int>& v,int h ) {
    int ini=0; int fin=0;
    int i=0;
    while(i<v.size() && ini!=0){
        if(v[i]<h && ini==0)
            ini=v[h];
        i++;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escri>biendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n,h;
    std::cin>>n;
    std::cin>>h;

    std::vector<int> v(n);
    for(int i=0;i<n;i++){
        std::cin>>v[i];
    }
    // escribir sol
    
    
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