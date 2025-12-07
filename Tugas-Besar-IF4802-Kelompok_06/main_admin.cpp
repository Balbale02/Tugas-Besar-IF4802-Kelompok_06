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

              createElementPaper(dataPaper, P);

              cout << "Elemen ingin dimasukan setelah judul paper apa: ";
              cin >> judulCari;

              q = findElementPaper(L, judulCari);

              if(q == nullptr){
                cout << "Paper tidak ditemukan!";
              }else{
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
              cout << "you choose option 2" << endl;
              // write your code here

              break;

           case 5  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;

           case 6  :
              cout << "you choose option 2" << endl;
              // write your code here

              break;

           case 7  :
              cout << "you choose option 2" << endl;
              //isi

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
