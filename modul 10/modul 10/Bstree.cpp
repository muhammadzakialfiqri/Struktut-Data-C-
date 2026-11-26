/* file : bstree.cpp
   Implementasi ADT Binary Search Tree pada bstree.h */

#include <iostream>
#include "bstree.h"

using namespace std;

/********* Soal 1 *********/
address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {                      // tempat kosong ketemu, buat node baru
        root = alokasi(x);
    } else if (x < root->info) {            // lebih kecil: masuk ke subtree kiri
        insertNode(root->left, x);
    } else if (x > root->info) {            // lebih besar: masuk ke subtree kanan
        insertNode(root->right, x);
    }
    // jika x sama dengan info, tidak dimasukkan lagi (duplikat)
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {   // tidak ada, atau ketemu
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

/********* Soal 2 *********/
int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start) {
    if (root == Nil) {
        return start;
    }
    start = start + root->info;
    start = hitungTotalInfo(root->left, start);
    start = hitungTotalInfo(root->right, start);
    return start;
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    }
    int kiri  = hitungKedalaman(root->left,  start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}

/********* Soal 3 *********/
void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
    }
}