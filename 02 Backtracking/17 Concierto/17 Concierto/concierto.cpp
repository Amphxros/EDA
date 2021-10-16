#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


int canPlay(vector<vector<bool>> cons, int k, const int& dim) {
    
    int i = 0;
    while (i<dim && !cons[k][i])
    {
        i++;
    }

    return i;
}


// función que resuelve el problema
int resolver(vector<vector<int>> ben, vector<vector<bool>> cons, int k, int m, int n) {
    for (int i = 0; i < n; i++) {
        int j = canPlay(cons, k, sqrt(n));
        if (j<=sqrt(n)) {
            m += ben[k][j];

            resolver(ben, cons, k + 1, m, n);
        }
    }
  
    return m;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<vector<int>> beneficios(n, vector<int>(n));
    vector<vector<bool>> consentimientos(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> beneficios[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            consentimientos[i][j] = b;
        }

    int r= resolver(beneficios, consentimientos, 0, 0,n);
    if (r < 0) {
        cout << r << "\n";
    }
    else {
        cout << "NEGOCIA CON LOS ARTISTAS" << "\n";
    }
    // salida
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
