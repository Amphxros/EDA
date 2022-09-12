#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

bool parcialmenteOrdenado(const std::vector<int>& v, int ini, int fin, int& min, int& max) {
    if (fin - ini == 1) {
        if (v[ini] < min)
            min = v[ini];
        if (v[ini] > max)
            max = v[ini];

        return  min == v[ini] || max==v[ini];
    }
    else {
        int mit = (fin + ini) / 2;
        int minIzq_ = std::numeric_limits<int>::max();
        int maxIzq_ = std::numeric_limits<int>::min();
        bool mitIzq = parcialmenteOrdenado(v, 0, mit, minIzq_, maxIzq_);
        
        int minDer_ = std::numeric_limits<int>::max();
        int maxDer_ = std::numeric_limits<int>::min();
        bool mitDer = parcialmenteOrdenado(v, 0, mit, minDer_, maxDer_);



        return maxDer_ >= maxIzq_ && minIzq_ <= minDer_;
    }

}

bool parcialmenteOrdenado(const std::vector<int>& v) {
    int min, max;
    return parcialmenteOrdenado(v, 0, v.size(), min, max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int e;
    std::cin >> e;
    if (e <= 0) return false;
    std::vector<int> sec;
    while (e != 0) {
        sec.push_back(e);
        std::cin >> e;
    }
    std::cout << (parcialmenteOrdenado(sec) ? "SI" : "NO") << std::endl;
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
    //system("PAUSE");
#endif

    return 0;
}