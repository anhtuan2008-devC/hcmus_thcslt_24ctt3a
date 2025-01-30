#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct phone {
    string id, brand, name;
    float price;
};

struct Node {
    phone data;
    Node* next;
};

void inputPhone(Node*& head);
void outputPhone(Node* head);
void updateBrand(Node* head, string id, string brand);
void removePriceMoreThanK(Node*& head, float k);
void writeToBinaryFile(Node* head, string fileName);
void readFromBinaryFileAndSortById(Node*& head, string fileName);

#endif
