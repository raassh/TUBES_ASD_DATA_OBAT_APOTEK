#ifndef SINGLELIST_H_INCLUDED
#define SINGLELIST_H_INCLUDED
#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;


typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};


void createListsingle(List &L);
address alokasisingle(infotype x);
void dealokasisingle(address &P);
void insertFirstsingle(List &L, address P);
void deleteFirstsingle(List &L, address &P);
void printInfosingle(List L);



#endif // SINGLELIST_H_INCLUDED
