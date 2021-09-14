#include <iostream>

int main() {
	int d;
	std::cin >> d;
	while (d != 0) {
		std::cout << 2 * d << std::endl;
		std::cin >> d;
	}

	return 0;
}