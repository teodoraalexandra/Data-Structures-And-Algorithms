//
// Created by Teodora Dan on 2019-04-03.
//

#ifndef SDA_LAB1_DYNAMICARRAY_H
#define SDA_LAB1_DYNAMICARRAY_H

#endif //SDA_LAB1_DYNAMICARRAY_H

#pragma once
#include <iostream>

typedef int TElem;

class DynamicArray
{
private:
    TElem* elems;
    int size;
    int capacity;

public:
    // default constructor for a DynamicArray
    DynamicArray(int capacity = 10);

    // copy constructor for a DynamicArray
    DynamicArray(const DynamicArray& v);
    ~DynamicArray();

    // assignment operator for a DynamicArray
    DynamicArray& operator=(const DynamicArray& v);

    // Adds an element to the current DynamicArray.
    void add(TElem e);

    //Remove the last element
    void removeLast();

    /*
    Overloading the subscript operator
    Input: pos - a valid position within the array.
    Output: a reference to the element o position pos.
    */
    TElem& operator[](int pos) const;

    int getSize() const;

private:
    // Resizes the current DynamicArray, multiplying its capacity by a given factor (real number).
    void resize(double factor = 2);
};

