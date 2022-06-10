#include <iostream>
#include <string>
using namespace std;

bool idiotProofing(char barcode[18], int length) {
	int asciiCodeHolder = 0;
	bool areYouIdiot = false;
	
	for (int i = 0; i < length; i++) {
		asciiCodeHolder = barcode[i];
		if (asciiCodeHolder < 48 || asciiCodeHolder > 57) {
			areYouIdiot = true;
			cout << "ERROR: Invalid Input Within Product Code" << endl;
			break;
		}
		areYouIdiot = false;
	}
	
	
	return areYouIdiot;
} 

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
	string barcodeHolder;
	int staticCastHolder, oddPositions = 0, evenPositions = 0, stringLength;
	bool idiotLmao = false;
	
	cout << "Enter first " << length << " digits of your product code: ";
	cin >> barcodeHolder;
	stringLength = barcodeHolder.length();

	if (stringLength != length) {
		cout << "ERROR: Invalid Product Code Length" << endl;
		return;
	}

	for (int i = 0; i < length; i++) {
		productCodeArray[i] = barcodeHolder.at(i);
	}

	idiotLmao = idiotProofing(productCodeArray, length);
	if (idiotLmao == true) {
		return;
	} 

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

	productCodeArray[length] = checkDigit(oddPositions, evenPositions);

	cout << "The check digit is " << productCodeArray[length] << endl;
	cout << "The product code is ";
	for (int i = 0; i <= length; i++) {
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
			length = 7;
			processProductCode(length);
			break;
		case 2:
			length = 11;
			processProductCode(length);
			break;
		case 3:
			length = 12;
			processProductCode(length);
			break;
		case 4:
			length = 13;
			processProductCode(length);
			break;
		case 5:
			length = 17;
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
