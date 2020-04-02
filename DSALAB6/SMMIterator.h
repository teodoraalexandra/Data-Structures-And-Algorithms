//
// Created by Teodora Dan on 2019-05-15.
//

#ifndef DSALAB6_SMMITERATOR_H
#define DSALAB6_SMMITERATOR_H

#endif //DSALAB6_SMMITERATOR_H

#pragma once
#include "SortedMultiMap.h"

class SMMIterator
{
    friend class SortedMultiMap;

public:
    const SortedMultiMap& smm;
    int current_position;
    int size_of_array;
    Node * sorted_array;

public:
    SMMIterator(const SortedMultiMap& input_smm);
    SMMIterator(const SMMIterator& it);
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;

    ~SMMIterator();
};