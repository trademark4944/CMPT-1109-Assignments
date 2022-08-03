#include <iostream>
using namespace std;

class polynomial {
	double* coeff;
	int size;
public:
	polynomial() { size = 1; coeff = new double[1]; coeff[0] = 0; }
	polynomial(int degree) {
		size = degree + 1;
		coeff = new double[size];
		for (int i = 0; i < size; i++) {
			coeff[i] = 0;
		}
	}
	polynomial(int degree, double inputs[]) {
		size = degree + 1;
		coeff = new double[size];
		for (int i = 0; i < size; i++) {
			coeff[i] = inputs[i];
		}

	}
	polynomial (polynomial& x) {
		size = x.size;
		coeff = new double[size];
		for (int i = 0; i < size; i++) {
			coeff[i] = x.coeff[i];
		}
	}
	~polynomial() {
		delete[] coeff;
		size = 0;
		coeff = nullptr;
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
		polynomial difference(ansSize);

		if (ansSize > size) {
			for (int i = 0; i < size; i++) {
				difference.coeff[i] = coeff[i] + b.coeff[i];
			}
			for (int i = size; i < ansSize; i++) {
				difference.coeff[i] = 0 - b.coeff[i];
			}
		}
		else {
			for (int i = 0; i < b.size; i++) {
				difference.coeff[i] = coeff[i] - b.coeff[i];
			}
			for (int i = b.size; i < ansSize; i++) {
				difference.coeff[i] = coeff[i];
			}
		}

		delete[] coeff;
		size = ansSize;
		coeff = new double[size];

		for (int i = 0; i < size; i++) {
			coeff[i] = difference.coeff[i];
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

	double search(int degree) {
		return coeff[degree];
	}

	void assign(int degree, double value) {
		coeff[degree] = value;
	}
};

int main() {
	double array[] = { 1,2,3 };
	double array2[] = { 1, 1 };
	polynomial num1(2, array);
	polynomial num2(1, array2);

	num1.print();
	num2.print();

	//num1.add(num2);

	//num1.print();

	//num1.sub(num2);

	num1.mult(num2);

	num1.print();

	double val = num1.search(2);
	cout << val << endl;

	num1.assign(2, 7);
	num1.print();

	return 0;
}
