#include "main_admin.h"
#include "Paper.h"

void menuAdmin(ListPaper &L){
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
              menuParent(L);
              continue;
           case 2  :
              cout << "you choose option 2" << endl;
              menuChild(L);
              continue;
        }
    }
}


void menuParent(ListPaper &L){
    int option=-99;
    addressPaper P, q;
    InfotypePaper dataPaper;
    string judulCari;

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
        cout << "|| 8.  View paper            ||" << endl;
        cout << "|| 0.  Exit                  ||"<< endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
           case 0  :
              cout << "Keluar dari menu parent..." << endl;
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

              cout << endl << "Elemen sudah dimasukan pada elemen pertama" << endl << endl;
              char jawab;
                do {
                    cout << "\nIngin tambah keyword sekarang? (y/n): ";
                    cin >> jawab;
                    if (jawab == 'y' || jawab == 'Y') {
                        InfotypeKeyword dataK;
                        cout << "   Nama Keyword (tanpa spasi): ";
                        cin >> dataK.namaKeyword;
                        dataK.kategori = pilihKategoriValid();

                        cout << "   Relevansi (1-10): "; cin >> dataK.relevansi;
                        addKeywordToPaper(L, dataPaper.judul, dataK);
                    }
                } while (jawab == 'y' || jawab == 'Y');
                break;
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

              cout << endl << "Elemen sudah dimasukan pada elemen terakhir" << endl << endl;
              do {
                    cout << "\nIngin tambah keyword sekarang? (y/n): ";
                    cin >> jawab;
                    if (jawab == 'y' || jawab == 'Y') {
                        InfotypeKeyword dataK;
                        cout << "   Nama Keyword (tanpa spasi): "; cin >> dataK.namaKeyword;
                        dataK.kategori = pilihKategoriValid();

                        cout << "   Relevansi (1-10): "; cin >> dataK.relevansi;
                        addKeywordToPaper(L, dataPaper.judul, dataK);
                    }
                } while (jawab == 'y' || jawab == 'Y');
                break;
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

              printPaper(L);
              cout << "Elemen ingin dimasukan setelah judul paper apa: ";
              cin >> judulCari;

              q = findElementPaper(L, judulCari);

              if(q == nullptr){
                cout << "Paper tidak ditemukan!";
              }else{
                createElementPaper(dataPaper, P);
                insertAfterPaper(L, q, P);
                cout << "Elemen sudah dimasukan setelah elemen dengan paper berjudul " << judulCari << endl;
                do {
                    cout << "\nIngin tambah keyword sekarang? (y/n): ";
                    cin >> jawab;
                    if (jawab == 'y' || jawab == 'Y') {
                        InfotypeKeyword dataK;
                        cout << "   Nama Keyword (tanpa spasi): "; cin >> dataK.namaKeyword;
                        dataK.kategori = pilihKategoriValid();

                        cout << "   Relevansi (1-10): "; cin >> dataK.relevansi;
                        addKeywordToPaper(L, dataPaper.judul, dataK);
                    }
                } while (jawab == 'y' || jawab == 'Y');
                break;
              }
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
              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();

              break;

           case 6  :
              cout << "Masukan judul paper dimana elemen setelahnya akan dihapus: ";
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
              cout << "\nTekan ENTER untuk kembali ke menu...";
              cin.ignore();
              cin.get();

              break;

           case 7  :
              cout << "Masukan judul paper yang ingin dicari: ";
              cin >> judulCari;

              q = findElementPaper(L, judulCari);

              if(q == nullptr){
                cout << "Paper tidak ditemukan!" << endl<<endl;
                cout <<"Ini List Paper yang ada" << endl;
                printPaper(L);
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

void menuChild(ListPaper &L){
    addressPaper q;
    addressKeyword key, prec;
    InfotypeKeyword dataK;
    int option=-99;
    string judulPaper, namaKeyword;

    while (option != 0) {
        system("cls");
        cout << "============ Menu ============ " << endl;
        cout << "|| 1.  Insert(All Insert)    ||" << endl;
        cout << "|| 2.  Delete first          ||" << endl;
        cout << "|| 3.  Delete last           ||" << endl;
        cout << "|| 4.  Delete after          ||" << endl;
        cout << "|| 5.  Cari keyword          ||" << endl;
        cout << "|| 6.  View keyword          ||" << endl;
        cout << "|| 0.  Exit                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {

           case 0  :
              cout << "Keluar dari menu child..." << endl;

              break;

           case 1  :
               printPaper(L);
                cout << "Judul Paper Target: ";
                cin >> judulPaper;

                if (findElementPaper(L, judulPaper) != nullptr) {
                    cout << "Nama Keyword : ";
                    cin >> dataK.namaKeyword;
                    dataK.kategori = pilihKategoriValid();

                    cout << "Relevansi    : ";
                    cin >> dataK.relevansi;
                    addKeywordToPaper(L, judulPaper, dataK);
                } else {
                    cout << "Paper tidak ditemukan." << endl;
                }

                cout << "\nTekan ENTER untuk kembali ke menu...";
                cin.ignore();
                cin.get();

              break;
           case 2:
                cout << "Judul Paper Target: ";
                cin >> judulPaper;
                q = findElementPaper(L, judulPaper);

                if (q == nullptr) {
                    cout << "[Error] Paper tidak ditemukan." << endl;
                } else {
                    deleteFirstKeyword(q->firstKeyword, key);

                    if (key != nullptr) {
                        cout << "[Sukses] Keyword '" << key->info.namaKeyword << "' dihapus dari depan." << endl;
                        delete key;
                        cout << "\n[List Keyword Terbaru]" << endl;
                        printKeywords(q->firstKeyword);
                    } else {
                        cout << "[Info] List keyword kosong, tidak ada yang dihapus." << endl;
                    }
                }

                cout << "\nTekan ENTER untuk kembali...";
                cin.ignore();
                cin.get();
                break;

            case 3:
                cout << "Judul Paper Target: ";
                cin >> judulPaper;
                q = findElementPaper(L, judulPaper);

                if (q == nullptr) {
                    cout << "[Error] Paper tidak ditemukan." << endl;
                } else {
                    deleteLastKeyword(q->firstKeyword, key);

                    if (key != nullptr) {
                        cout << "[Sukses] Keyword '" << key->info.namaKeyword << "' dihapus dari belakang." << endl;
                        delete key;
                        cout << "\n[List Keyword Terbaru]" << endl;
                        printKeywords(q->firstKeyword);
                    } else {
                        cout << "[Info] List keyword kosong/gagal hapus." << endl;
                    }
                }

                cout << "\nTekan ENTER untuk kembali...";
                cin.ignore();
                cin.get();
                break;

            case 4:
                cout << "Judul Paper Target: ";
                cin >> judulPaper;
                q = findElementPaper(L, judulPaper);

                if (q == nullptr) {
                    cout << "[Error] Paper tidak ditemukan." << endl;
                } else {
                    printKeywords(q->firstKeyword);
                    cout << "Hapus keyword SETELAH keyword apa (Predecessor)? ";
                    cin >> namaKeyword;

                    prec = findElementKeyword(q->firstKeyword, namaKeyword);
                    if (prec == nullptr) {
                        cout << "[Gagal] Keyword Predecessor tidak ditemukan." << endl;
                    } else if (prec->next == nullptr) {
                        cout << "[Gagal] Tidak ada keyword setelah '" << namaKeyword << "'." << endl;
                    } else {
                        deleteAfterKeyword(prec, key);
                        if (key != nullptr) {
                            cout << "[Sukses] Keyword '" << key->info.namaKeyword << "' berhasil dihapus." << endl;
                            delete key;
                            cout << "\n[List Keyword Terbaru]" << endl;
                            printKeywords(q->firstKeyword);
                        }
                    }
                }

                cout << "\nTekan ENTER untuk kembali...";
                cin.ignore();
                cin.get();
                break;

            case 5:
                cout << "Judul Paper Target: ";
                cin >> judulPaper;
                q = findElementPaper(L, judulPaper);

                if (q == nullptr) {
                    cout << "[Error] Paper tidak ditemukan." << endl;
                } else {
                    cout << "Nama Keyword yang dicari: ";
                    cin >> namaKeyword;

                    key = findElementKeyword(q->firstKeyword, namaKeyword);
                    if (key != nullptr) {
                        cout << "\n[Ditemukan!]" << endl;
                        cout << "Keyword  : " << key->info.namaKeyword << endl;
                        cout << "Kategori : " << key->info.kategori << endl;
                        cout << "Relevansi: " << key->info.relevansi << endl;
                    } else {
                        cout << "[Info] Keyword tidak ditemukan di paper ini." << endl;
                    }
                }

                cout << "\nTekan ENTER untuk kembali...";
                cin.ignore();
                cin.get();
                break;

            case 6:
                cout << "Judul Paper Target: ";
                cin >> judulPaper;
                q = findElementPaper(L, judulPaper);

                if (q == nullptr) {
                    cout << "[Error] Paper tidak ditemukan." << endl;
                } else {
                    cout << "\n=== Daftar Keyword pada Paper: " << q->info.judul << " ===" << endl;
                    printKeywords(q->firstKeyword);
                }

                cout << "\nTekan ENTER untuk kembali...";
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

