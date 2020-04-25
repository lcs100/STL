#pragma once
#include <iostream>
using namespace std;

template<typename T>
class myArray {
    private:
        T* pAddress;//heap part
        int m_capacity;
        int m_size;

    public:
        myArray(int capacity){
            this->m_capacity = capacity;
            this->m_size = 0;
            this->pAddress = new T[this->m_capacity];
        }

        myArray(const myArray& arr){
            this->m_capacity = arr.m_capacity;
            this->m_size = arr.m_size;
            //this->pAddress = arr.pAddress;
            this->pAddress = new T[arr.m_capacity];

            for(int i=0;i < this->m_size; i++){
                this->pAddress[i] = arr.pAddress[i];
            }
        }

        myArray& operator=(const myArray& arr){
            if(this->pAddress != nullptr){
                delete[] this->pAddress;
                this->pAddress = nullptr;
                this->m_capacity = 0;
                this->m_size = 0;
            }

            this->m_capacity = arr.m_capacity;
            this->m_size = arr.m_size;
            this->pAddress = new T[arr.m_capacity];
            for(int i=0;i < this->m_size; i++){
                this->pAddress[i] = arr.pAddress[i];
            }

            return *this;
        }

        void Push_Back(const T& val){
            //assert
            if(this->m_capacity == this->m_size) return ;
            
            this->pAddress[this->m_size] = val;
            this->m_size++;
        }

        void Pop_Back(){
            if(this->m_size == 0) return;

            this->m_size--;
        }

        T& operator[](int index){     //左值
            return this->pAddress[index];
        }

        int getCapacity(){
            return this->m_capacity;
        }

        int getSize(){
            return this->m_size;
        }

        ~myArray(){
            if(this->pAddress != nullptr){
                delete[] this->pAddress;
                this->pAddress = nullptr;
            }
        }
};