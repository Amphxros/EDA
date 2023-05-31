// Amparo Rubio Bellón
// Vj54

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctype.h>

#include "treemap_eda.h"
#include "list.h"

using namespace std;

typedef map<string, list<int>*> Diccionario;

bool contains(Diccionario dic, string key) {
    map<string, list<int>*>::iterator it = dic.begin();

    while (it != dic.end() && it->clave != key) {
        ++it;
    }

    return it != dic.end();

}

void leerDiccionario(Diccionario& dic, const int & n){
    string line;
    int i=0;
    while(i<n){
        getline(cin, line);
        stringstream lines(line); //procesar la línea
        string key;

        while(lines >> key){
           if(key.length()>2){
                for(int j=0; key[j];j++){
                    key[j]=tolower(key[j]);
                }
                if(!contains(dic,key)){
                    list<int>* l = new list<int>();
                    l->push_back(i+1);
                    dic.insert({key,l});
                }
                else{
                    if(dic.at(key)->back() != i+1)
                        dic.at(key)->push_back(i + 1); //si la clave ya existia, modificamos su lista
                }
            }
        }
        i++;

    }

}

// función que resuelve el problema
void resolver( Diccionario dic) {
    map<string, list<int>*>::iterator it = dic.begin();
    while(it != dic.end()){
        cout<< it->clave << " ";
        auto lit = it->valor->begin();
        while (lit!=it->valor->end())
        {
            cout << *lit << " ";
            lit++;
        }
        
        cout << "\n";
        
        ++it;
    }
    
}


#define DOMJUDGE
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n<=0)
        return false;
    Diccionario dic;
    string l;
    getline(cin,l);
    leerDiccionario(dic,n);
    resolver(dic);

    
    return true;
    
}

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
