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
    if(isPaperEmpty(L)){
        L.first = P;
        L.last = P;
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
        return;
    }

    if(prec->next == nullptr){
        cout << "List setelah list ini kosong" << endl;
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
    addressKeyword p;
    int i, k;

    if(L.first == nullptr){
        cout << "Data masih kosong" << endl;
        return ;
    }

    q = L.first;
    i = 1;

    cout << "Berikut merupakan tampilan seluruh data" << endl;
    while(q != nullptr){
        k = 1;
        cout << "PAPER KE-" << i << endl;
        cout << "Judul       : " << q->info.judul << endl;
        cout << "doi         : " << q->info.doi << endl;
        cout << "Penulis     : " << q->info.penulis << endl;
        cout << "Email       : " << q->info.email << endl;
        cout << "Afiliasi    : " << q->info.afiliasi << endl;
        cout << "Tahun terbit: " << q->info.tahunTerbit << endl;
        cout << endl;
        cout << "Dengan list keyword sebagai berikut" << endl;

        p = q->firstKeyword;
        while(p != nullptr){
            cout << "KEYWORD KE-" << k << endl;
            cout << "Nama keyword: " << p->info.namaKeyword << endl;
            cout << "Kategori    : " << p->info.kategori << endl;
            cout << "Relevansi   : " << p->info.relevansi << "/10" << endl;
            cout << endl;
            p = p->next;
            k++;
        }
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
        cout << "Judul       : " << q->info.judul << endl;
        cout << "doi         : " << q->info.doi << endl;
        cout << "Penulis     : " << q->info.penulis << endl;
        cout << "Email       : " << q->info.email << endl;
        cout << "Afiliasi    : " << q->info.afiliasi << endl;
        cout << "Tahun terbit: " << q->info.tahunTerbit << endl;
        q = q->next;
        i++;
    }
}
