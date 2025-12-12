#include "main_user.h"
#include "Paper.h"

void menuUser(){
    ListPaper L;
    addressPaper P, q;
    InfotypePaper dataPaper;
    int option=-99;

    createListPaper(L);

    while (option != 0) {
        system("cls");
        cout << "===========================Menu=============================  " << endl;
        cout << "|| 1. Insert paper berdasarkan tahun terbit                ||" << endl;
        cout << "|| 2. Hapus paper 5 tahun terakhir(Berdasarkan input)      ||" << endl;
        cout << "|| 3. Insert Keyword berdasarkan besar relevansi           ||" << endl;
        cout << "|| 4. Hapus keyword yang mengandung kategori tertentu      ||" << endl;
        cout << "|| 5. komputasi                                            ||" << endl;
        cout << "|| 6. Mencari paper dengan tahun terbit tertentu           ||" << endl;
        cout << "|| 7. View paper                                           ||" << endl;
        cout << "|| 8. Menampilkan keyword semua keyword secara unik        ||" << endl;
        cout << "|| 0. back                                                 ||" << endl;
        cout << "============================================================ " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              addressPaper q;

              cout << "Paper akan dimasukan dari paper yang paling lama diterbitkan hingga yang terbaru" << endl;
              cout << "Silahkan masukan data elemen parent" << endl;
              cout << "Judul: ";
              cin >> dataPaper.judul;
              cout << "Doi: ";
              cin >> dataPaper.doi;
              cout << "Penulis: ";
              cin >> dataPaper.penulis;
              cout << "Email: ";
              cin >> dataPaper.email;
              cout << "Afiliasi: ";
              cin >> dataPaper.afiliasi;
              cout << "Tahun terbit: ";
              cin >> dataPaper.tahunTerbit;

              createElementPaper(dataPaper, P);

              q = L.first;
              if(q == nullptr){
                insertFirstPaper(L, P);
                cout << "Paper berhasil dimasukan dalam list" << endl;
                return;
              }

              if(dataPaper.tahunTerbit < q->info.tahunTerbit){
                insertFirstPaper(L, P);
                cout << "Paper berhasil dimasukan dalam list" << endl;
                return;
              }


              while(q->next != nullptr){
                if(dataPaper.tahunTerbit < q->next->info.tahunTerbit){
                    insertAfterPaper(L, q, P);
                    cout << "Paper berhasil dimasukan dalam list" << endl;
                    return;
                }
                q = q->next;
              }

              insertLastPaper(L, P);
              cout << "Paper berhasil dimasukan dalam list" << endl;

               break;
           case 2  :
               cout << "you choose option 2" << endl;
               // kode
               break;
            case 3  :
                cout << "you choose option 3" << endl;
                // kode
                break;
        }
    }
}
