#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<list>
#include <map>
class VentaLibros
{
public:
    VentaLibros()=default;

    // Añade un nuevo libro al sistema
    void nuevoLibro(std::string const& titulo, int unidades){
        libros.push_back({ titulo,unidades });
    }
    
    // Compra un libro
    void comprar(std::string const& titulo){
        auto it = libros.begin();
        if (it == libros.end()) {
            return; //lista vacia
        }

        while (it != libros.end() && it->first != titulo)
        {
            ++it;
        }

        int i= it->second--;
        if (i == 0) {
            elimLibro(titulo);
        }
        else {
            it->second = i;
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
        if (it == libros.end()) {
            return; //lista vacia
        }

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
    
    std::list<std::string> top10() const{
        std::list<std::pair<std::string, int>> list = libros;
        std::list<std::string> top = std::list<std::string>(10);

        std::sort(list.begin(), list.end()); //REVISAR COMO ORDENAR TENIENDO EN CUENTA EL 2
        
        int i = 0;
        for (auto it = libros.end(); it != libros.begin() && i<10; it--) {
            top.push_back(it->first);
            i++;
        }
       
        return top;

    }
    private:
        std::list<std::pair<std::string, int>> libros;
        
};