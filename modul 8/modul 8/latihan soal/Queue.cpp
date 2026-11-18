#ifndef ALTERNATIF
#define ALTERNATIF 3
#endif

#include "queue.h"

// ===== Bagian yang sama untuk ketiga alternatif =====
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

// ===== isFullQueue =====
bool isFullQueue(Queue Q) {
#if ALTERNATIF == 1
    return Q.tail == MAX - 1;
#elif ALTERNATIF == 2
    return Q.head == 0 && Q.tail == MAX - 1;
#else
    return !isEmptyQueue(Q) && (Q.tail + 1) % MAX == Q.head;
#endif
}

// ===== enqueue =====
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
#if ALTERNATIF == 1
        Q.tail++;                           // tail maju
#elif ALTERNATIF == 2
        if (Q.tail == MAX - 1) {            // penuh semu: geser elemen ke awal array
            int jumlah = Q.tail - Q.head + 1;
            for (int i = 0; i < jumlah; i++) {
                Q.info[i] = Q.info[Q.head + i];
            }
            Q.head = 0;
            Q.tail = jumlah - 1;
        }
        Q.tail++;                           // tail maju
#else
        Q.tail = (Q.tail + 1) % MAX;        // setelah indeks terakhir kembali ke 0
#endif
    }
    Q.info[Q.tail] = x;
}

// ===== dequeue =====
infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];

#if ALTERNATIF == 1
    for (int i = Q.head; i < Q.tail; i++) { // geser semua elemen ke depan
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;                               // tail mundur
    if (Q.tail == -1) {                     // tadinya hanya 1 elemen
        Q.head = -1;
    }
#else
    if (Q.head == Q.tail) {                 // tadinya hanya 1 elemen
        Q.head = -1;
        Q.tail = -1;
    } else {
  #if ALTERNATIF == 2
        Q.head++;                           // head maju
  #else
        Q.head = (Q.head + 1) % MAX;        // head ikut berputar
  #endif
    }
#endif
    return x;
}

// ===== printInfo =====
void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }
#if ALTERNATIF == 3
    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }
#else
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
#endif
    cout << endl;
}