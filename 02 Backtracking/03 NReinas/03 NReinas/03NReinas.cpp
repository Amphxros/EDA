#include <iostream>
#include <vector>
#include<iomanip>
#include <fstream>


//#define DOMJUDGE 
int d_descendente(int x, int y, int nReinas)
{
    return (x - y + (nReinas - 1));
}
int d_ascendente(int x, int y)
{
    return x + y;
}
bool noCome_m(int n, std::vector<int>& sol, int k, std::vector<bool>& filas, std::vector<bool>& diagAsc, std::vector<bool>& diagDesc) {
    return !filas.at(sol[k]);
}
bool esSol_m(int n, std::vector<int>& sol, int k, std::vector<bool>& filas, std::vector<bool>& diagAsc, std::vector<bool>& diagDesc) {

    return k == (n - 1) && noCome_m(n, sol, k, filas, diagAsc, diagDesc);
}
void nReinas(int& numSols,std::vector<int>& sol, int n, int k,std::vector<bool>& filas, std::vector<bool>& diagAsc, std::vector<bool>& diagDesc)
{
    for (int i = 0; i < n; i++) {
        sol[k] = i;
        if (esSol_m(n, sol, k, filas, diagAsc, diagDesc)) {
            numSols ++; //procesamos sol
        }
        else if ((k < (n - 1)) && noCome_m(n, sol, k, filas, diagAsc, diagDesc)) {
            filas[i] = true;
            diagAsc[d_ascendente(k, i)] = true;
            diagDesc[d_descendente(k, i,n)] = true;

            nReinas(numSols, sol, n, k + 1, filas, diagAsc, diagDesc);

            filas[i] = false;
            diagAsc[d_ascendente(k, i)] = false;
            diagDesc[d_descendente(k, i, n)] = false;
        }
   }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(){
    int n;
    std::cin >> n;
    if (n > 0) {
    int numSols = 0;
    std::vector<int>reinas(n);
    std::vector<bool>filas(n);
    std::vector<bool>diagAsc(2 * n - 1);
    std::vector<bool>diagDesc(2 * n - 1);

    nReinas(numSols,reinas, n, 0,filas,diagAsc, diagDesc);
    std::cout << numSols << "\n";
    }

}
int main()
{
    // Para la entrada por fichero.
      // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
