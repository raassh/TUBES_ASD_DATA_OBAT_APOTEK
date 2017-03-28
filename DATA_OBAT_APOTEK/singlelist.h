/**
Nama: Fahrurrozi
NIM: 1301164213
Mengerjakan satu halaman ini
*/
#ifndef SINGLELIST_H_INCLUDED
#define SINGLELIST_H_INCLUDED
#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;


struct infotype_C{
    string nama;
    int id, stok, harga;
};
typedef struct elmlist_C *address_C;

struct elmlist_C {
    infotype_C info;
    address_C next;
};

struct List_C {
    address_C first;
};


void createListsingle(List_C &L);
address_C alokasisingle(infotype_C x);
void dealokasisingle(address_C &P);
void insertFirstsingle(List_C &L, address_C P);
void insertlastsingle(List_C &L, address_C P);
void insertaftersingle(List_C &L, address_C Prec, address_C P);
void deleteFirstsingle(List_C &L, address_C &P);
void deletelastsingle(List_C &L, address_C &P);
void deleteaftersingle(List_C &L, address_C Prec, address_C &P);
address_C findelmsingle(List_C L, infotype_C x);
void printInfosingle(List_C L);



#endif // SINGLELIST_H_INCLUDED
