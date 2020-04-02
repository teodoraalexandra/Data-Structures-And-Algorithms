//
// Created by Teodora Dan on 2019-04-03.
//

#ifndef SDA_LAB3_SMMITERATOR_H
#define SDA_LAB3_SMMITERATOR_H

#endif //SDA_LAB3_SMMITERATOR_H

#pragma once

#include "SortedMultiMap.h"

class SortedMultiMap;


class SMMIterator {

    friend class SortedMultiMap;

private:
    SMMIterator(const SortedMultiMap& m);
    const SortedMultiMap& m;
    node* currentNode;
public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;


};



