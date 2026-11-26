#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    // ===== Soal 1 : insert data lalu tampilkan secara in-order =====
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);        // duplikat, tidak dimasukkan
    insertNode(root, 7);
    printInorder(root);

    // ===== Soal 2 : hitung kedalaman, jumlah node, dan total info =====
    cout << "\n";
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;

    // ===== Soal 3 : tree pada Gambar 10-18, pre-order dan post-order =====
    address root2 = Nil;
    insertNode(root2, 6);
    insertNode(root2, 4);
    insertNode(root2, 7);
    insertNode(root2, 2);
    insertNode(root2, 5);
    insertNode(root2, 1);
    insertNode(root2, 3);
    cout << "pre-order : ";
    printPreorder(root2);
    cout << endl;
    cout << "post-order : ";
    printPostorder(root2);
    cout << endl;

    // ===== Pengujian findNode (soal 1) =====
    address P = findNode(4, root);
    if (P != Nil) {
        cout << "findNode(4) : ditemukan, info = " << P->info << endl;
    } else {
        cout << "findNode(4) : tidak ditemukan" << endl;
    }
    P = findNode(9, root);
    if (P != Nil) {
        cout << "findNode(9) : ditemukan, info = " << P->info << endl;
    } else {
        cout << "findNode(9) : tidak ditemukan" << endl;
    }

    return 0;
}