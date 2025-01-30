#include "Header.h"

void inputCar(vector<car>& cars) {
	int n;
	cout << "Enter the number of cars: ";
	cin >> n;
	cars.resize(n);
	for (int i = 0; i < n; i++) {
		cout << "Enter the name of car " << i + 1 << ": ";
		cin.ignore();
		getline(cin, cars[i].name);
		cout << "Enter the color of car " << i + 1 << ": ";
		cin >> cars[i].color;
		cout << "Enter the score of car " << i + 1 << ": ";
		cin >> cars[i].score;
	}
}

string transformColor(char color) {
	if (color == 'g') {
		return "Xam";
	}
	else if (color == 'r') {
		return "Do";
	}
	else if (color == 'b') {
		return "Xanh";
	}
	else if (color == 'w') {
		return "Trang";
	}
	else {
		return "Unknown";
	}
}
void outputCar(vector<car> cars) {
	for (int i = 0; i < cars.size(); i++) {
		cout << cars[i].name << " - " << transformColor(cars[i].color) << " - " << cars[i].score << endl;
	}
}

void toyotaScoreThan8(vector<car> cars) {
	int count = 0;
	for (int i = 0; i < cars.size(); i++) {
		if (cars[i].name.find("Toyota") != string::npos && cars[i].score > 8) {
			count++;
		}
	}
	cout << "The number of Toyota cars with score greater than 8: " << count << endl;
	for (int i = 0; i < cars.size(); i++) {
		if (cars[i].name.find("Toyota")!= string::npos && cars[i].score > 8) {
			cout << cars[i].name << " - " << transformColor(cars[i].color) << " - " << cars[i].score << endl;
		}
	}
}
int colorPoint(char color) {
	if (color == 'g') {
		return 3;
	}
	else if (color == 'r') {
		return 2;
	}
	else if (color == 'b') {
		return 1;
	}
	else {
		return 0;
	}
}

void sortByNameAndColor(vector<car>& cars) {
	for (int i = 0; i < cars.size() - 1; i++) {
		for (int j = i + 1; j < cars.size(); j++) {
			if (cars[i].name > cars[j].name || (cars[i].name == cars[j].name && colorPoint(cars[i].color) > colorPoint(cars[j].color))) {
				swap(cars[i], cars[j]);
			}
		}
	}
	cout << "=> finished sorting" << endl;
}

void writeToFile(vector<car> cars, string fileName) {
	ofstream file(fileName);
	for (int i = 0; i < cars.size(); i++) {
		file << i + 1<< ". " << "Ten: " << cars[i].name << " - " << "Mau: " << transformColor(cars[i].color) << " - " << "Diem: " << cars[i].score << endl;
	}
	file.close();
	cout << "=> finished writing to file" << endl;
}
