//
// Created by Teodora Dan on 2019-04-03.
//

#ifndef SDA_LAB1_BAGITERATOR_H
#define SDA_LAB1_BAGITERATOR_H

#endif //SDA_LAB1_BAGITERATOR_H

#pragma once
#include "Bag.h"


//unidirectional iterator for a container

class BagIterator{

    friend class Bag;

private:

    int current;

    //Constructor receives a reference of the container.

    //after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty


    const Bag& bag;

public:
    BagIterator(const Bag& bag);

    BagIterator(const BagIterator& it);



    //contains a reference of the container it iterates over




    /* representation specific for the iterator*/



public:



    //sets the iterator to the first element of the container

    void first();



    //moves the iterator to the next element

    //throws exception if the iterator is not valid

    void next();



    //checks if the iterator is valid

    bool valid() const;



    //returns the value of the current element from the iterator

    // throws exception if the iterator is not valid

    TElem getCurrent();



};


