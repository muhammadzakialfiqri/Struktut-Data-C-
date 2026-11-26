/* file : bstree.h
   ADT Binary Search Tree dengan representasi pointer (linked list)
   Modul 10 bagian 10.9 (Latihan) */

#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED

#include <cstddef>

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left, right;
};

/********* Soal 1 *********/
address alokasi(infotype x);
/* mengembalikan address node baru berisi x, left dan right = Nil */

void insertNode(address &root, infotype x);
/* I.S. tree boleh kosong
   F.S. x masuk ke posisi yang sesuai aturan BST, duplikat diabaikan */

address findNode(infotype x, address root);
/* mengembalikan address node dengan info = x, Nil jika tidak ada */

void printInorder(address root);
/* menampilkan isi tree secara in-order: kiri, root, kanan */

/********* Soal 2 *********/
int hitungJumlahNode(address root);
/* mengembalikan banyak node yang ada di dalam BST */

int hitungTotalInfo(address root, int start);
/* mengembalikan jumlah (total) info dari node-node di dalam BST,
   start = nilai awal penjumlahan (diisi 0) */

int hitungKedalaman(address root, int start);
/* mengembalikan kedalaman maksimal BST (root saja bernilai 1),
   start = 0 */

/********* Soal 3 *********/
void printPreorder(address root);
/* menampilkan isi tree secara pre-order: root, kiri, kanan */

void printPostorder(address root);
/* menampilkan isi tree secara post-order: kiri, kanan, root */

#endif // BSTREE_H_INCLUDED