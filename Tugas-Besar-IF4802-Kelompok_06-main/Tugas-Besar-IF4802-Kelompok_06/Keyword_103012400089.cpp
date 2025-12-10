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

void sortKeywordsInPaper(addressPaper P) {
    if (P == nullptr || P->firstKeyword == nullptr) return;

    bool swapped = true;
    while (swapped) {
        swapped = false;
        addressKeyword K = P->firstKeyword;

        while (K->next != nullptr) {
            if (K->info.namaKeyword > K->next->info.namaKeyword) {
                InfotypeKeyword temp = K->info;
                K->info = K->next->info;
                K->next->info = temp;

                swapped = true;
            }
            K = K->next;
        }
    }
}


