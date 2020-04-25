#include <iostream>
using namespace std;
#include "myArray.hpp"

void test01(){
    myArray<int> arr1(5);
    
    cout << arr1[0] << endl;
}

int main(){
    test01();

    return 0;
}