#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertLast(int x) {
    Node *baru = new Node;
    baru->data = x;
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

void insertAfter(int cari, int nilaiBaru) {
    Node *bantu = head;
    while (bantu != NULL && bantu->data != cari) {
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Data " << cari << " tidak ditemukan" << endl;
        return;
    }

    Node *baru = new Node;
    baru->data = nilaiBaru;
    baru->next = bantu->next;
    bantu->next = baru;
}

void tampilList() {
    Node *bantu = head;
    while (bantu != NULL) {
        cout << bantu->data;
        if (bantu->next != NULL) cout << " -> ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {
    int n, x, cari, nilaiBaru;

    if (!(cin >> n) || n < 0) {
        cout << "Input tidak valid" << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (!(cin >> x)) {
            cout << "Input tidak valid" << endl;
            return 1;
        }
        insertLast(x);
    }
    if (!(cin >> cari >> nilaiBaru)) {
        cout << "Input tidak valid" << endl;
        return 1;
    }

    insertAfter(cari, nilaiBaru);
    tampilList();

    return 0;
}