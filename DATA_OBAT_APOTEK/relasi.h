/**
Nama:Rangga Dwi Alamsyah
NIM: 1301164030
Mengerjakan satu halaman ini
*/
#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include<iostream>

#include "doublelist.h"
#include "singlelist.h"
#include "relasi.h"

#define first(L) L.first
#define obat(P) P->obat
#define penyakit(P) P->penyakit
#define next(P) P->next

typedef struct elmlist_R *address_R;

using namespace std;

struct elmlist_R{
    address_R next;
    address_C obat;
    address_P penyakit;
};

struct list_R{
    address_R first;
};

void createlist(list_R &L);
address_R alokasi(address_C C, address_P S);
void dealokasi(address_R &P);
void insertfirst(list_R &L, address_R P);
void insertlast(list_R &L, address_R P);
void deletefirst(list_R &L, address_R &P);
void deletelast(list_R &L, address_R &p);
address_R findelm(list_R L, address_C C, address_P S);
void insertafter(list_R &L, address_R Prec, address_R P);
void deleteafter(list_R &L, address_R Prec, address_R &P);
void printinfo(list_R L);


#endif // RELASI_H_INCLUDED
