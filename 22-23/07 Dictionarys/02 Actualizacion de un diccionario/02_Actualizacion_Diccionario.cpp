// Amparo Rubio Bellon  
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>

#include <sstream>
#include <string>

#include "treemap_eda.h"

using namespace std;

typedef map<string, int> Diccionario;


// función que resuelve el problema
void resolver(string pre, string post) {
    Diccionario dic;
    //primera parte del dic
    string key="";
    string value = "";
    string result = "";

    int j = 0;

    ///TODO ESTO SERIA MAS FACIL SI PUEDIERA SEPARAR POR ESPACIOS 
    for (int i = 0; i < pre.size(); i++) {
        if (pre[i] == ' ') {
            if (j % 2 != 0) {
                int num = stoi(value);
                dic.insert({key, num});
                key = value = ""; //resets 
            }
            j++;
        }
        else if (j % 2 == 0) {
            key += pre[i];
        }
        else {
            value += pre[i];
        }
    }
    key = value = ""; //resets 
    j = 0;

    for (int i = 0; i < post.size(); i++) {
        if (post[i] == ' ') {
            if (j % 2 != 0) {
                int num = stoi(value);
                int rslt = dic.at(key);

                if (rslt == -1) {
                   //no esta en el diccionario
                }
                else {
                    //esta
                    
                }

            }
            j++;
        }
        else if (j % 2 == 0) {
            key += post[i];
        }
        else {
            value += post;
        }
    }
  

    


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   string pre,post;
   getline(cin,pre); //primera linea
   getline(cin,post); //segunda linea


   
    
    
}

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
     system("PAUSE");
     #endif
    
    return 0;
}