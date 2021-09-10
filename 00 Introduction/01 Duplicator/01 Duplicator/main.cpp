#include <iostream>


int result(int n) {
	return 2 * n;
}
void resolve() {
	int j;
	std::cin >> j;
	j = result(j);
	std::cout << j;

}

int main() {

	int numCasos=0;

	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		resolve();
	}

	return 0;
}