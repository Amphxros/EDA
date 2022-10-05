#pragma once
#include <vector>
#include <math.h>
class Monomio{
    public:
        Monomio(int b,int e):base(b), exp(e){}
        int base;
        int exp;

};

class Polinomio{
    public:
        Polinomio(){};

        void add(int base, int exp){
            pol.push_back(Monomio(base, exp));
        }
        int resolver(int val) const{
            int res=0;
            for (int i = 0; i < pol.size(); i++) {
                res += pol[i].base * std::pow(val, pol[i].exp);
            }
            return res;
        }
    private:
        std::vector<Monomio> pol;

};