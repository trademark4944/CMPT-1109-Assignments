#include <iostream>
#include <fstream>

using namespace std;
fstream mainFile;

class rational_num {
	int numerator, denominator;

public:
	rational_num() : numerator(0), denominator(0) {}
	rational_num(int a, int b) : numerator(a), denominator(b) {}
	rational_num(int a) : numerator(a), denominator(1) {}
	rational_num add(rational_num b) {
		rational_num hold;
		hold.numerator = (numerator * b.denominator) + (b.numerator * denominator);
		hold.denominator = denominator * b.denominator;
		return hold;
	}
	rational_num sub(rational_num b) {
		rational_num hold;
		hold.numerator = (numerator * b.denominator) - (b.numerator * denominator);
		hold.denominator = denominator * b.denominator;
		return hold;
	}
	rational_num mul(rational_num b) {
		rational_num hold;
		hold.numerator = numerator * b.numerator;
		hold.denominator = denominator * b.denominator;
		return hold;
	}
	rational_num div(rational_num b) {
		rational_num hold;
		hold.numerator = numerator * b.denominator;
		hold.denominator = denominator * b.numerator;
		return hold;
	}
	bool less(rational_num b) {
		if ((numerator * b.denominator) < (denominator * b.numerator)) {
			return true;
		}
		else {
			return false;
		}
	}
	void negative() {
		numerator = 0 - numerator;
	}
	void consoleOut() {
		cout << numerator << "/" << denominator << endl;
	}
	void consoleIn() {
		cout << "Numerator: ";
		cin >> numerator;

		cout << "Denominator: ";
		cin >> denominator;
	}
	void fileOut() {
		mainFile.open("output.txt");
		mainFile << numerator << "/" << denominator << endl;
		mainFile.close();
	}
	void fileIn() {
		mainFile.open("input.txt");
		mainFile >> numerator;
		mainFile >> denominator;
		mainFile.close();
	}
};

int main() {
	rational_num A(12,33);
	rational_num B(7);
	rational_num C;
	rational_num D;
	rational_num E;

	C.fileIn();
	D.consoleIn();
	A.consoleOut();
	B.consoleOut();
	C.consoleOut();
	D.consoleOut();

	E = A.add(D);
	E.consoleOut();

	E = B.sub(C);
	E.consoleOut();

	E = A.mul(B);
	E.consoleOut();

	E = C.div(D);
	E.consoleOut();

	D.negative();
	D.consoleOut();

	bool lessThan = A.less(B);
	if (lessThan) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}