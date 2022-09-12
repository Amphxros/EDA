#include <iostream>
#include <vector>

void result() {
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int c;
		std::cin >> c;
		v[i] = c;
	}
	int nPicos=0, nValles=0;
	int k = 2;

	//coste O(n-2)
	while (k < n) {
		
		if (v[k - 1] > v[k] && v[k - 2] < v[k - 1]) {
			nPicos++;
		}
		else if (v[k - 1] < v[k] && v[k - 2] > v[k - 1]) {
			nValles++;
		}
		k++;
		
	}
	
	std::cout << nPicos << " " << nValles << std::endl;



}
int main() {

	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		result();
	}

	return 0;
}