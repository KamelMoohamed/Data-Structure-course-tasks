#include "MyArray.h"
#include <iostream>


template<class T>
MyArray<T>::MyArray()
{
    data = new T[capacity];
}


template<class T>
MyArray<T>::MyArray(T arr[], int size)
{
    if(size > capacity){
        expandArray();
    }
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = arr[i];
    }
    this->size = size;
}


template <class T>
void MyArray<T>::push(T element) {
    if (needsExpansion()) expandArray();
    data[size++] = element;
}


template <class T>
T MyArray<T> ::get(int index) {
    if (!isValidIndex(index)) return 0;
    return data[index];
}


template <class T>
void MyArray<T> ::insert(int index, T d) {
    if (needsExpansion()) expandArray();
    //accept index at size
    if (!(index >= 0 && index <= size)) return;
    //move all obj's at >= index up 1
    for (int i = size - 1; i >= 0; i--) {
        if (i >= index) {
            data[i + 1] = data[i];
        }
    }
    data[index] = d;
    size++;
}


template <class T>
T MyArray<T> ::pop() {
    if (isEmpty())
        return -1;
    T x = data[--size];
    if (needShrunking()) {
        shrunkArray();
    }
    return x;
}


//removes the element at the given index
template <class T>
T MyArray<T> ::remove(int index) {
    if (!isValidIndex(index)) return -1;

    T x = data[index];
    //shift elements down
    for (int i = index + 1; i < size; i++) {
        data[i - 1] = data[i];
    }
    //remove last element
    size--;
    if (needShrunking()) {
        shrunkArray();
    }
    return x;
}

template <class T>
int MyArray<T> ::get_size() {
    return size;
}


template <class T>
int MyArray<T> ::get_capacity() {
    return capacity;
}


template <class T>
void MyArray<T> ::print() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
}




template<class T>
bool MyArray<T> ::needsExpansion() {
    return size >= capacity;
}


template<class T>
void MyArray<T> ::expandArray() {
    capacity *= 2;
    T* newData = new T[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[]data;
    data = newData;
}


template<class T>
bool MyArray<T> ::needShrunking() {
    return size == capacity/4;
}


template<class T>
void MyArray<T> ::shrunkArray() {
    capacity *= 0.5;
    T* newData = new T[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[]data;
    data = newData;
}


template<class T>
bool MyArray<T>::isValidIndex(int index) {
    return index >= 0 && index < size;
}


template <class T>
bool MyArray<T> ::isEmpty() {
    return size == 0;
}