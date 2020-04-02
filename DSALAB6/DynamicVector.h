//
// Created by Teodora Dan on 2019-05-21.
//

#ifndef DSALAB6_DYNAMICVECTOR_H
#define DSALAB6_DYNAMICVECTOR_H

#pragma once

typedef int TElem_vector;

class DynamicVector
{
private:
    int size, capacity;
    TElem_vector * elems;
    void resize(double factor = 2);

public:
    DynamicVector(int cap = 10);
    DynamicVector(const DynamicVector& v);
    DynamicVector& operator=(const DynamicVector& v);
    TElem_vector & operator[](int pos) const;
    ~DynamicVector();

    void add(const TElem_vector & e);
    void remove(int position);
    int getSize();
    int getElement(int position);
};



#endif //DSALAB6_DYNAMICVECTOR_H
