// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int resolver(const std::vector<int>& v, int pri, int sig, const int & n) {
    if (sig == n-1) {
        if (v[pri] != v[sig])
            return sig;
        return 0;
    }
    else {
        if (v[pri] != v[sig]) {
            if (resolver(v, sig, sig + 1, n) != 0) {
                return sig;
            }
            else {
                return pri;
            }
        }
        else {
           return resolver(v, sig , sig + 1, n);
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    // escribir sol
    std::cout << resolver(v, 0,1,n) << "\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif

    return 0;
}