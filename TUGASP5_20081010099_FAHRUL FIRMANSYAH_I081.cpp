// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

struct Mahasiswa{
  string nama, npm;
  int usia;
  Mahasiswa *next, *prev;
};
Mahasiswa *head, *tail, *newNode, *del, *afterNode, *cur;

void createDLL(string nama, string npm, int usia){
    head = new Mahasiswa();
    head->nama = nama;
    head->npm = npm;
    head->usia = usia;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

void addFirst(string nama, string npm, int usia){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void addLast(string nama, string npm, int usia){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void addMid(string nama, string npm, int usia, int pos){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    
    int seq = 1;
    cur = head;
    while (seq < pos-1){
        cur = cur->next;
        seq++;
    }
    
    afterNode = cur->next;
    newNode->prev = cur;
    newNode->next = afterNode;
    cur->next = newNode;
    afterNode->prev = newNode;
    
}

void deleteFirst(){
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
}

void deleteLast(){
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

void deleteMiddle(int pos){
    int seq = 1;
    cur = head;
    while (seq < pos-1){
        cur = cur->next;
        seq++;
    }
    del = cur->next;
    afterNode = del->next;
    afterNode->prev = cur;
    cur->next = afterNode;
    delete del;
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


void changeMiddle(string nama, string npm, int usia, int pos){
    cur = head;
    int seq = 1;
    while (seq < pos){
        cur = cur->next;
        seq++;
    }
    cur->nama = nama;
    cur->npm = npm;
    cur->usia = usia;
}

void printDLL(){
    cur = head;
    while(cur != NULL){
        cout << "Nama Mahasiswa : " << cur->nama << endl;
        cout << "Npm Mahasiswa : " << cur->npm << endl;
        cout << "Usia Mahasiswa : " << cur->usia << endl << endl;
        cur = cur->next;
     }
}

int main() {
    createDLL("budi", "1", 17);
    addFirst("beni", "0", 16);
    addLast("benu", "3", 19);
    addMid("bido", "2", 18, 3);
    // deleteFirst();
    // deleteLast();
    // deleteMiddle(2);
    changeFirst("jeni", "0", -16);
    changeLast("jenu", "-3", -19);
    changeMiddle("judi", "-1", -17, 3);
    printDLL();
    
    
    return 0;
}