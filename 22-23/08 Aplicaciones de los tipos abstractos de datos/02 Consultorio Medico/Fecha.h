#pragma once


class Fecha
{
public:
	Fecha(int d, int h, int m);
	~Fecha();

	void print() const;
	
	int getDia() const { return dia; };
	int getHora() const { return hora; };
	int getMin() const { return min; };


	bool operator < (const Fecha& f)const {
		if (dia < f.dia) {
			return true;
		}
		else if (dia == f.dia) {
			if (hora < f.hora) {
				return true;
			}
			else if (hora == f.hora) {
				if (min < f.min) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

private:
	int dia;
	int hora;
	int min;
};

