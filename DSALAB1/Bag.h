//
// Created by Teodora Dan on 2019-04-03.
//

#ifndef SDA_LAB1_BAG_H
#define SDA_LAB1_BAG_H

#endif //SDA_LAB1_BAG_H

#pragma once
#include "DynamicArray.h"


typedef int TElem;

class BagIterator;

class Bag {
    friend class BagIterator;

private:

    /*representation of Bag*/
    DynamicArray unique{};
    DynamicArray positions{};



public:

    //constructor

    Bag();



    //adds an element to the bag

    void add(TElem e);



    //removes one occurrence of an element from a bag

    //returns true if an element was removed, false otherwise (if e was not part of the bag)

    bool remove(TElem e);



    //checks if an element appearch is the bag

    bool search(TElem e);



    //returns the number of occurrences for an element in the bag

    int nrOccurrences(TElem e) const;



    //returns the number of elements from the bag

    int size() const;


    //returns an iterator for this bag

    BagIterator iterator() const;


    //checks if the bag is empty

    bool isEmpty() const;


    //LAB ACTIVITY
    int minimumFrequency() const;
    int elementsWithMinimumFrequency() const;

    //destructor

    ~Bag();

};