// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

using productos=std::vector<int>;

bool superVisitado(int k, std::vector<int>& visitados) {
    return visitados[k] <= 2;
}

void resolver(int k,const std::vector<productos>& compra ,std::vector<int>& visita,std::vector<int>& cesta, const int& nSupers,const int& nProductos, int& gasto){

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nSupers, nProductos;
    std::cin >> nSupers >> nProductos;
    
   std::vector<productos> super(nSupers);

   for(int i=0; i<nSupers; i++){
       for(int j=0; j<nProductos; j++){
           int producto;
           std::cin >> producto;
           super[i].push_back(producto);
       }

    std::vector<int> cesta(nProductos, 0);
    std::vector<int> visitados(nSupers, 0);
    int gasto=0;


   
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