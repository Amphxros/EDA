// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// parte por la mitad y comprueba que en su segmento v[fin] - v[ini] son dispersos asi como recursivamente sus mitades
//coste O(n*log(n)) donde n= dimension del vector
bool suficientementeDisperso(const std::vector<int> & v,int k, int ini, int fin) {
    if (fin - ini == 1) {
        return std::abs(v[fin] - v[ini]) >= k;
    }
    else{
        int mit = (ini + fin) / 2;

        bool mitIzq = suficientementeDisperso(v, k, ini, mit);
        bool mitDer = suficientementeDisperso(v, k, mit+1, fin);

        return std::abs(v[fin] - v[ini]) >= k && mitIzq && mitDer;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n = 0;
    std::cin >> n;
    
    
    if (!std::cin || n<=0) {
        return false;
    }
  
    else {
        int k;
        std::cin >> k;
        std::vector<int> v(n);

        for (int i = 0; i < n; i++) {
            std::cin >> v[i];
        }

        if (n == 1 || suficientementeDisperso(v, k, 0, n - 1)) { //1 elemento ya es disperso
            std::cout << "SI" << "\n";
        }
        else {
            std::cout << "NO" << "\n";
        }

    }
    

    return true;

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
