//
// Created by Teodora Dan on 2019-05-23.
//

#ifndef DSALAB6_VALUEITERATOR_H
#define DSALAB6_VALUEITERATOR_H

#pragma once
#include "SortedMultiMap.h"
#include "DynamicVector.h"

class ValueIterator
{
    friend class SortedMultiMap;

public:
    const SortedMultiMap& smm;
    int current_element;
    DynamicVector vector_of_values;
    int values_added;
    TKey key;

public:
    ValueIterator(TKey k, const SortedMultiMap& input_smm);
    ValueIterator(TKey k, const ValueIterator& it);
    void first();
    void next();
    bool valid() const;
    TValue getCurrent() const;

    ~ValueIterator();
};


#endif //DSALAB6_VALUEITERATOR_H
