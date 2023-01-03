// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

enum Colores {  rojo, azul, verde };

bool esSolucion(int n, std::vector<int>& piezasUsadas, const int& tamTorre) {
    return (n == tamTorre && piezasUsadas[rojo] > piezasUsadas[azul] + piezasUsadas[verde]);
}

bool esViable(int k, std::vector<int> &solucion, std::vector<int>& piezas, const std::vector<int> &numPiezas, const int& n) {

    if (k >= n){
        return false;
    }

    if (piezas[solucion[k]] > numPiezas[solucion[k]]){
        return false;
    } 
    if (k == 0 && solucion[k] != rojo){
        return false;
    }
    
    if (k > 0 && solucion[k - 1] == verde) {
        return (solucion[k] != verde);
    }

    if (piezas[verde] > piezas[azul]) {
        return false;
    }
    return true;
}

// función que resuelve el problema
void resolver(int k,std::vector<int>&sol, const int & n,std::vector<std::string> colores,
              std::vector<int>& piezas,bool& haySolucion, std::vector<int> numPiezas){
    if(esSolucion(k,piezas,n)){
        haySolucion = true;
        for (int i = 0; i < sol.size(); i++) {
            std::cout << colores[sol[i]] << " ";
        }
        std::cout << "\n";
    }
    for(int i=0;i<colores.size();i++){
       if(k < n){
            sol[k]=i;
            piezas[i]++;
       }
       //siguiente
       if(esViable(k,sol,piezas,numPiezas,n)){
            resolver(k+1,sol,n,colores,piezas,haySolucion,numPiezas);
       }
       if(k < n){
            sol[k]=-1;
            piezas[i]--;
       }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::vector<std::string> colores = {"rojo","azul","verde" };
    std::vector<int> numPiezas;
    int n;
    std::cin >> n;
    for (int k = 0; k < colores.size(); k++) {
        int aux;
        std::cin >> aux;
        numPiezas.push_back(aux);
    }

    if (numPiezas[rojo] == 0 && numPiezas[azul] == 0 && numPiezas[verde] == 0)
        return false;

    bool haySolucion = false;
    std::vector<int> sol = std::vector<int>(n, -1);
    std::vector<int> piezasUsadas = std::vector<int>(colores.size(), 0);    
    resolver(0, sol, n, colores, piezasUsadas, haySolucion, numPiezas);
    if (!haySolucion) std::cout << "SIN SOLUCION" << "\n";
    std::cout << "\n";
    
    
    return true;
    
}
#define DOMJUDGE

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