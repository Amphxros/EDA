//Amparo Rubio Bellon
//VJ54

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;

//O(n*k/2) donde k=lon
void invertirSegmento(list<int>& l, int pos, int lon){
    auto ini = l.begin(), end = l.end();
    

    for (int i = 0; i < pos - 1; i++)
        ini++;

    for (int j = l.size(); j > pos + lon - 2; j--)
        end--;

    if (ini != end) {
        //O(n/2)
        for (int i = lon / 2; i > 0; i--) {
            swap(*ini, *end); //O(2)
            ini++;
            end--;
        }
    }

}

#define DOMJUDGE
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, pos, longitud, elem;
    list<int> l;
    cin >> n;
    if (!std::cin) return false;
    cin >> pos >> longitud;

    // Leo la lista
    for (int i=0; i < n; ++i) { cin >> elem; l.push_back(elem); }

    // Llamada a la funcion pedida
    invertirSegmento(l,pos,longitud);

    // Muestro la lista
    for (int& e : l) cout << e << " ";
    cout << "\n";

    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input1.txt");
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