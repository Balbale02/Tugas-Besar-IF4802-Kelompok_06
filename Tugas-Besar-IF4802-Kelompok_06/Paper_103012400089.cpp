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
