// VJ50 AMPARO RUBIO BELLON
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <set>

// O(n) donde n=caracteres del string
int conversor(std::string entrada) {               
    return std::stoi(entrada);
}
// O(1)
int elevado(int a) {                            
    return a * a;
}
// O(n) donde n= tam vector
int sumador(std::vector<int> ristra) {              
    int suma = 0;
    for (int i = 0; i < ristra.size(); i++) {
        suma += ristra[i];
    }
    return suma;
}
// O(a*n) donde: a=caracteres del string, n=tam del vector
std::vector<int> descomponedor(int largo) {          
    std::vector<int>separado;
    std::string datos = std::to_string(largo);
    int it = 0;
    while (it < datos.size()) {
        separado.push_back(datos[it] - 48);
        it++;
    }
    return separado;
}
// O(n) 
void elevador(std::vector<int>& separado) {           
    for (int i = 0; i < separado.size(); i++) {
        separado[i] = elevado(separado[i]);
    }
}
void recursivo(std::set<int>& historico, const int & num) {    
    std::vector<int>separado = descomponedor(num);
    elevador(separado);
    int suma = sumador(separado);
    if (historico.find(suma) != historico.end()) {
        if (suma == 1) {
            historico.insert(1);
            std::cout << 1;
        }
        else {
            historico.insert(suma);
            std::cout << suma << " ";
            historico.insert(0);
            std::cout << 0;
        }
    }
    else {
        historico.insert(suma);
        std::cout << suma << " ";
        recursivo(historico, suma);
    }
}

// función que resuelve el problema
std::set<int> numFelices(std::string datos) {
    std::set<int> historico;
    int d = conversor(datos);       // Paso del valor inicial a Int
    historico.insert(d); //es el primero y caso especial
    std::cout << datos << " ";
    recursivo(historico, d);
    return historico;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string dato;
    std::cin >> dato;
    if (!std::cin)
        return false;

    std::set<int> sol = numFelices(dato);
    // escribir sol

    std::cout << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}