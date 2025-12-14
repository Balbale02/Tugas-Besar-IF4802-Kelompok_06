#include "main_user.h"
#include "Paper.h"

void menuUser(ListPaper &L) {
    addressPaper P, q, prev;
    addressKeyword k, r, Prev, curr;
    InfotypePaper dataPaper;
    InfotypeKeyword dataK;
    string judulCari, pilihKategori;
    int option = -99;

    while (option != 0) {
        system("cls");
        cout << "========================== USER MENU ============================" << endl;
        cout << "|| 1. Insert Paper (Sorted by Tahun Terbit)                    ||" << endl;
        cout << "|| 2. Bersihkan Paper Invalid (Range Tahun)                    ||" << endl;
        cout << "|| 3. Insert Keyword (Sorted by Relevansi)                     ||" << endl;
        cout << "|| 4. Hapus Keyword Kategori Tertentu (Bulk Delete)            ||" << endl;
        cout << "|| 5. Komputasi                                                ||" << endl;
        cout << "|| 6. Cari Paper by Tahun                                      ||" << endl;
        cout << "|| 7. View Paper (Parent Only)                                 ||" << endl;
        cout << "|| 8. View Unik Keyword (No Duplicate)                         ||" << endl;
        cout << "|| 9. Tampilkan Seluruh Data (Parent + Child)                  ||" << endl;
        cout << "|| 0. Back                                                     ||" << endl;
        cout << "=================================================================" << endl;
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
           case 1: {
                bool inserted = false;
                cout << "\n--- Insert Paper Terurut Tahun ---" << endl;
                cout << "Judul        : "; cin >> dataPaper.judul;
                cout << "DOI          : "; cin >> dataPaper.doi;
                cout << "Penulis      : "; cin >> dataPaper.penulis;
                cout << "Email        : "; cin >> dataPaper.email;
                cout << "Afiliasi     : "; cin >> dataPaper.afiliasi;
                cout << "Tahun Terbit : "; cin >> dataPaper.tahunTerbit;

                createElementPaper(dataPaper, P);

                if (isPaperEmpty(L)) {
                    insertFirstPaper(L, P);
                }
                else if (dataPaper.tahunTerbit < L.first->info.tahunTerbit) {
                    insertFirstPaper(L, P);
                }
                else {
                    q = L.first;
                    while (q->next != nullptr) {
                        if (dataPaper.tahunTerbit < q->next->info.tahunTerbit) {
                            insertAfterPaper(L, q, P);
                            inserted = true;
                            break;
                        }
                        q = q->next;
                    }
                    if (!inserted) {
                        insertLastPaper(L, P);
                    }
                }
                cout << "[Sukses] Paper berhasil dimasukkan." << endl;
                cout << "\nTekan ENTER untuk kembali ke menu...";
                cin.ignore();
                cin.get();
                break;
            }

           case 2  :
               int tahunaMaks, tahunMin;

               if (isPaperEmpty(L)) {
                    cout << "List paper masih kosong, tidak ada data yang bisa dibersihkan." << endl;
                    cout << "\nTekan ENTER untuk kembali ke menu...";
                    cin.ignore();
                    cin.get();
                    break;
               }

               printPaper(L);
               cout << "Tentukan tahun minimal dan tahun maksimal" << endl;
               cout << "Tahun maksimal: ";
               cin >> tahunaMaks;
               cout << "Tahun minimal: ";
               cin >> tahunMin;

               if(tahunMin > tahunaMaks){
                    cout << "Input tahun tidak valid!" << endl;
                    break;
               }


               while(!isPaperEmpty(L) && L.first->info.tahunTerbit < tahunMin){
                    deleteFirstPaper(L, P);
               }

               if (isPaperEmpty(L)) {
                    cout << "Pembersihan data paper yang invalid berhasil dilakukan" << endl;
                    cout << "\nTekan ENTER untuk kembali ke menu...";
                    cin.ignore();
                    cin.get();
                    break;
               }

               prev = L.first;
               q = prev->next;
               while(q != nullptr && q != L.last){
                    if(q->info.tahunTerbit < tahunMin ||q->info.tahunTerbit > tahunaMaks){
                        deleteAfterPaper(L, prev, P);
                        q = prev->next;
                    }else{
                        prev = q;
                        q = q->next;
                    }
               }

               while(!isPaperEmpty(L) && L.last->info.tahunTerbit > tahunaMaks){
                    deleteLastPaper(L, P);
               }

              cout << "Pembersihan data paper yang invalid berhasil dilakukan" << endl;

              cout << endl;
              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();

               break;

            case 3  :
                bool Insert, sukses;
                Insert = false;
                sukses = false;

                printPaper(L);
                cout << "Keyowrd mau dimasukan paper dengan judul apa: ";
                cin >> judulCari;

                q = findElementPaper(L, judulCari);
                if(q == nullptr){
                    cout << "Judul tidak ditemukan!" << endl;
                }else{
                    cout << "\n--- Input Keyword (Sorted Relevansi) ---" << endl;
                    cout << "Nama Keyword: ";
                    cin >> dataK.namaKeyword;
                    dataK.kategori = pilihKategoriValid();
                    cout << "Relevansi (1-10): ";
                    cin >> dataK.relevansi;

                    if (dataK.relevansi >= 10){
                        dataK.relevansi = 10;
                    }else if(dataK.relevansi<=1){
                        dataK.relevansi = 1;
                    }

                    createElementKeyword(dataK, k);

                    if(q->firstKeyword == nullptr){
                        insertFirstKeyword(q->firstKeyword, k);
                    }else if(dataK.relevansi < q->firstKeyword->info.relevansi){
                        insertFirstKeyword(q->firstKeyword, k);
                    }else{
                        r = q->firstKeyword;
                        while(r->next != nullptr){
                            if(dataK.relevansi < r->next->info.relevansi ){
                                insertAfterKeyword(q->firstKeyword, k, r);
                                Insert = true;
                                break;
                            }
                            r = r->next;
                        }

                        if(!Insert){
                        insertLastKeyword(q->firstKeyword, k);
                        }
                    }
                    sukses = true;;
                }

                cout << endl;
                if(sukses){
                    cout << "Keyword berhasil dimasukan kedalam list" << endl;
                }else{
                    cout << "Keyword gagal dimasukan dalam list" << endl;
                }
                cout << "\nTekan ENTER untuk kembali ke menu...";
                cin.ignore();
                cin.get();

                break;

            case 4  :
                bool hapus;

                hapus = false;
                cout << "---Berikut merupakan tampilan semua data---" << endl;
                printAllData(L);

                cout << "Pilih kategori keyword yang ingin dihapus: ";
                pilihKategori = pilihKategoriValid();

                q = L.first;
                while(q != nullptr){
                    curr = q->firstKeyword;
                    Prev = nullptr;

                    while(curr != nullptr){
                        if(curr->info.kategori == pilihKategori){
                            hapus = true;

                            if(Prev == nullptr){
                                deleteFirstKeyword(q->firstKeyword, k);
                                curr = q->firstKeyword;
                            }else if(curr->next == nullptr){
                                deleteLastKeyword(q->firstKeyword, k);
                                curr = nullptr;
                            }else{
                                deleteAfterKeyword(Prev, k);
                                curr = Prev->next;
                            }
                            delete k;
                        }else{
                            Prev = curr;
                            curr = curr->next;
                        }
                    }
                    q = q->next;
                }

                if(hapus){
                    cout << "Keyword dengan kategori " << pilihKategori << " berhasil dihapus!" << endl;
                }else{
                    cout << "Tidak ada keyword dengan kategori tersebut" << endl;
                }

                cout << endl;
                cout << "Berikut merupakan data setelah penghapusan" << endl;
                printAllData(L);

                cout << "\nTekan ENTER untuk kembali ke menu...";
                cin.ignore();
                cin.get();
                break;

            case 5  :
                cout << "you choose option 5" << endl;
                // kode
                break;

            case 6  :
                int cariTahun;
                bool found = false;

                if (isPaperEmpty(L)) {
                    cout << "[Info] List Kosong." << endl;
                } else {
                    cout << "Masukkan Tahun Terbit yang dicari: ";
                    cin >> cariTahun;

                    cout << "\n=== HASIL PENCARIAN PAPER TAHUN " << cariTahun << " ===" << endl;
                    q = L.first;
                    int no = 1;
                    while (q != nullptr) {
                        if (q->info.tahunTerbit == cariTahun) {
                            cout << no << ". " << q->info.judul
                                 << " | Penulis: " << q->info.penulis
                                 << " | Afiliasi: " << q->info.afiliasi << endl;
                            found = true;
                            no++;
                        }
                        q = q->next;
                    }

                    if (!found) {
                        cout << "Tidak ditemukan paper pada tahun " << cariTahun << "." << endl;
                    }
                }
                cout << "\nTekan ENTER..."; cin.ignore(); cin.get();
                break;

            case 7  :
              cout << endl;
              cout << "===== DATA PAPER =====" << endl;
              printPaper(L);
              cout << "======================" << endl;

              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();
              break;

                break;

            case 8  :
                if (isPaperEmpty(L)) {
                    cout << "[Info] List Paper Kosong." << endl;
                } else {
                    cout << "\n=== DAFTAR KEYWORD UNIK (SEMUA PAPER) ===" << endl;
                    addressKeyword headUnique = nullptr;
                    addressKeyword tempK, check;
                    q = L.first;
                    int nomor = 1;

                    while (q != nullptr) {
                        curr = q->firstKeyword;

                        while (curr != nullptr) {
                            bool isDuplicate = false;
                            check = headUnique;
                            while (check != nullptr) {
                                if (check->info.namaKeyword == curr->info.namaKeyword &&
                                    check->info.kategori == curr->info.kategori) {
                                    isDuplicate = true;
                                    break;
                                }
                                check = check->next;
                            }
                            if (!isDuplicate) {
                                cout << nomor << ". " << curr->info.namaKeyword
                                     << " [" << curr->info.kategori << "]" << endl;
                                nomor++;
                                createElementKeyword(curr->info, tempK);
                                insertFirstKeyword(headUnique, tempK);
                            }

                            curr = curr->next;
                        }
                        q = q->next;
                    }

                    while (headUnique != nullptr) {
                        deleteFirstKeyword(headUnique, tempK);
                        delete tempK;
                    }
                }
                cout << "=========================================" << endl;
                cout << "\nTekan ENTER...";
                cin.ignore();
                cin.get();
                break;

            case 9  :
                cout << "----BERIKUT TAMPILAN SELURUH DATA----" << endl;
                printAllData(L);

                cout << "\nTekan ENTER untuk kembali ke menu...";
                cin.ignore();
                cin.get();
                break;

            case 0  :
                cout << "Keluar dari program....." << endl;

                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
                cin.ignore();
                cin.get();
                break;
        }
    }
}
