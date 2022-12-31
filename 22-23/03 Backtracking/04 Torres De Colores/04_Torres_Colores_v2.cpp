//Amparo Rubio Bellon
//VJ54
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

enum Colores { azul, rojo, verde };

bool esSolucion(int k, std::vector<int>& piezas, const int& tam) {
    return k == tam && piezas[rojo] >= piezas[verde];
}
bool esViable(int k, std::vector<int>& sol, std::vector<int>& piezas, const int& tam) {
   
    if (k >= tam) return false;
    if (k == 0 && sol[k] != rojo) return false;
    if (k > 0 && sol[k - 1] == verde) return sol[k] != verde;
    
    return true;
}
// función que resuelve el problema
void resolver(int k, std::vector<std::string> colors, std::vector<int> piezas, std::vector<int>& sol,int tam) {
    if (esSolucion(k, piezas, tam)) {
        for (int i = 0; i < sol.size(); i++) {
            std::cout << colors[sol[i]] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < colors.size(); i++) {
        
        //marcamos
        if (k < tam) {
            sol[k] = i;
            piezas[i]++;
        }

        //vamos al siguiente si es una pieza valida
        if (esViable(k,sol,piezas,tam)) {
            resolver(k + 1, colors, piezas, sol, tam);
        }

        //desmarcamos
        if (k < tam) {
            piezas[i]--;
            sol[k] = -1;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n<=0)
        return false;
    std::vector<std::string> colors = { "azul","rojo","verde" };
    std::vector<int> piezas = std::vector<int>(colors.size(), 0);
    std::vector<int> sol = std::vector<int>(n, -1);
    
    resolver(0, colors, piezas, sol,n);

    // escribir sol

    return true;

}
#define DOMJUDGE
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
