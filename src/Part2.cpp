#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Struct untuk menyimpan informasi buku
struct Book {
    string title;
    string description;
    string author;
    string publisher;
    string publish_year;
    string isbn;
};

// Algoritma Bubble Sort untuk menyortir array berdasarkan judul buku
void bubbleSort(vector<Book>& books) {
    int n = books.size();
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (books[j].title > books[j+1].title) {
                swap(books[j], books[j+1]);
            }
        }
    }
}

// Fungsi Linear Search untuk mencari buku berdasarkan kata kunci pada judul buku
vector<Book> linearSearch(const vector<Book>& books, const string& keyword) {
    vector<Book> foundBooks;
    for (const auto& book : books) {
        if (book.title.find(keyword) != string::npos) {
            foundBooks.push_back(book);
        }
    }
    return foundBooks;
}

// Fungsi untuk menampilkan daftar buku
void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "Buku tidak ditemukan." << endl;
        return;
    }
    cout << "Daftar Buku:" << endl;
    for (const auto& book : books) {
        cout << "Judul: " << book.title << endl;
        cout << "Deskripsi: " << book.description << endl;
        cout << "Penulis: " << book.author << endl;
        cout << "Penerbit: " << book.publisher << endl;
        cout << "Tahun Terbit: " << book.publish_year << endl;
        cout << "ISBN: " << book.isbn << endl;
        cout << "======================" << endl;
    }
}

int main() {
    // Inisialisasi array buku
    vector<Book> books = {
        {"BJ Habibie, The Power Of Ideas",
         "“Untuk menjadi manusia jenius. Jagalah kemampuan otak dengan banyak minum air. Saya banyak minum air.”",
         "A. Makmur Makka",
         "Republika Penerbit",
         "14 Oktober 2018",
         "9786025734311"},
        {"Why? People - Albert Einstein",
         "“Orang yang tidak pernah berbuat salah adalah orang yang tidak pernah melakukan sesuatu.” (Albert Einstein)",
         "JYearimdang",
         "Elex Media Komputindo",
         "31 Juli 2016",
         "9786020290959"},
        {"Stephen Hawking Kiamat 100 Tahun Lagi?",
         "Stephen Hawking merupakan fisikawan teoritis brilian. Ia merupakan seorang fisikawan teoretis, kosmolog, penulis, dan Direktur Riset di Pusat Kosmologi Teoretis di Universitas Cambridge lubang hitam memancarkan radiasi, yang dikenal dengan radiasi Hawking.",
         "Nina Artant Artanti",
         "Gerrmedia Pressindo",
         "20 November 2017",
         "9789799116192"},
    };

    // Menggunakan algoritma Bubble Sort untuk menyortir array buku berdasarkan judul buku
    bubbleSort(books);

    // Looping utama
    while (true) {
        cout << "Masukkan kata kunci pencarian (atau ketik 'exit' untuk keluar): ";
        string keyword;
        getline(cin, keyword);

        // Keluar dari program jika pengguna memasukkan 'exit'
        if (keyword == "exit") {
            break;
        }

        // Mencari buku berdasarkan kata kunci menggunakan Linear Search
        vector<Book> foundBooks = linearSearch(books, keyword);

        // Menampilkan hasil pencarian
        displayBooks(foundBooks);
    }
    return 0;
}


