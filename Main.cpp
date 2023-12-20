#include <iostream>
using namespace std;

// deklarasi class Buku
class Buku {
public:
    // method
    string judul, pengarang;
    int tahunTerbit;
    Buku* next;

    // constructor untuk inisialisasi node
    Buku(string j, string p, int tahun) : judul(j), pengarang(p), tahunTerbit(tahun), next(nullptr) {}
};

// deklarasi class LinkedList
class LinkedList {
public:
    Buku* head;
    Buku* tail;
    Buku* cur;
    Buku* newNode;
    Buku* del;

    // constructor untuk inisialisasi linked list
    LinkedList() : head(nullptr), tail(nullptr), cur(nullptr), newNode(nullptr), del(nullptr) {}

    // method untuk membuat single linked list
    void createSingleLinkedList(string judul, string pengarang, int tB) {
        head = new Buku(judul, pengarang, tB);
        tail = head;
    }

    // method untuk menambah node di awal linked list
    void addFirst(string judul, string pengarang, int tB) {
        newNode = new Buku(judul, pengarang, tB);
        newNode->next = head;
        head = newNode;
    }

    // method untuk menambah node di akhir linked list
    void addLast(string judul, string pengarang, int tB) {
        newNode = new Buku(judul, pengarang, tB);
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }

    // method untuk menghapus node di awal linked list
    void removeFirst() {
        del = head;
        head = head->next;
        delete del;
    }

    // method untuk menghapus node di akhir linked list
    void removeLast() {
        del = tail;
        cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = nullptr;
        delete del;
    }

    // method untuk mengubah node di awal linked list
    void changeFirst(string judul, string pengarang, int tB) {
        head->judul = judul;
        head->pengarang = pengarang;
        head->tahunTerbit = tB;
    }

    // method untuk mengubah node di akhir linked list
    void changeLast(string judul, string pengarang, int tB) {
        tail->judul = judul;
        tail->pengarang = pengarang;
        tail->tahunTerbit = tB;
    }

    // method untuk mencetak linked list
    void printSingleLinkedList() {
        cur = head;
        while (cur != nullptr) {
            cout << "Judul Buku : " << cur->judul << endl;
            cout << "Pengarang Buku : " << cur->pengarang << endl;
            cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl << endl;
            cur = cur->next;
        }
    }
};

int main() {
    // inisialisasi linked list
    LinkedList linkedList;

    // buat linked list
    linkedList.createSingleLinkedList("Kata", "Gezz & Aan", 2018);

    // cetak linked list
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    // tambahkan node di awal linked list
    linkedList.addFirst("Dia adalah Kakakku", "Tere Liye", 2009);

    // cetak linked list
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    // tambahkan node di akhir linked list
    linkedList.addLast("Aroma Karsa", "Dee Lestari", 2018);

    // cetak linked list
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    // hapus node di awal linked list
    linkedList.removeFirst();

    // cetak linked list
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    // tambahkan node di akhir linked list
    linkedList.addLast("11.11", "Fiera Basari", 2018);

    // cetak linked list
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    // hapus node di akhir linked list
    linkedList.removeLast();

    // cetak linked list
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    // ubah node di awal linked list
    linkedList.changeFirst("Berhenti di Kamu", "Gia Pratama", 2018);

    // cetak linked list
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    linkedList.addFirst("Pusing", "Hafida Ningrum", 2003);

    // cetak linked list
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    return 0;
}
