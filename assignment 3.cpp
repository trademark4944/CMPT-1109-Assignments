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
	void add(polynomial a) {
		int ansSize = 0;
		if (a.size > size) {
			ansSize = a.size;
		}
		else {
			ansSize = size;
		}
		polynomial sum(ansSize);

		if (ansSize > size) {
			for (int i = 0; i < size; i++) {
				sum.coeff[i] = coeff[i] + a.coeff[i];
			}
			for (int i = size; i < ansSize; i++) {
				sum.coeff[i] = a.coeff[i];
			}
		}
		else {
			for (int i = 0; i < a.size; i++) {
				sum.coeff[i] = coeff[i] + a.coeff[i];
			}
			for (int i = a.size; i < ansSize; i++) {
				sum.coeff[i] = coeff[i];
			}
		}

		delete[] coeff;
		size = ansSize;
		coeff = new double[size];

		for (int i = 0; i < size; i++) {
			coeff[i] = sum.coeff[i];
		}
	}
	void sub(polynomial b) {
		int ansSize = 0;
		if (b.size > size) {
			ansSize = b.size;
		}
		else {
			ansSize = size;
		}
		polynomial sum(ansSize);

		if (ansSize > size) {
			for (int i = 0; i < size; i++) {
				sum.coeff[i] = coeff[i] + b.coeff[i];
			}
			for (int i = size; i < ansSize; i++) {
				sum.coeff[i] = 0 - b.coeff[i];
			}
		}
		else {
			for (int i = 0; i < b.size; i++) {
				sum.coeff[i] = coeff[i] - b.coeff[i];
			}
			for (int i = b.size; i < ansSize; i++) {
				sum.coeff[i] = coeff[i];
			}
		}

		delete[] coeff;
		size = ansSize;
		coeff = new double[size];

		for (int i = 0; i < size; i++) {
			coeff[i] = sum.coeff[i];
		}
	}
	void mult(polynomial c) {
		int ansSize = (size + c.size - 1);
		polynomial product(ansSize);

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < c.size; j++) {
				product.coeff[(i + j)] += (c.coeff[j] * coeff[i]);
			}
		}

		delete[] coeff;
		size = ansSize;
		coeff = new double[size];

		for (int i = 0; i < size; i++) {
			coeff[i] = product.coeff[i];
		}
	}
};

int main() {

	return 0;
}
