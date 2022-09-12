//VJ54 Amparo Rubio Bellon

#include <iostream>

int main() {

	int numCasos;
	int n;

	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		std::cin >> n;						//o(1)
		std::cout << 2 * n << std::endl;	// o(1)
	}
	//coste total o(n) donde n= numCasos

	return 0;
}