// Amparo Rubio Bellon


#include <iostream>
#include <vector>


// O(n)  
int resolver(std::vector<int> v, const int& media) {
    
    int suma=0;

    for(int i=0;i<v.size();i++){
        suma+=v[i];    
    }

    return (int)(media* (v.size() + 1) - suma);    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n=0;
    int mediaDeseada=0;
    std::cin >> n;
    if (n<=0)
        return false;
    
    std::vector<int> v(n);
    for(int i=0;i<n;i++){
        std::cin >> v[i];
    }

    std::cin >> mediaDeseada;

    int sol=resolver(v,mediaDeseada);

    // escribir sol
    if(sol<=10)
        std::cout<< sol<< "\n";
    else std::cout << "IMPOSIBLE" << "\n";

    
    return true;
    
}
int main() {
   
    while (resuelveCaso())
        ; 
    return 0;
}
