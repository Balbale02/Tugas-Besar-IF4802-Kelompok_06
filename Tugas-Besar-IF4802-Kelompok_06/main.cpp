#include <iostream>
#include "Paper.h"
#include "main_admin.h"
#include "main_user.h"

using namespace std;
void initDummyData(ListPaper &L) {
    addressPaper P;
    addressKeyword K;

    InfotypePaper d1 = {"Deep_Learning", "10.1", "Yann_Lecun", "yann@fb", "Facebook_AI", 2015};
    createElementPaper(d1, P); insertLastPaper(L, P);
    InfotypeKeyword k1 = {"CNN", "Machine Learning", 9};
    createElementKeyword(k1, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d2 = {"GTA_VI_Review", "10.2", "Gamer_X", "x@game", "IGN", 2025};
    createElementPaper(d2, P); insertLastPaper(L, P);
    InfotypeKeyword k2 = {"Open_World", "Game", 10};
    createElementKeyword(k2, K); insertLastKeyword(P->firstKeyword, K);

    InfotypePaper d3 = {"React_JS", "10.3", "Facebook", "fb@meta", "Meta", 2013};
    createElementPaper(d3, P); insertLastPaper(L, P);
    InfotypeKeyword k3 = {"Frontend", "Web", 8};
    createElementKeyword(k3, K); insertLastKeyword(P->firstKeyword, K);
}

int main()
{
    ListPaper ListAdmin;
    createListPaper(ListAdmin);

    ListPaper ListUser;
    createListPaper(ListUser);
    initDummyData(ListUser);

    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ MAIN MENU ============" << endl;
        cout << "|| 1. Admin                      ||" << endl;
        cout << "|| 2. User                       ||" << endl;
        cout << "|| 0. Exit                       ||" << endl;
        cout << "===================================" << endl;
        cout << "Pilihan: ";
        cin >> option;

        switch(option) {
            case 1:
                menuAdmin(ListAdmin);
                break;
            case 2:
                menuUser(ListUser);
                break;
            case 0:
                cout << "Keluar program..." << endl;
                break;
            default:
                cout << "Pilihan salah." << endl;
                cin.ignore(); cin.get();
        }
    }
    return 0;
}
