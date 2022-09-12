#include <iostream>
#include <vector>

void result() {
	int n;
	std::cin >> n;

	int p;
	std::cin >> p;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int c;
		std::cin >> c;
		v[i] = c;
	}
	
	int j=0,k=0;
	
	for (int i = 0; i <= p; i++) {
		j += v[i];
	}

	for (int i = p + 1; i < n; i++) {
		k += v[i];
	}

	if (k > j) {
		std::cout << "SI" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
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