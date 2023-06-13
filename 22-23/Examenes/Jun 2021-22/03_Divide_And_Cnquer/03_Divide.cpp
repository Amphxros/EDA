// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Busqueda binaria recursiva en un vector ordenado de forma creciente 
//O(log n)
int resolver(const std::vector<int> & v, int ini, int fin, int& ult) {
    if(fin-ini==0){
        return v[ini];
    }
    else{
        int mit= (ini+fin)/2;
        if(v[mit]== mit + v[ini]){
            ult=v[mit];
            return resolver(v,mit+1,fin,ult);
        }
        else{
            return resolver(v,ini,mit,ult);
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    
    for(int i=0; i<n; i++){
        std::cin >> v[i];
    }
    
    int ult=-1;
    int sol = resolver(v,0,n-1,ult);
    
    // escribir sol
    std::cout  << ult << "\n";
    
    
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