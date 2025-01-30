#include "Header.h"

void main() {
	vector<car> cars;
	int n;

	cout << "Menu: " << endl;
	cout << "1. Input car" << endl;
	cout << "2. Output car" << endl;
	cout << "3. Toyota car with score greater than 8" << endl;
	cout << "4. Sort by name and color" << endl;
	cout << "5. Write to file" << endl;
	cout << "6. Exit" << endl;

	do {
		cout << endl;
		cout << "Enter your choice: ";
		cin >> n;
		switch (n) {
		case 1:
			inputCar(cars);
			break;
		case 2:
			outputCar(cars);
			break;
		case 3:
			toyotaScoreThan8(cars);
			break;
		case 4:
			sortByNameAndColor(cars);
			break;
		case 5:
			writeToFile(cars, "Output.txt");
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (n != 6);
}