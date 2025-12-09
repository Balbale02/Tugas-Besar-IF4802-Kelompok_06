#include "paper.h"

void insertLastKeyword(addressKeyword &first, addressKeyword P) {
    if (first == nullptr) {
        first = P;
    } else {
        addressKeyword last = first;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = P;
    }
}

void insertAfterKeyword(addressKeyword &first, addressKeyword P, addressKeyword prec) {
    if (prec != nullptr) {
        P->next = prec->next;
        prec->next = P;
    }
}

void deleteAfterKeyword(addressKeyword prec, addressKeyword &P) {
    P = prec->next;
    prec->next = P->next;
    P->next = nullptr;
}

addressKeyword findElementKeyword(addressKeyword first, string namaCari) {
    addressKeyword P = first;
    while (P != nullptr) {
        if (P->info.namaKeyword == namaCari) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
}

void printKeywords(addressKeyword first) {
    if (first == nullptr) {
        cout << "\t(Tidak ada keyword)" << endl;
    } else {
        addressKeyword P = first;
        int nomor = 1;

        while (P != nullptr) {
            cout << "\tKEYWORD KE-" << nomor << endl;
            cout << "\tNama keyword: " << P->info.namaKeyword << endl;
            cout << "\tKategori    : " << P->info.kategori << endl;
            cout << "\tRelevansi   : " << P->info.relevansi << "/10" << endl;
            cout << endl;

            P = P->next;
            nomor++;
        }
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
