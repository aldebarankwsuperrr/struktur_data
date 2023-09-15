// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
double power(double nilai, int pangkat){
    if (pangkat == 0){
        return 1;
    }
    return (pangkat < 0)  ? 1 / power(nilai, -pangkat) : nilai * power(nilai, pangkat-1);
    
}

double power_2(double nilai, int pangkat, int temp=1){
    if (pangkat == 0){
        return 1;
    }
    if (pangkat < 0){
        return 1 / power_2(nilai, -pangkat, temp);
    }
    (pangkat & 1) ? temp *= nilai : nilai *= nilai;
 
    return temp * power_2(nilai, pangkat/2, temp);
    // return temp;
}

int main(){
    // Write C++ code here
    double x = 2;
    int n = -2;
    double hasil = power(x, n);
    double hasil_2 = power_2(x, n);
    cout << "x : " << x << endl;
    cout << "n : " << n << endl;
    cout << "===========================" << endl;
    cout << "Power 1" << endl;
    cout << "Maka x^n : " << hasil << endl;
    
    cout << "===========================" << endl;
    cout << "Power 2" << endl;
    cout << "Maka x^n : " << hasil_2 << endl;

    

    return 0;
}