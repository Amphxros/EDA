// Amparo Rubio Bellon
// VJ54


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>

class Polinomio{
    public:
        struct Monomio{
            int base;
            int exp;
            Monomio(int b, int e): base(b), exp(e){}
        };

        Polinomio(){}
        void add(int base,int exp){
            v.push_back(Monomio(base,exp));
        }

        long int resolver(int val){
            long int result=0;
            for(int i=0;i<v.size();i++)
                result+=v[i].base*std::pow(val,v[i].exp);
            
            return result;
        }
    private:
        std::vector<Monomio> v;
};


// O(n)
long int resolver(Polinomio p, int val) {
    
    return p.resolver(val);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int base, exp;
    std::cin>>base;
    if (! std::cin)
        return false;
    std::cin>>exp;
    Polinomio p;
    while (base!=0 || exp!=0)
    {
       p.add(base, exp);
    }
    int n;
    std::cin>>n;

    // escribir sol
    for(int i=0; i<n;i++){
        int val;
        std::cin>>val;
        std::cout<< p.resolver(val)<<" ";
    }
    std::cout<<"\n";

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