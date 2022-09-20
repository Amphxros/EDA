// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(const std::vector<int> & v, int ini, int fin, int& min, int& max) {
    
    if(fin-ini ==1){
        if(v[ini]< min){
            min=v[ini];
        }
        if(v[ini]>max){

            max=v[ini];
        }

        return min==v[ini] || max==v[ini];
    }
    else{
        int mit= (fin + ini)/2;
        int min_izq= std::numeric_limits<int>::max();
        int max_izq= std::numeric_limits<int>::min();
        
        int min_der= std::numeric_limits<int>::max();
        int max_der= std::numeric_limits<int>::min();

        bool mitIzq= resolver(v,0,mit,min_izq,max_izq);
        bool mitDer= resolver(v,mit,fin,min_der,max_der);

        return max_der>=max_izq && min_izq<=min_der;

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> v;

    int n=-1;
    while(n==0){
        std::cin>>n;
        v.push_back(n);
    }
    v.pop_back();
    
    // escribir sol
    n=(int)(v.size()-1);
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    if(resolver(v,0,n,min,max)){
        std::cout <<"SI"<< "\n";
    }
    else{
          std::cout <<"NO"<< "\n";
    }
    
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