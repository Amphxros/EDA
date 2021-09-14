#include <iostream>
#include <vector>


void result() {
	int n;
	std::cin >> n;
	std::vector<int> vec;

	//introducimos los datos en 1 vector O(n) donde n = nº de hermanos= tamaño del vector
	for (int i = 0; i < n; i++) {
		int d;
		std::cin >> d;
		vec.push_back(d);
	}


	int j = 1;
	bool crec = false;

	//determina si es creciente o drececiente
	if (vec[j] > vec[j - 1]) {
		crec = true;
		j++;
	}
	
	// O(n-1) donde n= nºhermanos 
	while (crec && j < n && vec[j] > vec[j - 1]) {

		j++;
		
	}

	//similar al anterior solo que SOLO entra si no ha entrado en el primero
	j = 1;
	while (!crec && j < n && vec[j] < vec[j - 1]) {
		j++;
	}

	//constante en este caso
	if (j <= n) {
		std::cout << "DESCONOCIDOS" << std::endl;
	}
	else {
		std::cout << "DALTON" << std::endl;
	}
}

int main() {
	
	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		result();
	}


	return 0;


}