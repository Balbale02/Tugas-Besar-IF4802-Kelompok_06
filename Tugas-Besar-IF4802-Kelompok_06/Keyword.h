#ifndef KEYWORD_H
#define KEYWORD_H

#include <iostream>
#include <string>
using namespace std;
struct InfotypeKeyword {
    string namaKeyword;  // Contoh: "Machine Learning"
    string kategori;     // Contoh: "Topic", "Method", "Tool"
    int relevansi;       // Skor 0-100 seberapa pas keywordnya
};

typedef struct elementKeyword *addressKeyword;

struct elementKeyword {
    InfotypeKeyword info;
    addressKeyword next;
};

void createElementKeyword(InfotypeKeyword data, addressKeyword &P);                     //Akhtar
void insertFirstKeyword(addressKeyword &first, addressKeyword P);                       //Akhtar
void insertLastKeyword(addressKeyword &first, addressKeyword P);                        //Iqbal
void insertAfterKeyword(addressKeyword &first, addressKeyword P, addressKeyword prec);  //Iqbal

void deleteFirstKeyword(addressKeyword &first, addressKeyword &P);                      //Akhtar
void deleteLastKeyword(addressKeyword &first, addressKeyword &P);                       //Akhtar
void deleteAfterKeyword(addressKeyword prec, addressKeyword &P);                        //Iqbal

addressKeyword findElementKeyword(addressKeyword first, string namaCari);               //Iqbal
void printKeywords(addressKeyword first);                                               //Iqbal

#endif
