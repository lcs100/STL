#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class GreaterFive {
    public:
        bool operator()(int val){
            return val > 5;
        }
};

void test01(){
    vector<int> v;

    for(int i=0;i<10;i++){
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if( it == v.end()){
        cout << "not found" << endl;
    }
    else cout << "found" << endl;
}

class myCompare {
    public:
        bool operator()(int v1, int v2){
            return v1 > v2;
        }
};

void test02(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    sort(v.begin(), v.end(), myCompare());
}

int main(){
    //test01();

    test02();

    return 0;
}