//
// Created by Teodora Dan on 2019-05-09.
//

#ifndef DSALAB5_DYNAMICARRAY_H
#define DSALAB5_DYNAMICARRAY_H

#endif //DSALAB5_DYNAMICARRAY_H

#include <iostream>
#pragma once

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

