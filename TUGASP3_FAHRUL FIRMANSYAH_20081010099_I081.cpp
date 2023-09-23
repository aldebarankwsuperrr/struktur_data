// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

struct mata_kuliah{
    string nama;
    string dosen_pengampu;
    int bobot;
};

struct mahasiswa{
  string nama;
  string npm;
  mata_kuliah on_going[4];
};

void print_data_mahasiswa(mahasiswa data){
    cout << "================================" << endl;
    cout << "Nama\t: " << data.nama << endl;
    cout << "Npm\t\t: " << data.npm << endl;
    cout << "Mata Kuliah : " << endl;
    int total_sks = 0;
    for (mata_kuliah matkul : data.on_going){
        if (matkul.nama == ""){
            break;
        }
        cout << "- " << matkul.nama << endl;
        total_sks += matkul.bobot;
    }
    cout << "Total SKS : " << total_sks << endl;
}


int main() {
    // Write C++ code here
    mata_kuliah daftar_mata_kuliah[4] = {
        {"struktur data", "decker", 1},
        {"pengolahan citra digital", "jonathan", 2},
        {"riset informatika", "robert", 3},
        {"pengenalan pola", "chris", 4},
    };
    
    
    mahasiswa fahrul = {
        "fahrul firmansyah",
        "2223",
        {daftar_mata_kuliah[0], daftar_mata_kuliah[3]}
    };
    
    mahasiswa putra = {
        "putra dwi wira",
        "2224",
        {daftar_mata_kuliah[0], daftar_mata_kuliah[1],daftar_mata_kuliah[2], daftar_mata_kuliah[3]}
    };
    
    
    print_data_mahasiswa(fahrul);
    cout << endl;
    print_data_mahasiswa(putra);
    
    

    return 0;
}