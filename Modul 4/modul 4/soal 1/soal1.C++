#include <iostream>
#include <string>
using namespace std;

// Node singly linked list untuk antrean nasabah
struct Node {
    string nama;
    Node *next;
};

Node *head = NULL;

// Menambah nasabah di akhir antrean
void insertLast(string nama) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}


void deleteFirst() {
    if (head == NULL) {
        cout << "Antrean kosong" << endl;
        return;
    }
    Node *hapus = head;
    cout << "Melayani: " << hapus->nama << endl;
    head = head->next;
    delete hapus;
}

void tampilAntrean() {
    cout << "Antrean: ";
    if (head == NULL) {
        cout << "(kosong)" << endl;
        return;
    }
    Node *bantu = head;
    while (bantu != NULL) {
        cout << bantu->nama;
        if (bantu->next != NULL) cout << " -> ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {
    int pilihan;
    string nama;

    while (true) {
        cout << " \nMENU " << endl;
        cout << "1. Tambah nasabah" << endl;
        cout << "2. Layani nasabah" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";

       
        if (!(cin >> pilihan)) {
            if (cin.eof()) break;         
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid, masukkan angka 1-3" << endl;
            continue;
        }

        if (pilihan == 1) {
            cout << "Nama nasabah: ";
            cin >> ws;                    
            getline(cin, nama);
            insertLast(nama);
            tampilAntrean();
        } else if (pilihan == 2) {
            deleteFirst();
            tampilAntrean();
        } else if (pilihan == 3) {
            break;
        } else {
            cout << "Pilihan tidak ada, masukkan angka 1-3" << endl;
        }
    }

    return 0;
}