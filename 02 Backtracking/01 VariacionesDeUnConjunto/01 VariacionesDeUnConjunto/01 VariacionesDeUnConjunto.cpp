// 01 VariacionesDeUnConjunto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool esValida(std::string& ss, const std::vector<std::string>& v, int k) {
    int i = 0;
    while (i < k && ss != v[i]) {
        i++;
    }
    return i == k - 1;
}

bool esCompleta(std::string& ss, const std::vector<std::string>& v, int& k,int m) {
    return ss.size()==m;
}

void combina(std::vector<std::string>& v,const std::vector<char>& c,int k,int n,int m) {
   
    for (int i = 0; i < n; i++) {
        std::string ss = v[k];
        ss += c[m];
        if (esValida(ss, v, k)) {
            v[i] = ss;
            if (esCompleta(v[i], v, k, m)) {
                std::cout << v[i] << " ";
                combina(v, c, k + 1, n, 0);
            }
            
        }
        else {
            combina(v, c, k, n, m + 1);
        }

    }
}

bool resuelveCaso() {
    int n = 0, m = 0;
    std::cin >> n;
    std::cin >> m;


}


int main()
{
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

