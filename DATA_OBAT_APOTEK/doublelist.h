/**
Nama: Fahrurrozi
NIM: 1301164213
Mengerjakan satu halaman ini
*/
#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED
#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define last(L) L.last
#define prev(P) P->prev
#define info(P) P->info



using namespace std;

struct infotype_P {
    string nama, id, tb, gej1, gej2,gej3;
};

typedef struct elmlist_P *address_P;

struct elmlist_P {
    infotype_P info;
    address_P next;
    address_P prev;
};

struct List_P {
    address_P first;
    address_P last;
};


void createList(List_P &L);
address_P alokasi(infotype_P x);
void dealokasi(address_P &P);
void insertFirst(List_P &L, address_P P);
void insertAfter(List_P &L, address_P Prec, address_P P);
void insertLast(List_P &L, address_P P);
void deleteFirst(List_P &L, address_P &P);
void deleteLast(List_P &L, address_P &P);
void deleteAfter(List_P &L, address_P Prec, address_P &P);
address_P findElm(List_P L, infotype_P x);
void printInfo(List_P L);



#endif // DOUBLELIST_H_INCLUDED
