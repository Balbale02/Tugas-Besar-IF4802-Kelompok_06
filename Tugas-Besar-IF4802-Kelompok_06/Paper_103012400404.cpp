#include "Paper.h"

void createListPaper(ListPaper &L) {
    L.first = nullptr;
    L.last = nullptr;
}

void createElementPaper(InfotypePaper data, addressPaper &P) {
    P = new elementPaper;
    P->info = data;

    P->next = nullptr;
    P->prev = nullptr;

    P->firstKeyword = nullptr;
}

void insertLastPaper(ListPaper &L, addressPaper P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteLastPaper(ListPaper &L, addressPaper &P) {
    P = L.last;
    if (L.first == nullptr) {
        P = nullptr;
        cout <<"List masih kosong";
    }else if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = L.last->prev;
        L.last->next = nullptr;
        P->prev = nullptr;
    }
}

addressPaper findElementPaper(ListPaper L, string judulCari) {
    addressPaper P = L.first;

    while (P != nullptr) {
        if (P->info.judul == judulCari) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void addKeywordToPaper(ListPaper &L, string judulPaper, InfotypeKeyword dataKey) {
    addressPaper P = findElementPaper(L, judulPaper);

    if (P == nullptr) {
        cout << "[Error] Paper '" << judulPaper << "' tidak ditemukan." << endl;
    } else {
        // Nanti panggil fungsi child di sini
        // insertLastKeyword(P->firstKeyword, ...);
        cout << "[Info] Paper ditemukan, siap insert keyword." << endl;
    }
}

void deleteKeywordFromPaper(ListPaper &L, string judulPaper, string namaKey) {
    addressPaper P = findElementPaper(L, judulPaper);

    if (P == nullptr) {
         cout << "[Error] Paper '" << judulPaper << "' tidak ditemukan." << endl;
    } else {
        cout << "[Info] Paper ditemukan, siap delete keyword." << endl;
    }
}
