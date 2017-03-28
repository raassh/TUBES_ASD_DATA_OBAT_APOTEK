/**
Nama: Fahrurrozi
NIM: 1301164213
Mengerjakan satu halaman ini
*/
#include "doublelist.h"

void createList(List_P &L) {
    first(L)=NULL;
    last(L)=NULL;

}

address_P alokasi(infotype_P x) {
    address_P P;
    P=new elmlist_P;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void dealokasi(address_P &P) {
    delete P;
}

void insertFirst(List_P &L, address_P P) {
    if(first(L)!=NULL){
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
    else{
        first(L)=P;
        last(L)=P;
    }
}

void insertLast(List_P &L, address_P P) {
    if(first(L)!= NULL){
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
    }
    else{
        insertFirst(L,P);
    }
}

void deleteFirst(List_P &L, address_P &P) {
    if (first(L)==last(L)){
        cout<<"gagal hapus, list kosong"<<endl;
    }
    else{
        P=first(L);
        first(L)=next(first(L));
        prev(P)=NULL;
        prev(first(L))=NULL;
        next(P)=NULL;

    }
}

void deleteLast(List_P &L, address_P &P) {
    if (last(L)==first(L)){
        cout<<"delete gagal, list kosong"<<endl;
    }
    else{
        P=last(L);
        last(L)=prev(last(L));
        prev(P)=NULL;
        next(last(L))=NULL;
        dealokasi(P);
    }
}

void printInfo(List_P L) {
    address_P P;
    P=first(L);
    while (P!= NULL){
        cout<<"Nama: "<<info(P).nama<<endl;
        cout<<"ID: "<<info(P).id<<endl;
        cout<<"Tingkat Berbahaya: "<<info(P).tb<<endl;
        cout<<"Gejala 1: "<<info(P).gej1<<endl;
        cout<<"Gejala 2: "<<info(P).gej2<<endl;
        cout<<"Gejala 3: "<<info(P).gej3<<endl;
            P=next(P);
        }
    }



address_P findElm(List_P L, infotype_P x) {
    address_P P;
    P = first(L);
    while((P != NULL) && (info(P).id!=x.id)) {
        P = next(P);
    }
    return P;
}

void insertAfter(List_P &L, address_P Prec, address_P P) {
    if(Prec!=NULL) {
        if(next(Prec)!=NULL) {
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(Prec)) = P;
            next(Prec) = P;
        }
        else
            insertLast(L,P);
    } else {
        cout<<"gagal insert after, prec null"<<endl;
    }
}

void deleteAfter(List_P &L, address_P Prec, address_P &P) {
    if(first(L)!=NULL) {
        if(Prec!=NULL&&Prec!=last(L)) {
            if(next(Prec)==last(L)) {
                deleteLast(L,P);
            } else {
                P = next(Prec);
                next(Prec) = next(P);
                prev(next(P)) = Prec;
                prev(P) = NULL;
                next(P) = NULL;
            }
        } else {
            cout<<"gagal delete after"<<endl;
        }
    } else {
        cout<<"gagal delete after, list kosong"<<endl;
    }
}
