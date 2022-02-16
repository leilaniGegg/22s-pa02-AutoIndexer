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

#endif //INC_21F_PA02_DSVECTOR_H