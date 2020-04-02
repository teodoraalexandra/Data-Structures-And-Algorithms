//
// Created by Teodora Dan on 2019-05-21.
//

#include "DynamicVector.h"
#include <iostream>
#include <cstring>
using namespace std;

DynamicVector::DynamicVector(int cap)
{
    this->size = 0;
    this->capacity = cap;

    this->elems = new TElem_vector[this->capacity];
}

DynamicVector::DynamicVector(const DynamicVector & v)
{
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new TElem_vector[this->capacity];

    for (int i = 0; i < v.size; i++)
        this->elems[i] = v.elems[i];
}

int DynamicVector::getSize() {
    return this->size;
}

DynamicVector & DynamicVector::operator=(const DynamicVector & v)
{
    if (this == &v)
        return *this;

    this->capacity = v.capacity;
    this->size = v.size;

    delete[] this->elems;

    this->elems = new TElem_vector[this->capacity];
    for (int i = 0; i < v.size; i++)
        this->elems[i] = v.elems[i];

    return *this;
}


DynamicVector::~DynamicVector()
{
    delete[] this->elems;
}

void DynamicVector::add(const TElem_vector & e)
{
    // !!! resize
    if (this->size == this->capacity)
        this->resize();
    this->elems[this->size++] = e;
}

void DynamicVector::resize(double factor)
{
    this->capacity *= factor;

    TElem_vector* els = new TElem_vector[this->capacity];
    for (int i = 0; i < this->size; i++)
        els[i]=this->elems[i];

    delete[] this->elems;
    elems = els;
}


void DynamicVector::remove(int position) {
    for (int i = position; i < this->size - 1; i++)
        this->elems[i] = this->elems[i + 1];

    this->size--;
}

int DynamicVector::getElement(int position) {
    return this->elems[position];
}

TElem_vector & DynamicVector::operator[](int pos) const
{
    return this->elems[pos];
}