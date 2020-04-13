#include <iostream>
#include <cmath>
#include <iomanip>
#include "AllZerosException.h"
using namespace std;

void greeting();
void check_discriminant(double a, double b, double c);

int main() {
	cout << fixed << setprecision(2);

	greeting();
	char response{};

	try {
		do {

			cout << "Please enter values for coefficients: A,B,C separated by spaces: ";
			double num1{}, num2{}, num3{};
			cin >> num1 >> num2 >> num3;

			check_discriminant(num1, num2, num3);
			cout << endl;
			cout << "Do you want to do another calculation? [Y/N]" << endl;
			cin >> response;
			cout << endl;
			system("cls");
		} while (response != 'n' && 'N');
	}
	
	catch (const AllZerosException& ex) {
		cerr << ex.what() << endl;
	}

	cout << "\nHave a nice day!" << endl;
	system("pause");
	return 0;
}

void greeting() {
	cout << "Hello there, this program is to calculate the roots of quadratic equations." << endl;
	cout << "Equations will take the form Ax^2 + Bx + C." << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << endl;
}


void check_discriminant(double a, double b, double c) {
	if (pow(b, 2) - (4 * a * c) > 0) {
		cout << "The roots are real and different and calculated as follows: " << endl;
		cout << "x1 = [-b + sqrt(b^2-4ac)] / 2a" << endl;
		cout << "x2 = [-b - sqrt(b^2-4ac)] / 2a " << endl;
		cout << endl;
		double x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
		cout << "Therefore x1 = " << x1;
		double x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / 2 * a;
		cout << " and x2 = " << x2 << endl;

		//including test for integer and (x+y)(x+y) form:
		if (floor(x1) == ceil(x1) && floor(x2) == ceil(x2)) {
			cout << resetiosflags(std::ios::fixed);
			cout << "\nThis can also be written in the form: " << endl;
			if (x1 < 0) {
				cout << "(x + " << abs(x1) << ")";
			}
			else if (x1 == 0)cout << "x";
			else cout << "(x - " << x1 << ")";

			if (x2 < 0) {
				cout << "(x + " << abs(x2) << ")";
			}
			else if (x2 == 0)cout << "x";
			else cout << "(x - " << x2 << ")";
		}	cout << endl;
	}

	else if (pow(b, 2) - (4 * a * c) == 0) {
		if (a == 0 && b == 0 && c == 0) {
			throw AllZerosException{};	//had to use exception handling here, if-else did no good...
		}

		cout << "The roots are real and equal and are calculated as follows: " << endl;
		cout << "x1 = x2 = -b / 2a" << endl;
		cout << endl;
		double x1x2 = -b / 2 * a;
		cout << "Therefore x1 = x2 = " << x1x2 << endl;

		if (floor(x1x2) == ceil(x1x2)) {
			cout << resetiosflags(std::ios::fixed);
			cout << "This can also be written as: " << endl;
			cout << "(x ";
			if (x1x2 < 0) {
				cout << "+ " << abs(x1x2) << ")";
			}
			else cout << "- " << x1x2 << ")";
		}cout << endl;
	}

	//implement this someday
	else if (pow(b, 2) - (4 * a * c) < 0) {
		cout << "The roots are complex and different and therefore out of the scope of this program. " << endl;
	}

}