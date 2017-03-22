#include "singlelist.h"

void createListsingle(List &L) {
    first(L) = NULL;
}

address alokasisingle(infotype x) {
    address P;
    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasisingle(address &P) {
    delete P;
    P = NULL;
}

void insertFirstsingle(List &L, address P) {
    if (first(L)!=NULL){
        next(P)=first(L);
        first(L)=P;
    }
    else{
        first(L)=P;
    }

}

void deleteFirstsingle(List &L, address &P) {
    if (first(L)!=NULL){
        P=first(L);
        first(L)=next(P);
        next(P)= NULL;
    }
    else{
        cout<<"delete gagal, list kosong"<<endl;
    }
}


void printInfosingle(List L) {
    cout<<"  ";
    address P = first(L);
    while(P!=NULL) {
        cout<<info(P)<<", ";
        P = next(P);
    }
    cout<<endl;
}
