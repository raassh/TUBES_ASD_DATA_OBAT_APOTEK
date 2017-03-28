/**
Nama: Fahrurrozi
NIM: 1301164213
Mengerjakan satu halaman ini
*/
#include "singlelist.h"

void createListsingle(List_C &L) {
    first(L) = NULL;
}

address_C alokasisingle(infotype_C x) {
    address_C P;
    P = new elmlist_C;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasisingle(address_C &P) {
    delete P;
    P = NULL;
}

void insertFirstsingle(List_C &L, address_C P) {
    if (first(L)!=NULL){
        next(P)=first(L);
        first(L)=P;
    }
    else{
        first(L)=P;
    }

}

void insertlastsingle(List_C &L, address_C P){
    address_C Q;
    if(first(L) != NULL){
        Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
    else{
        insertFirstsingle(L,P);
    }
}

void insertaftersingle(List_C &L, address_C Prec, address_C P){
    if(first(L) != NULL){
        next(P) = next(Prec);
        next(Prec) = P;
    }
    else{
        insertFirstsingle(L,P);
    }
}

void deleteFirstsingle(List_C &L, address_C &P) {
    if (first(L)!=NULL){
        P=first(L);
        first(L)=next(P);
        next(P)= NULL;
        dealokasisingle(P);
    }
    else{
        cout<<"delete gagal, list kosong"<<endl;
    }
}

void deletelastsingle(List_C &L, address_C &P){
    address_C Q;
    if(first(L) != NULL){
        if(next(first(L)) != NULL){
            Q = first(L);
            while(next(next(Q)) != NULL){
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
            dealokasisingle(P);
        }
        else{
            deleteFirstsingle(L,P);
        }
    }
    else
        cout<<"Delete Gagal List Kosong"<<endl;
}

void deleteaftersingle(List_C &L, address_C Prec, address_C &P){
    if(first(L) != NULL){
        if(next(first(L)) != NULL){
            P = next(Prec);
            next(Prec) = next(P);
            next(P) = NULL;
            dealokasisingle(P);
        }
        else{
            deleteFirstsingle(L,P);
        }
    }
}

address_C findelmsingle(List_C L, infotype_C x){
    address_C Q;
    Q = first(L);
    while(Q != NULL && info(Q).id != x.id){
        Q = next(Q);
    }
    return Q;
}

void printInfosingle(List_C L) {
    address_C P = first(L);
    while(P!=NULL) {
        cout<<"Nama: "<<info(P).nama<<endl;
        cout<<"ID: "<<info(P).id<<endl;
        cout<<"Stok: "<<info(P).stok<<endl;
        cout<<"Harga: "<<info(P).harga<<endl;
        P = next(P);
    }
}
