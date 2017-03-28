/**
Nama: Fahrurrozi
NIM: 1301164213
Mengerjakan satu halaman ini
*/
#include<iostream>
#include "singlelist.h"
#include "doublelist.h"
#include "relasi.h"
#include <windows.h>
using namespace std;

void insertobat(List_C &C);
void insertpenyakit(List_P &S);
void relasi(list_R &R, List_C A, List_P S);
void list_obat(List_C C);
void list_penyakit(List_P S);
void list_relasi(list_R R);
void search_obat(List_C C);
void search_penyakit(List_P S);
void search_relasi(list_R R, List_C C, List_P S);
void delete_obat(List_C &C, list_R &R);
void delete_penyakit(List_P &S, list_R &R);
void delete_relasi(list_R &R, List_C C, List_P S);

void menu(List_C C, List_P S, list_R R){
    int ch;
    do{
        cout<<endl;
        cout<<"Program Data Relasi Obat dan Penyakitnya"<<endl;
        cout<<endl;
        Sleep(20);
        cout<<"     1. Input Data Obat"<<endl;
        Sleep(20);
        cout<<"     2. Input Data Penyakit"<<endl;
        Sleep(20);
        cout<<"     3. Input Data Relasi"<<endl;
        Sleep(20);
        cout<<"     4. List Obat"<<endl;
        Sleep(20);
        cout<<"     5. List Penyakit"<<endl;
        Sleep(20);
        cout<<"     6. List Relasi"<<endl;
        Sleep(20);
        cout<<"     7. Search Obat"<<endl;
        Sleep(20);
        cout<<"     8. Search Penyakit"<<endl;
        Sleep(20);
        cout<<"     9. Search Relasi"<<endl;
        Sleep(20);
        cout<<"    10. Delete Obat"<<endl;
        Sleep(20);
        cout<<"    11. Delete Penyakit"<<endl;
        Sleep(20);
        cout<<"    12. Delete Relasi"<<endl;
        Sleep(20);
        cout<<"     0. Keluar"<<endl;
        Sleep(20);
        cout<<endl;
        Sleep(20);
        cout<<"Pilih : ";
        cin>>ch;
        switch(ch){
            case 1:
                system("cls");
                insertobat(C);
                break;
            case 2:
                system("cls");
                insertpenyakit(S);
                break;
            case 3:
                system("cls");
                relasi(R,C,S);
                break;
            case 4:
                system("cls");
                list_obat(C);
                break;
            case 5:
                system("cls");
                list_penyakit(S);
                break;
            case 6:
                system("cls");
                list_relasi(R);
                break;
            case 7:
                system("cls");
                search_obat(C);
                break;
            case 8:
                system("cls");
                search_penyakit(S);
                break;
            case 9:
                system("cls");
                search_relasi(R,C,S);
                break;
            case 10:
                system("cls");
                delete_obat(C,R);
                break;
            case 11:
                system("cls");
                delete_penyakit(S,R);
                break;
            case 12:
                system("cls");
                delete_relasi(R,C,S);
                break;
        }
    }while(ch != 0);
}
int main()
{
    List_C C;
    List_P S;
    list_R R;
    createListsingle(C);
    createList(S);
    createlist(R);
    menu(C,S,R);
    return 0;
}
