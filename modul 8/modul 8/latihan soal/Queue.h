#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>

using namespace std;

const int MAX = 5;            // kapasitas queue (array [5])

typedef int infotype;

struct Queue {
    infotype info[MAX];       // indeks array dimulai dari 0
    int head;                 // indeks elemen terdepan, -1 = queue kosong
    int tail;                 // indeks elemen terakhir, -1 = queue kosong
};

// I.S. sembarang, F.S. terbentuk queue kosong (head = -1, tail = -1)
void createQueue(Queue &Q);

// true jika queue kosong
bool isEmptyQueue(Queue Q);

// true jika queue penuh
bool isFullQueue(Queue Q);

// menambahkan x di belakang queue
void enqueue(Queue &Q, infotype x);

// mengambil elemen terdepan, mengembalikan nilainya
// jika queue kosong, menampilkan pesan dan mengembalikan -1
infotype dequeue(Queue &Q);

// menampilkan head - tail dan isi queue
void printInfo(Queue Q);

#endif // QUEUE_H_INCLUDED