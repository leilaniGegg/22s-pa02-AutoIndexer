//
// Created by leila on 2/14/2022.
//

#ifndef INC_21F_PA02_DSVECTOR_H
#define INC_21F_PA02_DSVECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class DSVector{
private:
    T* data;
    long size = 0;
    long capacity;
    int itr = 0;
    void resize();

public:
    ///--------------------------
    /// CONSTRUCTOR AND RULE OF 3
    ///--------------------------
    DSVector();
    DSVector(const DSVector&);
    ~DSVector();
    DSVector& operator=(const DSVector<T>&);

    ///----------
    /// MODIFIERS
    ///----------
    T& push_back(T);
    T& insert(T, int);
    DSVector& removeIndex(const int);
    DSVector& sort();

    ///----------
    /// ACCESSORS
    ///----------
    int find(const T&);
    T& at(const int)const;
    T& operator[](const int);

    ///---------------------------
    /// ITERATOR OR BOOL FUNCTIONS
    ///---------------------------
    T& begin();
    T& end();
    bool hasNext();
    T& getNext();
    bool isEmpty();

    ///----------------------------
    /// GETTERS AND PRINT FUNCTIONS
    ///----------------------------
    long getSize()const;
    long getCapacity()const;
    void displayNewLine()const;
    void displayComma()const;
};

template <typename T>
DSVector<T>::DSVector(){
    capacity = 10;
    size = 0;
    data = new T[capacity];
}

template <typename T>
DSVector<T>::DSVector(const DSVector& temp){
    capacity = temp.capacity;
    size = temp.size;
    data = new int[capacity];
    for(int i = 0; i < size; i++){
        data[i] = temp.data[i];
    }
}

template <typename T>
DSVector<T>::~DSVector(){
    delete[] data;
}

template <typename T>
DSVector<T>& DSVector<T>::operator=(const DSVector<T>& temp){
        if(&temp != this){
            delete[] data;
            capacity = temp.capacity;
            size = temp.size;
            data = new T[capacity];
            for(int i = 0; i < size; i++){
                data[i] = temp.data[i];
            }
        }
        return *this; // I think
}



template <typename T>
T& DSVector<T>::push_back(T value){
    if(size == capacity) {
        resize();
    }
    data[size] = value;
    ++size;
    return data[size-1];
}

template <typename T>
T& DSVector<T>::insert(T value, int index){
    T* temp = new T[++size];
    if(size == capacity){
        resize();
    }
    for(int i = 0; i < index; i++){
        temp[i] = data[i];
    }
    temp[index] = value;
    for(int i = index+1; i < size; i++){
        temp[i] = data[i-1];
    }
    delete[] data;
    data = temp;
    return data[index];
}

template<typename T>
DSVector<T>& DSVector<T>::removeIndex(const int index){
    T* temp = new T[capacity];
    for(int i = 0; i < index;i++){
        temp[i] = data[i];
    }
    int dataIndex, tempIndex;
    //might be able to get rid of tempIndex condition
    for(tempIndex = index, dataIndex = index + 1;
        tempIndex < size && dataIndex < size; tempIndex++, dataIndex++){
        temp[tempIndex] = data[dataIndex];
    }
    delete[] data;
    data = temp;
    return *this;
}

template<typename T>
DSVector<T>& DSVector<T>::sort(){
    //Insertion Sort
    int j;
    T temp;
    for(int i = 1; i < this->getSize(); i++){
        j = i;
        while(data[j] < data[j-1] && j > 0){
            temp = data[j];
            data[j] = data[j-1];
            data[j-1] = temp;
            --j;
        }
    }
    return *this;
}



template<typename T>
int DSVector<T>::find(const T& temp){
    for(int i = 0; i < size; i++) {
        if (data[i] == temp) {
            return i;
        }
    }
    return -1;
}

template<typename T>
T& DSVector<T>::at(const int index)const{
    if(index >= size){
        throw std::out_of_range("Index is out of range!");
    }
    return data[index];
}

template<typename T>
T& DSVector<T>::operator[](const int index){
    return data[index];
}



template<typename T>
T& DSVector<T>::begin(){
    itr = 0;
    return *data[itr];
}

template<typename T>
T& DSVector<T>::end(){
    itr = size - 1;
    return data[itr];
}

template<typename T>
bool DSVector<T>::hasNext(){
    return itr+1 < size;
}

template<typename T>
T& DSVector<T>::getNext(){
    return data[++itr];
}

template<typename T>
bool DSVector<T>::isEmpty(){
    return (size == 0);
}



template<typename T>
long DSVector<T>::getSize()const{
    return size;
}

template<typename T>
long DSVector<T>::getCapacity()const{
    return capacity;
}

template<class T>
void DSVector<T>::displayNewLine()const{
    for(int i = 1; i < size; i++){
        cout << data[i] << endl;
    }
}

template<class T>
void DSVector<T>::displayComma()const{
    cout << data[0];
    for(int i = 1; i < size; i++){
        cout << ", " << data[i];
    }
}

///----------------
/// PRIVATE FUNCTION
/// ---------------
template <typename T>
void DSVector<T>::resize() {
    T* temp = new T[capacity*2];
    for(int i = 0; i < capacity; i++){
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity *= 2;
}

#endif //INC_21F_PA02_DSVECTOR_H