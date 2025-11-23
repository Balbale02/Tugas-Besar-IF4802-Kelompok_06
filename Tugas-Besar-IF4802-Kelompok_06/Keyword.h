#ifndef KEYWORD_H
#define KEYWORD_H

#include <iostream>
#include <string>
using namespace std;

struct NodeKeyword {
    string namaKeyword;
    string kategori;         // Contoh: "Topik Utama", "Metode", "Tools"

    NodeKeyword *nextKeyword;
};
//pancingan
    NodeKeyword *createKeywordNode(string nama, string kat);

#endif
