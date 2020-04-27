#include <iostream>
#include "Vector.h"
#include "Functional.h"

using namespace std;

class compare: public binary_function<int, int, bool> {
    public:
        bool operator()(int i, int num) const {
            return i > num;
        }
};

class comparetonum: public unary_function<int, bool> {
    public:
        bool operator()(int i) const {
            return i > 5;
        }
};

void print(int i, int j){
    if(i > j){
        cout << i << " ";
    }
}

int main(){
    mySTL::vector<int> vec;

    for(int i=0;i<10;i++){
        vec.push_back(i);
    }

    mySTL::vector<int>::iterator it = find_if(vec.begin(), vec.end(), bind2nd(compare(), 6));
    if(it == vec.end()){
        cout << "cannot find the number!" << endl;
    }
    else {
        cout << "find num: " << *it << endl;
    }

    mySTL::vector<int> vec1;
    for(int i=0;i<10;i++){
        vec1.push_back(i);
    }

    cout << "The num larger than 5: ";
    mySTL::for_each(vec1.begin(), vec1.end(), bind2nd(ptr_fun(print),5));
    cout << endl;

    return 0;
}