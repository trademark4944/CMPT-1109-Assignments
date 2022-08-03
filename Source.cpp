#include <iostream>
using namespace std;

class polynomial {
	int* coeff;
	int size;
public:
	polynomial() { size = 1; coeff = new int[1]; coeff[0] = 0; }
	polynomial(int degree) {
		size = degree + 1;
		coeff = new int[size];
		for (int i = 0; i < size; i++) {
			coeff[i] = 0;
		}
	}
	polynomial()
	polynomial(polynomial& x) {
		size = x.size;
		coeff = new int[size];
		for (int i = 0; i < size; i++) {
			coeff[i] = x.coeff[i];
		}
	}
	~polynomial() {
		delete[] coeff;
		size = 0;
	}
};

int main() {

	return 0;
}