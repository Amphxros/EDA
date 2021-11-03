// Nombre del alumno .....
// VJ50 Amparo Rubio Bellon
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//T(n) = c0 si n=1
//T(n) = T(n/2)+c1 si n>1
//T(n) pertenece a O(log n)-> a =1, b=2 por lo que a=b^k (1=b^0) ^ n^k *log n = log n
int minimo(const std::vector<int>& v, int ini, int fin) {
    int min;
    if (fin - ini == 1) {
        if (v[ini] > v[fin])
            min = v[fin];
        else
            min = v[ini];
    }
    else {
        int mit = (fin + ini) / 2;
        if (v[ini] > v[mit])
            min = minimo(v, mit, fin);
        else
            min = minimo(v, ini, mit);
    }
    return min;
}


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
    std::cout << minimo(v, 0, n-1)<<"\n";
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
