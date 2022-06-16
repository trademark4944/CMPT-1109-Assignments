#include <iostream>
#include <string>
using namespace std;

bool errorCheck(char barcode[18], int length) { //double cheching that all user inputs are valid chars, integers but in char form
	int asciiCodeHolder = 0; // a variable to hold ascii codes of chars
	
	for (int i = 0; i < length; i++) { // we itterate through every indice of the array with a for loop
		asciiCodeHolder = barcode[i]; // we determine the ascii code of the character 
		if (asciiCodeHolder < 48 || asciiCodeHolder > 57) { /*test wether the ascii code is not within the range of 48 to 57,
															the corresponding codes for the numbers 0 through 9 */
			cout << "ERROR: Invalid Input Within Product Code" << endl;
			return true; // if the code is not within the range we return that an error is present, it is TRUE that there is an error
		}
		return false; //otherwise, if all ascii codes are valid then we return that it is FALSE that there is an error 
	}
} 

char checkDigit(int odd, int even) { //calculating check digit with values even and odd gathered from the processProductCode() function
	int total, remainder, hold;

	total = odd + even; //sum the odd and the even
	remainder = total % 10; //determine the remainder (modulus %) of the total divided by ten
	hold = total - remainder; //remove the remainder from the total in order to make it an even multiple of ten ex. 76 -> 70

	if (hold != total) { /*check if the total and the hold variable are not the same, if they are not we add ten to hold
						 in order to find the next multiple of ten ex. if total = 76, next multiple of ten hold = 70 + 10 = 80*/
		hold += 10;
	}

	return (hold - total + 48); /*we return the next multiple of ten, hold, minus the intial total. which is an integer, 
								in order to make it the needed char we add 48 to find the corresponding ascii code */
}

void processProductCode(int length) {
	char productCodeArray[18];
	string barcodeHolder;
	int staticCastHolder, oddPositions = 0, evenPositions = 0, stringLength;
	bool errors = false;
	
	cout << "Enter first " << length << " digits of your product code: ";
	cin >> barcodeHolder; //gathering user input of the product code without the check digit
	stringLength = barcodeHolder.length(); // determining length of the input, how many characters were inputted by the user

	if (stringLength != length) { /*the main reason we use a string variable is to be able to 
								  easily access the length of the user input in order to test wether the 
								  user input is of correct length for the selected product code type*/
		cout << "ERROR: Invalid Product Code Length" << endl;
		return;
	}

	for (int i = 0; i < length; i++) { /* since we initially sent the user input to a string variable
									   we must now go through and individually send each character of the string to 
									   it's corresponding indice in the aray*/
		productCodeArray[i] = barcodeHolder.at(i); /*the string.at() function from the string library allows us to 
												   access specific characters within the string at specified indices
												   similar to accessing specific indices on an array*/
	}

	errors = errorCheck(productCodeArray, length); /*here we send the array in to the errorCheck() function to 
												   be searched for incorrect inputs, if the function returns
												   that it is true that errors are present we exit the processProductCode()
												   function*/
	if (errors == true) {
		return;
	} 

	for (int i = 0; i < length; i++) { //for loop to sum the integers at the odd positions
		if (i % 2 == 0) { /*if statement determines whether indice is odd or not, we use modulus (%)
						  to determine wether it is cleanly divisible by 2. since array indices begin at 0,
						  the odd positions are indices 0, 2, 4, 6 etc. */
			staticCastHolder = productCodeArray[i] - 48;
			oddPositions += staticCastHolder;
		}
	}
	oddPositions *= 3;

	for (int i = 0; i < length; i++) { //for loop to sum the integers at the even positions
		if (i % 2 != 0) { /*if statement determines whether the indice is even or not, as for 
						  loop goes through every possible indice*/
			staticCastHolder = productCodeArray[i] - 48; /*we use a holder variable to store 
														 the ascii code as the array is set to be char and we
														 must manipulate the code with the (-48) in order to 
														 obtain an integer*/
			evenPositions += staticCastHolder;
		}
	}

	productCodeArray[length] = checkDigit(oddPositions, evenPositions); /*here we calculate the check digit and set
																		the last digit of the product code to be that
																		digit, length is the indice of the last digit*/

	/*printing the final product code with calculated check digit*/
	cout << "The check digit is " << productCodeArray[length] << endl;
	cout << "The product code is ";
	for (int i = 0; i <= length; i++) { //the for loop allows us to print each individual digit of the product code
		cout << productCodeArray[i];
	}
	cout << endl;
}

int main() {

	bool cont = true;
	int codeType, length;

	cout << "Check Product Calculator" << endl;

	while (cont == true) { //we use a while loop to continue the program until the user inputs to exit

		cout << "------------------------" << endl;
		cout << "1. EAN-8" << endl << "2. UPC-A" << endl << "3. EAN-13" << endl << "4. EAN-14" << endl << "5. SSCC" << endl << "6. Quit" << endl;
		cout << "------------------------" << endl;
		cout << "Choose your product code type: ";
		cin >> codeType;
		//prompt the user to input the corresponding number of which product code they wish to enter
		//the input is stored in variable codeType to be used in the following switch case loop

		switch (codeType) { /* the switch case determines which product code type the user will be 
							inputting and sets the length according to the predetermined number of digits
							for each type*/
		case 1:
			length = 7;
			processProductCode(length); /*we then send the length into the processProductCode() function to 
										begin procesing an inputted product code, this is the same for all cases
										of the switch case loop just with different lengths for each type of product code*/
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
		case 6: /*the exit case, which when selected by the users input displays the exitting message and changes the 
				variable controlling the while loop to false in order to break from the while loop which ends the code as the
				return 0; is directly after the loop*/
			cout << endl << "Exitting..." << endl;
			cont = false;
			break;
		default: /* the default case which catches any incorrect user inputs*/
			cout << "ERROR: Invalid Menu Selection" << endl;
			break;
		}
	}

	return 0;
}