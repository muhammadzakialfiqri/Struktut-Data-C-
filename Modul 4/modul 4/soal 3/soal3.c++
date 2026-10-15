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

void hitungSum(int &total) {
    total = 0;
    Node *bantu = head;
    while (bantu != NULL) {
        total = total + bantu->data;
        bantu = bantu->next;
    }
}

int main() {
    int n, x, total;

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

    hitungSum(total);
    cout << total << endl;

    return 0;
}