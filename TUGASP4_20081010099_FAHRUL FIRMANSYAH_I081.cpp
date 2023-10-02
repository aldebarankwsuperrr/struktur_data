// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct Mahasiswa{
  string nama, npm;  
  int usia;
  Mahasiswa* next;
};
Mahasiswa *head, *tail, *cur;

void print(){
    Mahasiswa *pos = new Mahasiswa();
    pos = head;
    while(pos != NULL){
        cout << "nama: " << pos->nama << endl;
        cout << "npm: " << pos->npm << endl;
        cout << "usia: " << pos->usia << endl;
        cout << endl;
        pos = pos->next;
    }
}

void createSSL(string nama, string npm, int usia){
    head = new Mahasiswa();
    head->nama = nama;
    head->npm = npm;
    head->usia = usia;
    head->next = NULL;
    cur = head;
    tail = head;
}

void addLast(string nama, string npm, int usia){
    if (head == NULL){
        createSSL(nama, npm, usia);
    }
    else{
        Mahasiswa* newMahasiswa = new Mahasiswa();
        newMahasiswa->nama = nama;
        newMahasiswa->npm = npm;
        newMahasiswa->usia = usia;
        newMahasiswa->next = NULL;
        cur->next = newMahasiswa;
        cur = newMahasiswa;
        tail = newMahasiswa;
    }
}


void addFirst(string nama, string npm, int usia){
    if (head == NULL){
        createSSL(nama, npm, usia);
    }
    else{
        Mahasiswa* newMahasiswa = new Mahasiswa();
        newMahasiswa->nama = nama;
        newMahasiswa->npm = npm;
        newMahasiswa->usia = usia;
        newMahasiswa->next = head;
        head = newMahasiswa;
    }
}

void changeFirst(string nama, string npm, int usia){
    head->nama = nama;
    head->npm = npm;
    head->usia = usia;
}

void changeLast(string nama, string npm, int usia){
    tail->nama = nama;
    tail->npm = npm;
    tail->usia = usia;
}

void deleteFirst(){
    Mahasiswa* del = head;
    head = head->next;
    delete del;
}

void deleteLast(){
    Mahasiswa *pos = head;
    Mahasiswa* del = tail;
    while(pos->next != tail){
        pos = pos->next;
    }
    pos->next = NULL;
    tail = pos;
    delete del;
}

int main() {
    // Write C++ code here
    addFirst("Fahrul", "20081010099", 17);
    addFirst("budi", "20081010098", 18);
    addLast("beni", "20081010097", 19);
    changeLast("beni", "20081010087", 10);
    changeFirst("budi", "2008101007", 100);
    // deleteFirst();
    deleteLast();
    print();
    
    
    return 0;
}