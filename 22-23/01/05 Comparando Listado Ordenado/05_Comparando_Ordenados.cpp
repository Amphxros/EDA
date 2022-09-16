// Amparo Rubio Bellon
// VJ 54 


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
#define DOMJUDGE
// O(2*n)
void comparaListados(vector<string> const& v, vector<string> const& w,
    vector<string>& both, vector<string>& a, vector<string>& b) {

		
	/*
		En caso de que no vinieran ordenados habria que hacer
		un std::sort(v.begin, v.end), algoritmo cuyo coste es O(n*log(n))
	
	*/
   
    int m = 0;
    int n = 0;
    while(n<v.size() && m<w.size()) {
        if (v[n] == w[m]) {
            both.push_back(v[n]);
                n++;
                m++;
        }

        else {
            if (v[n] > w[m]) { //si el primero es mayor avanzamos el segundo
                b.push_back(w[m]); m++;

            }
            else { //si no el primero
                a.push_back(v[n]); n++;
            }
        }
    }

    for (n; n < v.size(); n++)
        a.push_back(v[n]);

    for (m; m < w.size(); m++)
        b.push_back(w[m]);


    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    vector<string> both;
    vector<string> a; //solo 1
    vector<string> b; //solo 2
    
    cin >> n;
    vector<string> v(n);

    for (string& e : v) 
        cin >> e;
  
    cin >> n;
   
    vector<string> w(n);
    for (string& e : w) cin >> e;
    
    
    comparaListados(v, w, both, a, b);
    for (string& e : both) cout << e << " ";
    cout << "\n";
    for (string& e : a) cout << e << " ";
    cout << "\n";
    for (string& e : b) cout << e << " ";
    cout << "\n";
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
