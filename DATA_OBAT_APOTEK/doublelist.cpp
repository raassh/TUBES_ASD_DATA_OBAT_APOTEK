#include "doublelist.h"

void createList(List &L) {
    first(L)=NULL;
    last(L)=NULL;

}

address alokasi(infotype x) {
    address P;
    P=new elmlist;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(List &L, address P) {
        if(first(L)!=last(L)){
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
    else{
        first(L)=P;
        next(P)=P;
    }
}

void insertLast(List &L, address P) {
    if(first(L)!=last(L)){
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
    }
    else{
        first(L)=P;
        next(P)=P;
    }
}

void deleteFirst(List &L, address &P) {
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

void deleteLast(List &L, address &P) {
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

void printInfo(List L) {
    address P;
    if(first(L)==last(L)){
        cout<<"List kosong"<<endl;
    }
    else{
        P=first(L);
        while (next(P)!= NULL){
            cout<<info(P)<<endl;
            P=next(P);
    }
    }

    //----------------------------------------
}


address findElm(List L, infotype x) {
    address P = NULL;
    P = first(L);
    while(P!=NULL && info(P)!=x) {
        P = next(P);
    }
    return P;
}

void insertAfter(List &L, address Prec, address P) {
    if(Prec!=NULL) {
        if(next(Prec)==NULL) {
            insertLast(L, P);
        } else {
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(Prec)) = P;
            next(Prec) = P;
        }
    } else {
        cout<<"gagal insert after, prec null"<<endl;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
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
