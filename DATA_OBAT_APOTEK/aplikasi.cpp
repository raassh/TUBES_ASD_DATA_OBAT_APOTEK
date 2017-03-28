/**
Nama:Rangga Dwi Alamsyah
NIM: 1301164030
Mengerjakan satu halaman ini
*/
#include "doublelist.h"
#include "singlelist.h"
#include "relasi.h"
#include <windows.h>
#include <conio.h>

void insertobat(List_C &O){
    infotype_C x;
    address_C P, Q;
    cout<<endl;
    cout<<" Masukan Obat"<<endl;
    cout<<endl;
    cout<<"ID: ";
    cin>>x.id;
    cout<<"Name: ";
    cin>>x.nama;
    cout<<"stok: ";
    cin>>x.stok;
    cout<<"harga: ";
    cin>>x.harga;
    P = alokasisingle(x);
    if(first(O) == NULL || info(first(O)).id > x.id && info(first(O)).id != x.id){
        insertFirstsingle(O,P);
    }
    else{
        Q = first(O);
        while(next(Q) != NULL && info(next(Q)).id < x.id){
            Q = next(Q);
        }
        if(next(Q) != NULL && info(Q).id != x.id){
            insertaftersingle(O,Q,P);
        }
        else if(info(Q).id != x.id){
            insertlastsingle(O,P);
        }
        if(info(first(O)).id == x.id || info(Q).id == x.id){
            cout<<"ID sudah ada:"<<endl;
        }
    }
    getch();
    system("cls");
}

void insertpenyakit(List_P &S){
    infotype_P x;
    address_P P;
    address_P Q;
    cout<<endl;
    cout<<"masukan penyakit"<<endl;
    cout<<endl;
    cout<<"ID: ";
    cin>>x.id;
    cout<<"Name: ";
    cin>>x.nama;
    cout<<"Tingkat Berbahaya: ";
    cin>>x.tb;
    cout<<"Gejala 1: ";
    cin>>x.gej1;
    cout<<"Gejala 2: ";
    cin>>x.gej2;
    cout<<"Gejala 3: ";
    cin>>x.gej3;
    P = alokasi(x);
    if(first(S) == NULL || info(first(S)).id > x.id && info(first(S)).id != x.id){
        insertFirst(S,P);
    }
    else{
        Q = first(S);
        while(next(Q) != NULL && info(next(Q)).id < x.id){
            Q= next(Q);
        }
        if(next(Q) != NULL && info(Q).id != x.id){
            insertAfter(S,Q,P);
        }
        else if(info(Q).id != x.id){
            insertLast(S,P);
        }
        if(info(first(S)).id == x.id || info(Q).id == x.id){
            cout<<"ID sudah ada:"<<endl;
        }
    }
    getch();
    system("cls");
}

void relasi(list_R &R, List_C C, List_P S){
    infotype_C x;
    infotype_P y;
    address_C P;
    address_P Q;
    address_R r;
    cout<<endl;
    cout<<"Relasi obat dan penyakit"<<endl;
    cout<<endl;
    cout<<"Obat : ";
    cin>>x.id;
    cout<<"Penyakit : ";
    cin>>y.id;
    P = findelmsingle(C, x);
    Q = findElm(S, y);
    if(P != NULL && Q != NULL){
        r = alokasi(P, Q);
        if(first(R) != NULL){
            insertlast(R,r);
        }
        else{
            insertfirst(R,r);
        }
    }
    else{
        cout<<"ID sudah ada:"<<endl;
    }
    getch();
    system("cls");
}

void list_obat(List_C C){
    cout<<endl;
    cout<<"List Obat"<<endl;
    cout<<endl;
    if(first(C) != NULL){
        printInfosingle(C);
    }
    else{
        cout<<"List Kosong :"<<endl;
    }
    getch();
    system("cls");
}

void list_penyakit(List_P S){
    cout<<endl;
    cout<<"List Penyakit"<<endl;
    cout<<endl;
    if(first(S) != NULL){
        printInfo(S);
    }
    else{
        cout<<"List Kosong:"<<endl;
    }
    getch();
    system("cls");
}

void list_relasi(list_R R){
    cout<<endl;
    cout<<"List Relasi"<<endl;
    cout<<endl;
    if(first(R) != NULL){
        printinfo(R);
    }
    else{
        cout<<"List Kosong:"<<endl;
    }
    getch();
    system("cls");
}

void search_obat(List_C C){
    infotype_C x;
    address_C P;
    cout<<endl;
    cout<<"Search Obat"<<endl;
    cout<<endl;
    cout<<"ID Obat: ";
    cin>>x.id;
    P = findelmsingle(C, x);
    if(P != NULL){
        cout<<endl;
        cout<<"Nama: "<<info(P).nama<<endl;
        cout<<"ID: "<<info(P).id<<endl;
        cout<<"Stok: "<<info(P).stok<<endl;
        cout<<"Harga: "<<info(P).harga<<endl;
    }
    else{
        cout<<"Obat Tidak diTemukan:"<<endl;
    }
    getch();
    system("cls");
}

void search_penyakit(List_P S){
    infotype_P y;
    address_P Q;
    cout<<endl;
    cout<<"Search Penyakit"<<endl;
    cout<<endl;
    cout<<"ID Penyakit: ";
    cin>>y.id;
    Q = findElm(S,y);
    if(Q != NULL){
        cout<<endl;
        cout<<"Nama: "<<info(Q).nama<<endl;
        cout<<"ID: "<<info(Q).id<<endl;
        cout<<"Tingkat Berbahaya: "<<info(Q).tb<<endl;
        cout<<"Gejala 1: "<<info(Q).gej1<<endl;
        cout<<"Gejala 2: "<<info(Q).gej2<<endl;
        cout<<"Gejala 3: "<<info(Q).gej3<<endl;
    }
    else{
        cout<<"Penyakit Tidak diTemukan:"<<endl;
    }
    getch();
    system("cls");
}

void search_relasi(list_R R, List_C C, List_P S){
    infotype_C x;
    infotype_P y;
    address_C P;
    address_P Q;
    address_R r;
    cout<<endl;
    cout<<"Search Relasi"<<endl;
    cout<<endl;
    cout<<"ID Obat: ";
    cin>>x.id;
    cout<<"ID Penyakit: ";
    cin>>y.id;
    P = findelmsingle(C,x);
    Q = findElm(S,y);
    if(P != NULL && Q != NULL){
        r = findelm(R,P,Q);
        if(r != NULL){
            cout<<endl;
            cout<<"Penyakitnya: "<<info(penyakit(r)).nama<<endl;
            cout<<"Obatnya: "<<info(obat(r)).nama<<endl;
        }
        else{
            cout<<"Relasi Tidak diTemukan:"<<endl;
        }
    }
    else{
        cout<<"Error"<<endl;
    }
    getch();
    system("cls");
}

void delete_relasi(list_R &R, List_C C, List_P S){
    infotype_C x;
    infotype_P y;
    address_C P;
    address_P Q;
    address_R r, p, q;
    cout<<endl;
    cout<<"Delete Relasi"<<endl;
    cout<<endl;
    cout<<"ID Obat : ";
    cin>>x.id;
    cout<<"ID Penyakit : ";
    cin>>y.id;
    P = findelmsingle(C,x);
    Q = findElm(S,y);
    if(P != NULL && Q != NULL && first(R) != NULL){
        r = findelm(R,P,Q);
        if(r == first(R)){
            deletefirst(R,r);
        }
        else if(r != first(R) && next(r) != NULL){
            p = r;
            r = first(R);
            while(next(r) != p){
                r = next(r);
            }
            deleteafter(R,r,q);
        }
        else{
            deletelast(R,r);
        }
    }
    else{
        cout<<"gagal delete :"<<endl;
    }
    getch();
    system("cls");
}

void delete_obat(List_C &C, list_R &R){
    infotype_C x;
    address_C P, P1, P2, P3;
    address_R r, r1, r2, r3;
    cout<<endl;
    cout<<"Delete Obat"<<endl;
    cout<<endl;
    cout<<"ID Obat : ";
    cin>>x.id;
    P = findelmsingle(C,x);
    if(P != NULL && first(C) != NULL && first(R) != NULL){
        r = first(R);
        while(r != NULL){
            if(obat(r) == P && r == first(R)){
                deletefirst(R,r3);
                r = first(R);
            }
            else if(obat(r) == P && r != first(R)){
                r1 = r;
                r = first(R);
                r2 = first(R);
                while(next(r2) != r1){
                    r2 = next(r2);
                }
                deleteafter(R,r2,r3);
            }
            else if(obat(r) == P && next(r) == NULL){
                deletelast(R,r3);
                r = first(R);
            }
            r = next(r);
        }
        if(P == first(C)){
            deleteFirstsingle(C,P3);
        }
        else if(P != first(C)){
            P1 = P;
            P2 = first(C);
            while(next(P2) != P1){
                P2 = next(P2);
            }
            deleteaftersingle(C,P2,P3);
        }
        else{
            deletelastsingle(C,P3);
        }
    }
    else{
        cout<<"gagal delete, Obat Tidak diTemukan :"<<endl;
    }
    getch();
    system("cls");
}

void delete_penyakit(List_P &S, list_R &R){
    infotype_P y;
    address_P P, P1, P2, P3;
    address_R r, r1, r2, r3;
    cout<<endl;
    cout<<"Delete Penyakit"<<endl;
    cout<<endl;
    cout<<"ID Penyakit : ";
    cin>>y.id;
    P = findElm(S,y);
    if(P != NULL && first(S) != NULL && first(R) != NULL){
        r = first(R);
        while(r != NULL){
            if(penyakit(r) == P && r == first(R)){
                deletefirst(R, r3);
                r = first(R);
            }
            else if(penyakit(r) == P && r != first(R)){
                r1 = r;
                r = first(R);
                r2 = first(R);
                while(next(r2) != r1){
                    r2 = next(r2);
                }
                deleteafter(R,r2,r3);
            }
            else if(penyakit(r) == P && next(r) == NULL){
                deletelast(R,r3);
                r = first(R);
            }
            r = next(r);
        }
        if(P == first(S)){
            deleteFirst(S, P3);
        }
        else if(P != first(S)){
            P1 = P;
            P2 = first(S);
            while(next(P2) != P1){
                P2 = next(P2);
            }
            deleteAfter(S, P2, P3);
        }
        else{
            deleteLast(S, P3);
        }
    }
    else{
        cout<<"delete gagal Penyakit tidak ditemukan:("<<endl;
    }
    getch();
    system("cls");
}
