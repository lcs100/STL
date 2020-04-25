#include <iostream>
#include "Algorithm.h"
#include "Iterator.h"

int main(){
    mySTL::vector<int> vec;
    for(int i=0;i<10;i++)
        vec.push_back(i);

    mySTL::vector<int>::iterator it = vec.begin();
    mySTL::vector<int>::iterator end = vec.end();
    std::cout << "The value of vector:";
    for(;it != vec.end();it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    it = vec.begin();
    std::cout << "After advance 3:";
    mySTL::advance(it, 3);
    std::cout << *it << " " << std::endl;

    std::cout << "The distance of position 3 to th end:";
    std::cout << mySTL::distance(it, end) << std::endl;

    return 0;
}
