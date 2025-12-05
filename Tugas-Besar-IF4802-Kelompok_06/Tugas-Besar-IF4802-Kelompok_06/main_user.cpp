#include "main_user.h"
#include "Paper.h"

void menuUser(){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "===========================Menu=============================  " << endl;
        cout << "|| 1. studi case 1                                         ||" << endl;
        cout << "|| 2. studi case 2                                         ||" << endl;
        cout << "|| 3. studi case 3                                         ||" << endl;
        cout << "|| 4. studi case 4                                         ||" << endl;
        cout << "|| 5. studi case 5                                         ||" << endl;
        cout << "|| 6. studi case 6                                         ||" << endl;
        cout << "|| 7. studi case 7                                         ||" << endl;
        cout << "|| 8. studi case 8                                         ||" << endl;
        cout << "|| 9. studi case 9                                         ||" << endl;
        cout << "|| 0. back                                                 ||" << endl;
        cout << "============================================================ " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
               cout << "you choose option 1" << endl;
               // kode
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
