#pragma once
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

#include <list>

using namespace std;

class VentaLibros
{
public:
    VentaLibros() {
        libros = std::list < std::pair<std::string, int>>();
    };

    // Añade un nuevo libro al sistema
    void nuevoLibro(std::string const& titulo, int unidades){
        
        libros.push_back({ titulo,unidades });
    }
    
    // Compra un libro
    void comprar(std::string const& titulo){
        auto it = libros.begin();
       
        while (it != libros.end() && it->first != titulo)
        {
            ++it;
        }

        int i= it->second--;
        if (i == 0) {
            elimLibro(titulo);
        }
      


    }

    // Devuelve true si el libro está en el sistema O(n)
    bool estaLibro(std::string const& titulo) const{
        auto it = libros.begin();
        if (it == libros.end()) {
            return false; //lista vacia
        }

        while (it!= libros.end() && it->first !=titulo)
        {
            ++it;
        }

        return it != libros.end();

    }

    // Elimina un libro del sistema
    void elimLibro(std::string const& titulo){
        
        auto it = libros.begin();

        while (it != libros.end() && it->first != titulo)
        {
            ++it;
        }

        if (it != libros.end()) {
            libros.erase(it);
        }

    }

    // Devuelve el número de ejemplares de un libro O(n)
    int numEjemplares(std::string const& titulo) const{
        auto it = libros.begin();
        if (it == libros.end()) {
            return 0; //lista vacia
        }

        while (it != libros.end() && it->first != titulo)
        {
            ++it;
        }
        if (it == libros.end()) return 0;

        return it->second;
    }
    
    //O(nlogn)
    std::list<std::string> top10(){
        
        std::list<std::string> top = std::list<std::string>();

        //O (nlogn) al igual que el std::sort
        libros.sort([](const auto& x, const auto& y) { return x.second > y.second; });

        int i = 0;
        for (auto it = libros.begin(); it != libros.end() && i<10; ++it) {
            top.push_back(it->first);
            i++;
        }
       
        return top;

    }
    private:
        std::list<std::pair<std::string, int>> libros;
        
};