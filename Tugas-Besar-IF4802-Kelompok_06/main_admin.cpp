#include "main_admin.h"
#include "Paper.h"

void menuAdmin(){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu ============ " << endl;
        cout << "|| 1. Parent                ||" << endl;
        cout << "|| 2. Child                 ||" << endl;
        cout << "|| 0. back                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              menuParent();
              continue;
           case 2  :
              cout << "you choose option 2" << endl;
              menuChild();
              continue;
        }
    }
}


void menuParent(){
    int option=-99;
    ListPaper L;
    addressPaper P, q;
    InfotypePaper dataPaper;
    string judulCari;

     createListPaper(L);

    while (option != 0) {
        system("cls");
        cout << "============ Menu ============ " << endl;
        cout << "|| 1.  Insert first          ||" << endl;
        cout << "|| 2.  Insert last           ||" << endl;
        cout << "|| 3.  Insert after          ||" << endl;
        cout << "|| 4.  Delete first          ||" << endl;
        cout << "|| 5.  Delete last           ||" << endl;
        cout << "|| 6.  Delete after          ||" << endl;
        cout << "|| 7.  Cari paper            ||" << endl;
        cout << "|| 8.  View parent           ||" << endl;
        cout << "|| 0.  Exit                  ||"<< endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
           case 0  :
              cout << "Keluar dari program..." << endl;
              break;

           case 1  :
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

              insertFirstPaper(L, P);

              cout << endl;
              cout << "Elemen sudah dimasukan pada elemen pertama" << endl;
              cout << endl;
              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();

              break;
           case 2  :
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

              insertLastPaper(L, P);

              cout << endl;
              cout << "Elemen sudah dimasukan pada elemen terakhir" << endl;
              cout << endl;
              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();

              break;

           case 3  :
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


              cout << "Elemen ingin dimasukan setelah judul paper apa: ";
              cin >> judulCari;

              q = findElementPaper(L, judulCari);

              if(q == nullptr){
                cout << "Paper tidak ditemukan!";
              }else{
                createElementPaper(dataPaper, P);
                insertAfterPaper(L, q, P);
                cout << "Elemen sudah dimasukan setelah elemen dengan paper berjudul " << judulCari << endl;
              }

              cout << endl;
              cout << endl;
              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();

              break;

           case 4  :
              deleteFirstPaper(L, P);
              if(P == nullptr){
                cout << "List masih kosong, tidak ada data yang dihapus." <<endl;
              }else{
                cout << "Elemen pertama sudah dihapus dari list" << endl;
              }

              cout << endl;
              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();

              break;

           case 5  :
              deleteLastPaper(L, P);
              if(P == nullptr){
                cout << "List masih kosong, tidak ada data yang dihapus." <<endl;
              }else{
                cout << "Elemen terakhir sudah dihapus dari list" << endl;
              }

              cout << endl;
              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();

              break;

           case 6  :
              cout << "Masukan judul paper dimana elemen setelahnya akan dihapus";
              cin >> judulCari;

              q = findElementPaper(L, judulCari);

              if(q == nullptr){
                cout << "Paper tidak ditemukan" << endl;
              }else if(q == L.last){
                cout << "Elemen setelah paper ini tidak ada" << endl;
              }else{
                deleteAfterPaper(L, q, P);
                if(P != nullptr){
                    cout << "elemen setelah judul " << judulCari << " telah dihapus" << endl;
                }else{
                    cout << "Penghapusan gagal" << endl;
                }
              }

              cout << endl;
              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();

              break;

           case 7  :
              cout << "Masukan judul paper yang ingin dicari: ";
              cin >> judulCari;

              q = findElementPaper(L, judulCari);

              if(q == nullptr){
                cout << "Paper tidak ditemukan!" << endl;
              }else{
                cout << "Paper ditemukan!" << endl;
                cout << "Berikut paper nya" << endl;
                cout << "Judul        : " << q->info.judul << endl;
                cout << "DOI          : " << q->info.doi << endl;
                cout << "Penulis      : " << q->info.penulis << endl;
                cout << "Email        : " << q->info.email << endl;
                cout << "Afiliasi     : " << q->info.afiliasi << endl;
                cout << "Tahun Terbit : " << q->info.tahunTerbit << endl;

              }

              cout << endl;
              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();

              break;

           case 8  :
              cout << endl;
              cout << "===== DATA PAPER =====" << endl;
              printPaper(L);
              cout << "======================" << endl;

              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();
              break;

            default:
              cout << "Pilihan tidak valid!" << endl;
              cin.ignore();
              cin.get();
              break;
        }
    }
}

void menuChild(){
    addressPaper q;
    int option=-99;


    while (option != 0) {
        system("cls");
        cout << "============ Menu ============ " << endl;
        cout << "|| 1.  Buat list parent      ||" << endl;
        cout << "|| 2.  Buat elemen parent    ||" << endl;
        cout << "|| 3.  Insert first          ||" << endl;
        cout << "|| 4.  Insert last           ||" << endl;
        cout << "|| 5.  Insert after          ||" << endl;
        cout << "|| 6.  Delete first          ||" << endl;
        cout << "|| 7.  Delete last           ||" << endl;
        cout << "|| 8.  Delete after          ||" << endl;
        cout << "|| 9.  Cari paper            ||" << endl;
        cout << "|| 10. View parent           ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;

              break;
           case 2  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;
            // continue for another case here
        }
    }
}
