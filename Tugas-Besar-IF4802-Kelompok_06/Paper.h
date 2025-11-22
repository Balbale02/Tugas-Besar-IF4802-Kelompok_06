#ifndef PAPER_H
#define PAPER_H

#include "Keyword.h"
using namespace std;

struct NodePaper {
    string judul;
    string penerbit;
    string doi;

    NodePaper* nextPaper;      // Ke samping
    NodeKeyword* headKeyword;  // Ke bawah
};

//pancingan
void createPaper(NodePaper* &head, string judul, string penerbit, string doi);
NodePaper* findPaper(NodePaper* head, string judulCari);
void addKeywordToPaper(NodePaper* head, string judulPaper, string namaKey, string katKey);
void showAllPapers(NodePaper* head);

#endif
