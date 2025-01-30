#include "Header.h"

void inputPhone(Node*& head) {
    int n;
    cout << "Nhap so luong: ";
    cin >> n;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node();
        cout << "Nhap ma cua dien thoai thu " << i + 1 << ": ";
        cin.ignore();
        getline(cin, newNode->data.id);
        cout << "Nhap thuong hieu cua dien thoai thu " << i + 1 << ": ";
        getline(cin, newNode->data.brand);
        cout << "Nhap ten cua dien thoai thu " << i + 1 << ": ";
        getline(cin, newNode->data.name);
        cout << "Nhap gia cua dien thoai thu " << i + 1 << ": ";
        cin >> newNode->data.price;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void outputPhone(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << "Ma so: " << current->data.id << ", Hang: " << current->data.brand << ", Ten: " << current->data.name << ", Gia: " << current->data.price << endl;
        current = current->next;
    }
}

void updateBrand(Node* head, string id, string brand) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.id == id) {
            current->data.brand = brand;
        }
        current = current->next;
    }
    cout << "Danh sach sau khi thay doi: " << endl;
    outputPhone(head);
}

void removePriceMoreThanK(Node*& head, float k) {
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->data.price > k) {
            if (prev == nullptr) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    cout << "Danh sach sau khi xoa: " << endl;
    outputPhone(head);
}

void writeToBinaryFile(Node* head, string fileName) {
    ofstream ofs(fileName, ios::binary);
    if (!ofs) {
        cerr << "Khong the mo file de ghi!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        const phone& p = current->data;

        // Ghi id
        size_t idLength = p.id.size();
        ofs.write((char*)&idLength, sizeof(idLength));
        ofs.write(p.id.c_str(), idLength);

        // Ghi brand
        size_t brandLength = p.brand.size();
        ofs.write((char*)&brandLength, sizeof(brandLength));
        ofs.write(p.brand.c_str(), brandLength);

        // Ghi name
        size_t nameLength = p.name.size();
        ofs.write((char*)&nameLength, sizeof(nameLength));
        ofs.write(p.name.c_str(), nameLength);

        // Ghi price
        ofs.write((char*)&p.price, sizeof(p.price));

        current = current->next;
    }
    ofs.close();

    cout << "Ghi thanh cong" << endl;
}

void readFromBinaryFileAndSortById(Node*& head, string fileName) {
    ifstream ifs(fileName, ios::binary);
    if (!ifs) {
        cerr << "Khong the mo file de ghi!" << endl;
        return;
    }

    // Xoa du lieu cu
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* tail = nullptr;
    while (ifs) {
        phone p;

        // Doc id
        size_t idLength;
        ifs.read((char*)&idLength, sizeof(idLength));
        if (!ifs) break; // Kiem tra xem co du lieu de doc khong
        p.id.resize(idLength);
        ifs.read(&p.id[0], idLength);

        // Doc brand
        size_t brandLength;
        ifs.read((char*)&brandLength, sizeof(brandLength));
        p.brand.resize(brandLength);
        ifs.read(&p.brand[0], brandLength);

        // Doc name
        size_t nameLength;
        ifs.read((char*)&nameLength, sizeof(nameLength));
        p.name.resize(nameLength);
        ifs.read(&p.name[0], nameLength);

        // Doc price
        ifs.read((char*)&p.price, sizeof(p.price));

        Node* newNode = new Node();
        newNode->data = p;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    ifs.close();

    // Sap xep danh sach lien ket theo id
    if (head == nullptr) return;
    for (Node* i = head; i->next != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data.id > j->data.id) {
                swap(i->data, j->data);
            }
        }
    }

    cout << "Danh sach sau khi sap xep: " << endl;
    outputPhone(head);
}
