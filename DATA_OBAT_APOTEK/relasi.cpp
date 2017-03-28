/**
Nama:Rangga Dwi Alamsyah
NIM: 1301164030
Mengerjakan satu halaman ini
*/
#include "relasi.h"

void createlist(list_R &L){
    first(L) = NULL;
}

address_R alokasi(address_C C, address_P S){
    address_R P = new elmlist_R;
    obat(P) = C;
    penyakit(P) = S;
    next(P) = NULL;
    return P;
}

void dealokasi(address_R &P){
    delete P;
}

void insertfirst(list_R &L, address_R P){
    if(first(L) != NULL){
        next(P) = first(L);
        first(L) = P;
    }
    else{
        first(L) = P;
    }
}

void insertlast(list_R &L, address_R P){
    address_R Q;
    if(first(L) != NULL){
        Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
    else{
        insertfirst(L,P);
    }
}

void deletefirst(list_R &L, address_R &P){
    if(first(L) != NULL){
        if(next(first(L)) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        dealokasi(P);
        }
        else{
            P = first(L);
            first(L) = NULL;
            dealokasi(P);
        }
    }
    else
        cout<<"delete gagal list kosong"<<endl;
}

void deletelast(list_R &L, address_R &P){
    address_R Q;
    if(first(L) != NULL){
        if(next(first(L)) != NULL){
            Q = first(L);
            while(next(next(Q)) != NULL){
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
            dealokasi(P);
        }
        else{
            deletefirst(L,P);
        }
    }
    else
        cout<<"delete gaagal list kosong"<<endl;
}

address_R findelm(list_R L, address_C C, address_P S){
    address_R Q;
    Q = first(L);
    while(Q != NULL && obat(Q) != C || penyakit(Q) != S){
        Q = next(Q);
    }
    return Q;
}

void insertafter(list_R &L, address_R Prec, address_R P){
    if(first(L) != NULL){
        next(P) = next(Prec);
        next(Prec) = P;
    }
    else{
        insertfirst(L,P);
    }
}

void deleteafter(list_R &L, address_R Prec, address_R &P){
    if(first(L) != NULL){
        if(next(first(L)) != NULL){
            P = next(Prec);
            next(Prec) = next(P);
            next(P) = NULL;
            dealokasi(P);
        }
        else{
            deletefirst(L,P);
        }
    }
    else
        cout<<"delete gagal list kosong"<<endl;
}

void printinfo(list_R L){
    address_R Q;
    if(first(L) != NULL){
        Q = first(L);
        while(Q != NULL){
            cout<<"Penyakitnya: "<<info(penyakit(Q)).nama<<endl;
            cout<<"Obatnya: "<<info(obat(Q)).nama<<endl;
            Q = next(Q);
        }
    }
}
