#include <iostream>
#include "Paper.h"

using namespace std;

bool isPaperEmpty(ListPaper &L){
    return L.first == nullptr;
}
void insertFirstPaper(ListPaper &L, addressPaper P){
    if(isPaperEmpty(L)){
        L.first = P;
        L.last = P;
    }else{
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}
void insertAfterPaper(ListPaper &L, addressPaper prec, addressPaper P){
    if(prec == nullptr){
        cout << "precursor tidak valid" << endl;
        return;
    }

    if(isPaperEmpty(L)){
        L.first = P;
        L.last = P;
        P->next = nullptr;
        P->prev = nullptr;
    }else if(prec == L.last){
         prec->next = P;
         P->prev = prec;
         P->next = nullptr;
         L.last = P;
    }else{
        P->next = prec->next;
        P->prev = prec;
        prec->next->prev = P;
        prec->next = P;

    }
}
void deleteFirstPaper(ListPaper &L, addressPaper &P){
    if(isPaperEmpty(L)){
        cout << "List masih kosong" << endl;
        P = nullptr;
    }else if(L.first == L.last){
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }else{
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
        L.first->prev = nullptr;
    }
}
void deleteAfterPaper(ListPaper &L, addressPaper prec, addressPaper &P){
    if(isPaperEmpty(L)){
        cout << "List masih kosong" << endl;
        P = nullptr;
        return;
    }

    if(prec->next == nullptr){
        cout << "List setelah list ini kosong" << endl;
        P = nullptr;
        return;
    }

    P = prec->next;

    if(P == L.last){
        L.last = prec;
        prec->next = nullptr;
        P->prev = P->next = nullptr;
    }
    else {
        prec->next = P->next;
        P->next->prev = prec;
        P->prev = P->next = nullptr;
    }

}

void printAllData(ListPaper L){
    addressPaper q;
    int i;

    if(L.first == nullptr){
        cout << "Data masih kosong" << endl;
        return;
    }

    q = L.first;
    i = 1;

    cout << "Berikut merupakan tampilan seluruh data" << endl;

    while(q != nullptr){
        cout << "========== PAPER KE-" << i << " ==========" << endl;
        cout << "Judul        : " << q->info.judul << endl;
        cout << "DOI          : " << q->info.doi << endl;
        cout << "Penulis      : " << q->info.penulis << endl;
        cout << "Email        : " << q->info.email << endl;
        cout << "Afiliasi     : " << q->info.afiliasi << endl;
        cout << "Tahun terbit : " << q->info.tahunTerbit << endl;

        cout << "List keyword :" << endl;

        printKeywords(q->firstKeyword);
        cout << endl;
        q = q->next;
        i++;
    }
}
void printPaper(ListPaper L){
    addressPaper q;
    int i;

    q = L.first;
    i = 1;

    if(L.first == nullptr){
        cout << "Data masih kosong" << endl;
        return ;
    }

    cout << "Berikut tampilan seluruh paper" << endl;

    while(q != nullptr){
        cout << "PAPER KE-" << i << endl;
        cout << endl;
        cout << "Judul       : " << q->info.judul << endl;
        cout << "doi         : " << q->info.doi << endl;
        cout << "Penulis     : " << q->info.penulis << endl;
        cout << "Email       : " << q->info.email << endl;
        cout << "Afiliasi    : " << q->info.afiliasi << endl;
        cout << "Tahun terbit: " << q->info.tahunTerbit << endl;
        cout << endl;
        q = q->next;
        i++;
    }
}

