// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <math.h>

#define DOMJUDGE
bool resolver(std::set<int> s, int n) {
    bool feliz = true;
    std::cout << n << " ";
    s.insert(n);
    while (n != 1 && feliz) {
        int aux, result = 0;
        while (n != 0) {
            aux = n % 10;
            result += aux*aux;
            n /= 10;
        }
        n = result;
        std::cout << result << " ";
        if (s.find(result) != s.end()) 
            feliz = false;
        else 
            s.insert(result);
    }
    
    return feliz;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num = 0;
    std::cin >> num;
    if (!std::cin) {
        return false;
    }
    std::set<int> s;

    std::cout << resolver(s, num) << " " << "\n";

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
    system("PAUSE");
#endif

    return 0;
}