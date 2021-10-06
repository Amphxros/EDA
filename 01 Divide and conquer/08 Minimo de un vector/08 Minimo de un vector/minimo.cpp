// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int minimo(const std::vector<int>& v, int ini, int fin) {
    if (fin - ini <= 1) {
       return v[ini];
        
    }
    else {
        int mit= (fin +ini)/2;

        int minIzq = minimo(v, ini, mit);
        int minDer = minimo(v, mit, fin);

        if (minDer > minIzq ) {
            return minIzq;
        }
        else if(minDer < minIzq){
            return minDer;
        }
        else {
            return v[mit];
        }


    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (n <= 0) {
        return false;
    }
    else {
        std::vector<int> v(n);
        for (int i = 0; i < n; i++) {
            std::cin >> v[i];
        }
    std::cout << minimo(v, 0, n)<<"\n";
    return true;
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif

    return 0;
}
