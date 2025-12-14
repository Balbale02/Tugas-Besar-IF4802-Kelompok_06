#include "main_user.h"
#include "Paper.h"

void menuUser(){
    ListPaper L;
    addressPaper P, q, prev;
    addressKeyword k, r, Prev, curr;
    InfotypePaper dataPaper;
    InfotypeKeyword dataK;
    string judulCari, pilihKategori;
    int option=-99, pilihTahun;

    createListPaper(L);

    while (option != 0) {
        system("cls");
        cout << "===========================Menu==================================" << endl;
        cout << "|| 1. Insert paper berdasarkan tahun terbit                    ||" << endl;
        cout << "|| 2. Pembersihan paper invalid berdasarkan tahun akreditasi   ||" << endl;
        cout << "|| 3. Insert Keyword berdasarkan besar relevansi               ||" << endl;
        cout << "|| 4. Hapus keyword yang mengandung kategori tertentu          ||" << endl;
        cout << "|| 5. komputasi                                                ||" << endl;
        cout << "|| 6. Mencari paper dengan tahun terbit tertentu               ||" << endl;
        cout << "|| 7. View paper                                               ||" << endl;
        cout << "|| 8. Menampilkan keyword semua keyword secara unik            ||" << endl;
        cout << "|| 9. Tampilkan seluruh data                                   ||" << endl;
        cout << "|| 0. back                                                     ||" << endl;
        cout << "================================================================ " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1: {
            bool inserted = false;

            cout << "Paper akan dimasukan dari paper yang paling lama diterbitkan hingga yang terbaru" << endl;
            cout << "Silahkan masukan data paper" << endl;

            cout << "Judul        : ";
            cin >> dataPaper.judul;
            cout << "DOI          : ";
            cin >> dataPaper.doi;
            cout << "Penulis      : ";
            cin >> dataPaper.penulis;
            cout << "Email        : ";
            cin >> dataPaper.email;
            cout << "Afiliasi     : ";
            cin >> dataPaper.afiliasi;
            cout << "Tahun Terbit : ";
            cin >> dataPaper.tahunTerbit;

            createElementPaper(dataPaper, P);


            if (L.first == nullptr) {
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

            cout << endl;
            cout << "Paper berhasil dimasukan dalam list" << endl;
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
                    cout << "Keyowrd akan dimasukan terurut berdasarkan relevansi" << endl;
                    cout << "Nama Keyword: ";
                    cin >> dataK.namaKeyword;
                    cout << "Kategori: ";
                    cin >> dataK.kategori;
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
                cin >> pilihKategori;

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
                cout << "you choose option 3" << endl;
                // kode
                break;

            case 6  :
                cout << "you choose option 3" << endl;
                // kode
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
                cout << "you choose option 3" << endl;
                // kode
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
