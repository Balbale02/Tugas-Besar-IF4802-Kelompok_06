#include "main_user.h"
#include "Paper.h"

void menuUser(){
    ListPaper L;
    addressPaper P, q, prev;
    InfotypePaper dataPaper;
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
                cout << "you choose option 3" << endl;
                // kode
                break;

            case 4  :
                cout << "you choose option 3" << endl;
                // kode
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

            case 0  :
                cout << "you choose option 3" << endl;
                // kode
                break;
        }
    }
}
