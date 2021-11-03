#pragma once
#include <iostream>

class Horas
{
public:
	Horas() {}
	Horas(int h, int m, int s):
		hh(h), mm(m), ss(s)
	{
		
		isValid = !(h <= -1 || h>23 || m <=-1 || m>59 || s <=-1 || s > 59);
		
	}
	~Horas() {}

	bool isCorrect() { return isValid; }
	bool operator < (const Horas& h) const {
		if (isValid && h.isValid) {
			if (h.hh != hh) {
				return h.hh > hh;
			}
			else if (h.mm != mm) {
				return h.mm < mm;
			}
			else {
				return h.ss > ss;
			}
		}

	}
	
	void print(std::ostream& out = std::cout) {
		
		if (isValid) {
			if (hh < 10)
				out << "0";
			out << hh << ":";

			if (mm < 10)
				out << "0";
			out << mm << ":";

			if (ss < 10)
				out << "0";
			out << ss;
		}
		else {
			out << "ERROR";
		}
	}



private:
	int hh, mm, ss;
	bool isValid = true;
};

inline std::istream & operator>>(std::istream &in, Horas& hora) {
	int h, m, s;
	char flag;
	in >> h >> flag >> m >> flag >> s;
	hora = Horas(h, m, s);
	return in;
}

inline std::ostream& operator<<(std::ostream& out, Horas hora) {
	hora.print(out);
	return out;
}