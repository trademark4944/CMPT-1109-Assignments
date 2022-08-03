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
	polynomial(int degree, int inputs[]) {
		size = degree + 1;
		coeff = new int[size];
		for (int i = 0; i < size; i++) {
			coeff[i] = inputs[i];
		}

	}
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
	polynomial operator=(polynomial& x) {
		size = x.size;
		coeff = new double[size];
		for (int i = 0; i < size; i++) {
			coeff[i] = x.coeff[i];
		}
	}

	void print() {
		for (int i = (size - 1); i >= 0; i--) {
			if (i == 0) {
				cout << coeff[i] << endl;
			}
			else {
				cout << coeff[i] << "(X ^ " << i << ") + ";
			}
		}
	}
};

int main() {

	return 0;
}
