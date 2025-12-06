#include "Paper.h"

void createElementKeyword(InfotypeKeyword data, addressKeyword &p){
    p = new elementKeyword;
    p->info.namaKeyword = data.namaKeyword;
    p->info.kategori = data.kategori;
    p->info.relevansi = data.relevansi;
    p->next = nullptr;
}

void insertFirstKeyword(addressKeyword &first, addressKeyword P){
    if(first == nullptr){
        first = P;
    }else{
        P->next = first;
        first = P;
    }
}

void deleteFirstKeyword(addressKeyword &first, addressKeyword &P){
    if(first == nullptr){
        cout << "List keyword masih kosong" << endl;
        P = nullptr;
    }else if(first->next == nullptr){
        P = first;
        first = nullptr;
    }else{
        P = first;
        first = P->next;
        P->next = nullptr;
    }
}

void deleteLastKeyword(addressKeyword &first, addressKeyword &P){
    if(first == nullptr){
        cout << "List keyword masih kosong" << endl;
        P = nullptr;
    }else if(first->next == nullptr){
        P = first;
        first = nullptr;
    }else{
        addressKeyword q;

        q = first;
        while(q->next->next != nullptr){
            q = q->next;
        }
        P = q->next;
        q->next = nullptr;
    }
}


