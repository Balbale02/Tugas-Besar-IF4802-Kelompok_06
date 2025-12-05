#ifndef PAPER_H
#define PAPER_H

#include "Keyword.h"
#include <iostream>

using namespace std;

struct InfotypePaper {
    string judul;
    string doi;
    string penulis;
    string email;
    string afiliasi;
    int tahunTerbit;
};

typedef struct elementPaper *addressPaper;

struct elementPaper {
    InfotypePaper info;
    addressPaper next;
    addressPaper prev;
    addressKeyword firstKeyword;
};

struct ListPaper {
    addressPaper first;
    addressPaper last;
};

void createListPaper(ListPaper &L);                                                 //Iqbal
void createElementPaper(InfotypePaper data, addressPaper &P);                       //Iqbal

void insertFirstPaper(ListPaper &L, addressPaper P);                                //Akhtar
void insertLastPaper(ListPaper &L, addressPaper P);                                 //Iqbal
void insertAfterPaper(ListPaper &L, addressPaper prec, addressPaper P);             //Akhtar

void deleteFirstPaper(ListPaper &L, addressPaper &P);                               //Akhtar
void deleteLastPaper(ListPaper &L, addressPaper &P);                                //Iqbal
void deleteAfterPaper(ListPaper &L, addressPaper prec, addressPaper &P);            //Akhtar

addressPaper findElementPaper(ListPaper L, string judulCari);                       //Iqbal
void printAllData(ListPaper L);                                                     //Akhtar
void printPaper(ListPaper L);                                                       //Akhtar
void addKeywordToPaper(ListPaper &L, string judulPaper, InfotypeKeyword dataKey);   //Iqbal
void deleteKeywordFromPaper(ListPaper &L, string judulPaper, string namaKey);       //Iqbal

bool isPaperEmpty(ListPaper &L); // Akhtar

#endif


