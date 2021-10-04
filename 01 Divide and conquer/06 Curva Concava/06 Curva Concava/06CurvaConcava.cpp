#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include <limits>
int perfilCurvaConcava(const std::vector<int>& v, int ini, int fin, int& min) {
    if (fin == ini)
        return min;
    else if (fin - ini == 1) { //just 2 elems
        if (v[fin] > v[ini] && v[ini] < min) {
            min = v[ini];
        }
        else if(v[fin] < min) {
            min = v[fin];
        }
        return min;
    }

    int mit = (ini + fin) / 2;

    perfilCurvaConcava(v, 0, mit, min);
    perfilCurvaConcava(v, mit + 1, fin, min);


}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n=0;
    std::cin >> n;
    if (n < 0) {
        return false;
    }
    else {
        std::vector<int> v(n);
        for (int i = 0; i < n; i++) {
            std::cin >> v[i];
        }
        int min= std::numeric_limits<int>::max(); //infinito de la libreria de limits

        std::cout<< perfilCurvaConcava(v, 0, n, min);

    // escribir sol

    return true;
    }
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
