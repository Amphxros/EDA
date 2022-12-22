#pragma once
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

#include <list>

using namespace std;

struct Libros {
    std::string titulo;
    int unidades;
    int ventas;
};

class VentaLibros
{
public:
    VentaLibros() {
        
    };

    // Añade un nuevo libro al sistema
    void nuevoLibro(std::string const& titulo, int unidades){
        Libros l= {titulo, unidades, 0};

        if (libros.count(l)==0){
            libros.insert({l,0});
        }
        else{
            libros[l].unidades+=unidades;
        }
    }
    
    // Compra un libro
    void comprar(std::string const& titulo){
        if(libros.count(titulo)>0){
            libros[titulo].unidades--;
            libros[titulo].ventas++;
            numVenta++;
            regVentas.push_back(titulo);
        }
        else{
            throw std::domain_error("Libro no disponible");
        }
    }

    // Devuelve true si el libro está en el sistema O(n)
    bool estaLibro(std::string const& titulo) const{
        auto it= libros.begin();
        while (it!=libros.end()){
            if (it->first.titulo==titulo){
                return true;
            }
            it++;
        }
        return false;

    }

    // Elimina un libro del sistema
    void elimLibro(std::string const& titulo){
        
     auto it= libros.begin();
        while (it!=libros.end() && it->first.titulo!=titulo){
            it++;
        }
        libros.erase(it);
        

    }

    // Devuelve el número de ejemplares de un libro O(n)
    int numEjemplares(std::string const& titulo) const{
       
     auto it= libros.begin();
        while (it!=libros.end() && it->first.titulo!=titulo){
            it++;
        }
        return it->first.unidades;
    }
    
    //O(nlogn)
    std::list<std::string> top10(){
        
 

    }
    private:

        int numVenta=0;
        std::map<Libros, int> libros;
        std::list<std::string> regVentas;


        
};