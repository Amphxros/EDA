//Amparo Rubio
//VJ 54
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// coste de O(log(n)) ya que 2^k=n seria el ultimo caso recursivo
int resolver(const vector<int>& sec, int ini, int fin) {
    int min, mit;
    if (fin - ini == 1) {
        min = sec[ini];
    }
    else if (fin - ini == 2) {
        if (sec[ini] >= sec[ini+1]) {
            min = sec[ini + 1];
        }
        else {
            min = sec[ini];
        }
    }
    else {
        mit = (fin + ini) / 2;
        if (sec[mit] > sec[mit - 1] && sec[mit] < sec[mit + 1])
            min = resolver(sec, ini, mit);
        else if (sec[mit]<sec[mit - 1] && sec[mit]> sec[mit + 1])
            min = resolver(sec, mit, fin);
        else
            min = sec[mit];

    }
    return min;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!cin) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << resolver(sec, 0, n) << endl;
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