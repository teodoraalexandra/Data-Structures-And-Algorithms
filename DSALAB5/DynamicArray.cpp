//
// Created by Teodora Dan on 2019-05-09.
//

#include "DynamicArray.h"


DynamicArray::DynamicArray(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->elems = new TElem[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& v)
{
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];
}

DynamicArray::~DynamicArray()
{
    delete[] this->elems;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& v)
{
    if (this == &v)
        return *this;

    this->size = v.size;
    this->capacity = v.capacity;

    delete[] this->elems;
    this->elems = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];

    return *this;
}

void DynamicArray::removeLast()
{
    this->size -= 1;
}


void DynamicArray::add(TElem e)
{
    if (this->size == this->capacity)
        this->resize();
    this->elems[this->size] = e;
    this->size++;
}

void DynamicArray::resize(double factor)
{
    this->capacity *= factor;

    TElem* els = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++)
        els[i]=this->elems[i];

    delete[] this->elems;
    elems = els;
}

TElem & DynamicArray::operator[](int pos) const
{
    return this->elems[pos];
}

int DynamicArray::getSize() const
{
    return this->size;
}