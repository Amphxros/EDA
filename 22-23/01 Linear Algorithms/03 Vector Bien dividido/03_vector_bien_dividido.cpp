// VJ54 Amparo Rubio Bellon

#define DOMJUDGE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// O(n)
bool resolver(const std::vector<int>& v, int p) {
   
    int j = 0, k = 0;

    for (int i = 0; i <= p; i++) {
        j += v[i];
    }
    for (int i = p+1; i < v.size(); i++) {
        k+= v[i];
    }
    //std::cout << j << " " << k;
    return k =< j;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, p;
    std::cin >> n;
    std::cin >> p;
    std::vector <int> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i];
   
    // escribir sol
    if (resolver(v, p)) {
        std::cout << "SI" << "\n";
    }
    else {
        std::cout << "NO" << "\n";
    }

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