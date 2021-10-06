// 01 VariacionesDeUnConjunto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool esValida(std::string& ss, const std::vector<std::string>& v, int k) {
    int i = k - 1; //numero de pal completas
    while (i >= 0 && v[k] != v[i])
        i--;
    return i == -1;
}

void combina(std::vector<std::string>& v,const std::vector<char>& c, int n, int m,int& ind, int k) {
    
    for (k; k < m;) {
        std::string ss = v[k];
        ss += c[ind];
        if (esValida(ss, v, k)) {
            v[k] = ss;
            if (v[k].size() >= n) {
          
                ind = 0;
                std::cout << v[k] << " " << k << "\n";
                combina(v, c, n, m, ind, k + 1);
            }
        }
        else {
            ind = (ind + 1) % c.size();
            combina(v, c, n, m, ind, k);
        }
   }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n;
    std::cin >> m;
    std::cin >> n;

    if (m <= 0) {
        return false;
    }
    else {
        std::vector<char> c(m);

        //rellenamos con el alfabeto (97 en ascii = a) coste O(m) donde m es el numero de letras disponibles
        for (int i = 0; i < m; i++) {
            c[i] = (char)('a'+ i);
        }
        std::vector<std::string> v(powf(m, n));
        int i = 0;
       
        combina(v, c, n, m,i,i);


    // escribir sol

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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
//#endif

    return 0;
}

