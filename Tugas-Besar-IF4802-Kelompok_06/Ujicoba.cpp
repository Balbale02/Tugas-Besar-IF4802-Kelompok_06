#include <iostream>
#include <string>
#include <cstdlib> // Untuk rand() dan srand()
#include <ctime>   // Untuk time()

using namespace std;

int main() {
    // --- 1. PERSIAPAN ---
    const int UKURAN_POPULASI = 10;
    const int JUMLAH_HAPUS = UKURAN_POPULASI / 2; // Yaitu 5

    // Inisialisasi populasi (Perumpamaan)
    string populasi[UKURAN_POPULASI] = {
        "Andi", "Bela", "Citra", "Doni", "Eka",
        "Fajar", "Gina", "Heri", "Indah", "Joni"
    };

    // Array penanda untuk melacak siapa yang sudah terpilih (awalnya semua false)
    bool sudahTerhapus[UKURAN_POPULASI] = {false};

    // Variabel untuk menghitung berapa banyak yang sudah kita hapus
    int jumlahSudahTerhapus = 0;

    // "Kocok" bibit acak berdasarkan waktu saat ini
    // Ini penting agar hasil undian berbeda setiap kali program dijalankan
    srand(time(0));

    cout << "--- PROSES UNDIAN DIMULAI (Menghapus " << JUMLAH_HAPUS << " dari " << UKURAN_POPULASI << " orang) ---" << endl;

    // --- 2. ALGORITMA UNDIAN (Looping) ---
    // Kita akan terus mengulang undian sampai kita mendapatkan 5 orang unik
    while (jumlahSudahTerhapus < JUMLAH_HAPUS) {

        // Dapatkan nomor undian acak (indeks dari 0 sampai 9)
        int undian = rand() % UKURAN_POPULASI; // (Hasilnya antara 0 dan 9)

        // Cek: Apakah orang di nomor undian ini SUDAH terhapus?
        if (sudahTerhapus[undian] == false) {
            // Jika BELUM, maka undian ini SAH.

            // 1. Tandai dia sebagai "sudah terhapus"
            sudahTerhapus[undian] = true;

            // 2. Tambahkan hitungan
            jumlahSudahTerhapus++;

            // 3. Beri laporan
            cout << "Undian ke-" << jumlahSudahTerhapus << ": Nomor " << undian
                 << " (" << populasi[undian] << ") terpilih untuk dihapus." << endl;

        } else {
            // Jika SUDAH terhapus (sudahTerhapus[undian] == true)
            // Kita tidak melakukan apa-apa. Loop 'while' akan berputar lagi
            // untuk mencari nomor undian baru (mengocok ulang).
            cout << "(Mengulang undian: Nomor " << undian << " sudah terpilih sebelumnya...)" << endl;
        }
    }

    // --- 3. LAPORAN AKHIR ---
    cout << "\n--- HASIL AKHIR UNDIAN ---" << endl;

    cout << "Daftar Dihapus:" << endl;
    for (int i = 0; i < UKURAN_POPULASI; i++) {
        if (sudahTerhapus[i] == true) {
            cout << "- " << populasi[i] << endl;
        }
    }

    cout << "\nDaftar Tersisa:" << endl;
    for (int i = 0; i < UKURAN_POPULASI; i++) {
        if (sudahTerhapus[i] == false) {
            cout << "- " << populasi[i] << endl;
        }
    }

    return 0;
}
