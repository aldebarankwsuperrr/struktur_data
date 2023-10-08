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
        cout << "usia: " << pos->usia << endl << endl;
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

int countSingleLinkedList(){
    Mahasiswa *pos = new Mahasiswa();
    pos = head;
    int length = 0;
    while(pos != NULL){
        pos = pos->next;
        length++;
    }
    return length;
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

void addMid(string nama, string npm, int usia, int pos){
    int lengthLinkedList = countSingleLinkedList();
    if(lengthLinkedList == 0 || pos > lengthLinkedList){
        cout << "Posisi diluar jangkauan" << endl;
        return;
    } else if (pos == 1 || pos == lengthLinkedList){
        cout << "Posisi bukan ditengah" << endl;
        return;
    } else {
        Mahasiswa* newMahasiswa = new Mahasiswa();
        newMahasiswa->nama = nama;
        newMahasiswa->npm = npm;
        newMahasiswa->usia = usia;
        
        Mahasiswa* temp = head;
        int nomor = 1;
        while (nomor < pos-1){
            temp = temp->next;
            nomor++;
        }
        newMahasiswa->next = temp->next;
        temp->next = newMahasiswa;
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

void changeMid(string nama, string npm, int usia, int pos=1){
    int lengthLinkedList = countSingleLinkedList();
    if(lengthLinkedList == 0 || pos > lengthLinkedList){
        cout << "Posisi diluar jangkauan" << endl;
        return;
    } else if (pos == 1 || pos == lengthLinkedList){
        cout << "Posisi bukan ditengah" << endl;
        return;
    } else {
        Mahasiswa* temp = head;
        int nomor = 1;
        while(nomor < pos){
            temp = temp->next;
            nomor++;
        }
        temp->nama = nama;
        temp->npm = npm;
        temp->usia = usia;
    }
}

void deleteFirst(){
    Mahasiswa* del = head;
    head = head->next;
    delete del;
}

void deleteMid(int pos){
    int lengthLinkedList = countSingleLinkedList();
    if(lengthLinkedList == 0 || pos > lengthLinkedList){
        cout << "Posisi diluar jangkauan" << endl;
        return;
    } else if (pos == 1 || pos == lengthLinkedList){
        cout << "Posisi bukan ditengah" << endl;
        return;
    } else {
        Mahasiswa* temp = new Mahasiswa();
        Mahasiswa* temp2 = new Mahasiswa();
        temp = head;
        int nomor = 1;
        while(nomor < pos-1){
            temp = temp->next;
            nomor++;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
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
    //  Membuat Linked List
    createSSL("Susilo", "1", 12);
    
    //  Menambah Data Pada Awal Linked List
    addFirst("Fahrul", "2", 13);
    
    //  Menambah Data Pada Akhir Linked List
    addLast("Beni", "3", 14);
    
    //  Menambah Data Pada Tengah Linked List
    addMid("Budi", "4", 15, 2);
    
    //  Mengubah Data Pada Awal Linked List
    changeFirst("Fajrul", "10", 15);
    
    //  Mengubah Data Pada Akhir Linked List
    changeLast("Benu", "9", 15);
    
    //  Mengubah Data Pada Tengah Linked List
    changeMid("Bidi", "2", 29, 2);
    
    //  Menghapus Data Pada Awal Linked List
    deleteFirst();
    
    //  Menghapus Data Pada Tengah Linked List
    deleteMid(2);
    
    //  Menghapus Data Pada Akhir Linked List
    deleteLast();
    print();
    return 0;
}
