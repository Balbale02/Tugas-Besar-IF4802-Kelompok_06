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
        return;
    }

    addressKeyword K_Baru;
    createElementKeyword(dataKey, K_Baru);
    int pilihan = -99;
    cout << "\n>>> OPSI TAMBAH KEYWORD KE: " << P->info.judul << " <<<" << endl;
    cin>>pilihan;

    switch (pilihan) {
        case 1:
            // --- Insert First ---
            insertFirstKeyword(P->firstKeyword, K_Baru);
            cout << "[Sukses] Keyword ditambahkan di awal." << endl;
            break;

        case 2:
            // --- Insert Last ---
            insertLastKeyword(P->firstKeyword, K_Baru);
            cout << "[Sukses] Keyword ditambahkan di akhir." << endl;
            break;

        case 3: {
            // --- Insert After ---
            // Pakai kurung kurawal {} karena ada deklarasi variabel di dalam case
            if (P->firstKeyword == nullptr) {
                cout << "[Info] List kosong, otomatis insert first." << endl;
                insertFirstKeyword(P->firstKeyword, K_Baru);
            } else {
                string namaPrec;
                cout << "Masukkan nama keyword sebelumnya (Predecessor): ";
                cin >> ws;
                getline(cin, namaPrec);

                addressKeyword Prec = findElementKeyword(P->firstKeyword, namaPrec);

                if (Prec != nullptr) {
                    insertAfterKeyword(P->firstKeyword, K_Baru, Prec);
                    cout << "[Sukses] Keyword ditambahkan setelah '" << namaPrec << "'." << endl;
                } else {
                    cout << "[Gagal] Keyword '" << namaPrec << "' tidak ditemukan. Batal insert." << endl;
                    return;
                }
            }
            break;
        }

        default:
            cout << "[Error] Pilihan tidak valid." << endl;
            return;
    }
    cout << "\n[UPDATE DATA PAPER: " << P->info.judul << "]" << endl;
    printKeywords(P->firstKeyword);
    cout << "---------------------------------------------" << endl;
}

void deleteKeywordFromPaper(ListPaper &L, string judulPaper, string namaKey) {
    addressPaper P = findElementPaper(L, judulPaper);

    if (P == nullptr) {
         cout << "[Error] Paper '" << judulPaper << "' tidak ditemukan." << endl;
         return;
    }
    addressKeyword firstK = P->firstKeyword;
    addressKeyword K_Hapus = nullptr;

    if (firstK == nullptr) {
        cout << "[Info] Tidak ada keyword untuk dihapus." << endl;
        return;
    }
    if (firstK->info.namaKeyword == namaKey) {
        deleteFirstKeyword(P->firstKeyword, K_Hapus);
        cout << "[Sukses] Keyword '" << namaKey << "' dihapus dari depan." << endl;
    }
    else {
        addressKeyword Prec = firstK;
        bool ketemu = false;
        while (Prec->next != nullptr) {
            if (Prec->next->info.namaKeyword == namaKey) {
                ketemu = true;
                break;
            }
            Prec = Prec->next;
        }
        if (ketemu) {
            deleteAfterKeyword(Prec, K_Hapus);
            cout << "[Sukses] Keyword '" << namaKey << "' berhasil dihapus." << endl;

        } else {
            cout << "[Gagal] Keyword '" << namaKey << "' tidak ditemukan." << endl;
            return;
        }
    }

    if (K_Hapus != nullptr) {
        delete K_Hapus;
    }

    cout << "\n[UPDATE DATA PAPER: " << P->info.judul << "]" << endl;
    printKeywords(P->firstKeyword);
    cout << "---------------------------------------------" << endl;
}

void sortPapersByTitle(ListPaper &L) {
    if (L.first == nullptr || L.first->next == nullptr) return;

    bool swapped = true;
    while (swapped) {
        swapped = false;
        addressPaper P = L.first;

        while (P->next != nullptr) {
            if (P->info.judul > P->next->info.judul) {
                InfotypePaper tempInfo = P->info;
                P->info = P->next->info;
                P->next->info = tempInfo;

                addressKeyword tempKey = P->firstKeyword;
                P->firstKeyword = P->next->firstKeyword;
                P->next->firstKeyword = tempKey;

                swapped = true;
            }
            P = P->next;
        }
    }
}

void sortEverythingAscending(ListPaper &L) {
    sortPapersByTitle(L);
    addressPaper P = L.first;
    while (P != nullptr) {
        sortKeywordsInPaper(P);

        P = P->next;
    }
    cout << "[Success] Paper dan Keyword sudah diurutkan A-Z." << endl;
}
