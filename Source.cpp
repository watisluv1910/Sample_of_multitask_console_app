#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <fstream> // for if/ofstream
#include <time.h> // for srand
#include <vector> // for vector
#include <stdio.h> // for printf
#include <stdlib.h> // for rand, srand
#include <sstream>
#include <utility>

using namespace std;

//function that check type error or "border crossing"
int initializeInteger(string path, int lowerBound, int upperBound) {
	bool isCorrect = false;
	int temporaryVariable;
	while (!isCorrect) {
		string temporaryVariableString;
		cin >> temporaryVariableString;
		isCorrect = true;
		for (size_t i = 0; i < 128; i++) {
			if ((i < (int)'0' || i >(int)'9') && i != (int)'-') {
				if (temporaryVariableString.find((char)i) != string::npos) {
					isCorrect = false;
				}
			}
		}
		if (isCorrect) {
			temporaryVariable = stoi(temporaryVariableString);
			if (lowerBound != 0 || upperBound != 0) {
				if (temporaryVariable < lowerBound
					|| temporaryVariable > upperBound) {
					cout << "Initialization error.\nEnter correct value:\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					isCorrect = false;
					// operator >> will no longer fetch data from the stream 
					// as it is in the wrong format
				}
			}
			else if (path == "allExceptZero" && temporaryVariable == 0 ||
				path == "negative" && temporaryVariable >= 0 ||
				path == "notpositive" && temporaryVariable > 0 ||
				path == "notnegative" && temporaryVariable < 0 ||
				path == "positive" && temporaryVariable <= 0) {
				cout << "Initialization error.\nEnter correct value:\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				isCorrect = false;
			}
		}
		else {
			cout << "Initialization error.\nEnter correct value:\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return temporaryVariable;
}

// function that check type error or "border crossing"
double initializeDouble(string path, double lowerBound, double upperBound) {
	bool isCorrect = false;
	double temporaryVariable;
	while (!isCorrect) {
		string temporaryVariableString;
		cin >> temporaryVariableString;
		isCorrect = true;
		for (size_t i = 0; i < 128; i++) {
			if ((i < (int)'0' || i >(int)'9') &&
				i != (int)'-' && i != (int)'.') {
				if (temporaryVariableString.find((char)i) != string::npos) {
					isCorrect = false;
				}
			}
		}
		if (isCorrect) {
			// turns a string into a stream:
			istringstream stringStream(temporaryVariableString);
			stringStream >> temporaryVariable; // reads data from the stream
			if (lowerBound != 0.0 || upperBound != 0.0) {
				if (temporaryVariable < lowerBound ||
					temporaryVariable > upperBound) {
					cout << "Initialization error.\nEnter correct value:\n";
					cin.clear();
					// operator >> will no longer fetch data from the stream:
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					isCorrect = false;
				}
			}
			else if (path == "allExceptZero" && temporaryVariable == 0.0 ||
				path == "negative" && temporaryVariable >= 0.0 ||
				path == "notpositive" && temporaryVariable > 0.0 ||
				path == "notnegative" && temporaryVariable < 0.0 ||
				path == "positive" && temporaryVariable <= 0.0) {
				cout << "Initialization error.\nEnter correct value:\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				isCorrect = false;
			}
		}
		else {
			cout << "Initialization error.\nEnter correct value:\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return temporaryVariable;
}

void f1() {

}

void f2() {

}

int main() {
	int chooseTask;
	setlocale(LC_ALL, "Russian");
	cout << "Hello!\nTask number can't be more than 2.\n"
		"Enter 0 to end the programm.\nEnter the task number :\n";
	chooseTask = initializeInteger("notnegative", 0, 0);
	while (chooseTask > 0) {
		switch (chooseTask) {
		case 1:
			f1();
			break;
		case 2:
			f2();
			break;
		default:
			cout << "Entered task number is incorrect, try again.\n"
				"Task number can't be more than 2.\n"
				"Enter 0 to end the programm.\n";
			break;
		}
		cout << "Enter the next task number:\n";
		chooseTask = initializeInteger("notnegative", 0, 0);
	}
}