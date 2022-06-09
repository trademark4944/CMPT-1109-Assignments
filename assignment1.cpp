#include <iostream>
#include <math.h>
using namespace std;

char checkDigit(int odd, int even) {
	int total, remainder, hold;
	char returningChar;

	total = odd + even;
	remainder = total % 10;
	hold = total - remainder;

	if (hold != total) {
		hold += 10;
	}

	returningChar = (hold - total + 48);

	return returningChar;
}

void processProductCode(int length) {
	char productCodeArray[18];
	int staticCastHolder, oddPositions = 0, evenPositions = 0;
	cout << "Enter first " << (length - 1) << " digits of your product code: ";
	cin >> productCodeArray;

	for (int i = 0; i < length; i++) {
		if (i % 2 == 0) {
			staticCastHolder = productCodeArray[i] - 48;
			oddPositions += staticCastHolder;
		}
	}
	oddPositions *= 3;

	for (int i = 0; i < length; i++) {
		if (i % 2 != 0) {
			staticCastHolder = productCodeArray[i] - 48;
			evenPositions += staticCastHolder;
		}
	}

	productCodeArray[7] = checkDigit(oddPositions, evenPositions);

	cout << "The check digit is " << productCodeArray[7] << endl;
	cout << "The product code is ";
	for (int i = 0; i < 8; i++) {
		cout << productCodeArray[i];
	}
	cout << endl;
}

int main() {

	bool cont = true;
	int codeType, length;

	cout << "Check Product Calculator" << endl;

	while (cont == true) {
		
		cout << "------------------------" << endl;
		cout << "1. EAN-8" << endl << "2. UPC-A" << endl << "3. EAN-13" << endl << "4. EAN-14" << endl << "5. SSCC" << endl << "6. Quit" << endl;
		cout << "------------------------" << endl;
		cout << "Choose your product code type: ";
		cin >> codeType;
		
		switch (codeType) {
		case 1:
			length = 8
			processProductCode(length);
			break;
		case 6:
			cout << endl << "Exitting..." << endl;
			cont = false;
			break;
		default:
			cout << "ERROR: Invalid Menu Selection" << endl;
			break;
		}
	}

	return 0;
}
