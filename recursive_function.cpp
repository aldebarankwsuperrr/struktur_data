#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int multiplication(int a, int b){
    if (b > 0){
        return a + multiplication(a, b-1);
    } else {
        return 0;
    }
}

int multiplication_2(int a, int b){
    int result  = 0;
    while (b-- > 0){
        result += a;
    }

    return result;
}

int main(){
    int a = 1000000;
    int b = 1000;


    auto t1 = chrono::high_resolution_clock::now();
    int result = multiplication(a, b);
    auto t2 = chrono::high_resolution_clock::now();

    auto t3 = chrono::high_resolution_clock::now();
    int result_2 = multiplication_2(a, b);
    auto t4 = chrono::high_resolution_clock::now();

    
    cout << result/(a*b)<< endl;
    chrono::duration<double, std::milli> ms_double = t2-t1;
    chrono::duration<double, std::milli> ms_double_2 = t4-t3;
    cout << "time recursion : "<< ms_double.count() << endl;
    cout << "time non-recursion : " << ms_double_2.count() << endl;
    return 0;
}