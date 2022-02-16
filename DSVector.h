//
// Created by leila on 2/14/2022.
//

#ifndef INC_21F_PA02_DSVECTOR_H
#define INC_21F_PA02_DSVECTOR_H

template <class T>
class DSVector{
private:
    T* data;
    int size = 0;
    int capacity;
    void resize();

public:
    DSVector();
    ~DSVector();
    DSVector& operator=(const DSVector&);
    T& push_back(T);
    T& at(const int);
    T& operator[](const int);
    int getSize();
    int getCapacity();
};

template <class T>
DSVector<T>::DSVector(){
    capacity = 10;
    size = 0;
    data = new T[capacity];
}

template <class T>
DSVector<T>::~DSVector(){
    delete[] data;
}

template <class T>
DSVector<T>& DSVector<T>::operator=(const DSVector& temp){
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

template <class T>
void DSVector<T>::resize() {
    T* temp = new T[capacity*2];
    for(int i = 0; i < capacity; i++){
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity *= 2;
}

template <class T>
T& DSVector<T>::push_back(T value){
    if(size == capacity) {
        resize();
    }
    data[size] = value;
    size++;
    return data[size-1];
}

template<class T>
T& DSVector<T>::at(const int index){
    if(index >= size){
        throw std::out_of_range("Index is out of range!");
    }
    return data[index];
}

template<class T>
T& DSVector<T>::operator[](const int index){
    return data[index];
}

template<class T>
int DSVector<T>::getSize(){
    return size;
}

template<class T>
int DSVector<T>::getCapacity(){
    return capacity;
}

#endif //INC_21F_PA02_DSVECTOR_H