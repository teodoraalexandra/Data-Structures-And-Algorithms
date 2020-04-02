//
// Created by Teodora Dan on 2019-05-15.
//

#ifndef DSALAB6_SORTEDMULTIMAP_H
#define DSALAB6_SORTEDMULTIMAP_H

#endif //DSALAB6_SORTEDMULTIMAP_H

#pragma once
#include <vector>
typedef int TKey;
typedef int TValue;

#include <utility>
#include <limits.h>
#include "DynamicVector.h"

using namespace std;

typedef bool(*Relation)(TKey, TKey);

class SMMIterator;
class ValueIterator;

#define DELETED INT_MAX
#define MY_NULL INT_MIN


struct Node {
    TKey key;
    DynamicVector value{};
};

typedef std::pair<TKey, DynamicVector> TElem;

class SortedMultiMap {
public:
    /* representation of the SortedMultiMap */
    Node* hash;
    int m;
    int number_of_elements;
    Relation rel;
    int primes[18];
    int posPrime;
    int h(int k, int i) const {
        if (k > 0)
            return  (k % m + i * (1 + (k % (m - 1)))) % m;
        else
            return  ((m+(k%m)) % m + i * (1 + ((m-1) + k % (m - 1))%(m-1))) % m;
    }
    void resize();

public:
    // constructor
    SortedMultiMap(Relation r);

    //adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

    //returns the values belonging to a given key
    vector<int> search(TKey c);

    //removes a key value pair from the sorted multimap
    //returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)
    SMMIterator iterator();
    ValueIterator value_iterator(TKey k);

    // destructor
    ~SortedMultiMap();

};
