#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct car{
	string name;
	char color;
	float score;
};

void inputCar(vector<car>& cars);
string transformColor(char color);
void outputCar(vector<car> cars);
void toyotaScoreThan8(vector<car> cars);
int colorPoint(char color);
void sortByNameAndColor(vector<car>& cars);
void writeToFile(vector<car> cars, string fileName);

#endif