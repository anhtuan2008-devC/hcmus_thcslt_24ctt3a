#include "Header.h"

int main() {
    Node* phones = nullptr;
    int n;
    cout << "Menu: " << endl;
    cout << "1. Input phone" << endl;
    cout << "2. Output phone" << endl;
    cout << "3. Update brand" << endl;
    cout << "4. Remove phone with price more than k" << endl;
    cout << "5. Write to binary file" << endl;
    cout << "6. Read from binary file and sort by id" << endl;
    cout << "7. Exit" << endl;

    string id, brand;
    float k;

    do {
        cout << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch (n) {
        case 1:
            inputPhone(phones);
            break;
        case 2:
            outputPhone(phones);
            break;
        case 3:
            cout << "Nhap id can thay doi: ";
            cin.ignore();
            getline(cin, id);
            cout << "Nhap thuong hieu moi: ";
            getline(cin, brand);
            updateBrand(phones, id, brand);
            break;
        case 4:
            cout << "Nhap gia k: ";
            cin >> k;
            removePriceMoreThanK(phones, k);
            break;
        case 5:
            writeToBinaryFile(phones, "dienthoai.bin");
            break;
        case 6:
            readFromBinaryFileAndSortById(phones, "dienthoai.bin");
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Lua chon khong thich hop!" << endl;
            break;
        }
    } while (n != 7);

    // Clean up the linked list
    while (phones != nullptr) {
        Node* temp = phones;
        phones = phones->next;
        delete temp;
    }

    return 0;
}
