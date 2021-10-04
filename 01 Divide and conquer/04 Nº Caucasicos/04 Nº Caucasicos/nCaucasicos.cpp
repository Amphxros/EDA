
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
int getPares(const std::vector<int>& v, int ini, int fin, int num) {
    if (fin - ini == 1) {
        if (v[ini] % 2 == 0) {
            num++; 
        }
        return num;
    }
    else {
        int mit = (fin + ini) / 2;
        return getPares(v, ini, mit, num) + getPares(v, mit, fin, num);

    }

}

bool numCaucasicos(const std::vector<int>& v, int ini, int fin) {
    if (fin - ini <= 2) {
        return true;
    }
    else {
        int mit = (ini + fin) / 2;
        
        int paresIzq = getPares(v, ini, mit, 0);
        int paresDer = getPares(v, mit, fin, 0);
   
        return std::abs(paresDer- paresIzq)<= 2 && numCaucasicos(v, ini, mit) && numCaucasicos(v, mit, fin);

    }
}

bool resolver() {
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
        if (numCaucasicos(v, 0, n)) {
            std::cout << "SI" << "\n";
        }
        else {
            std::cout << "NO" << "\n";
        }
        return true;
    }

}

int main()
{
    // Para la entrada por fichero.
   // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 


    while (resolver())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif

    return 0;
}

