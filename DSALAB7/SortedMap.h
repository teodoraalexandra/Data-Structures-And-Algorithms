//
// Created by Teodora Dan on 2019-05-28.
//

#ifndef DSALAB7_SORTEDSET_H
#define DSALAB7_SORTEDSET_H

#include "SortedMapIterator.h"
#include "BSTNode.h"
#include <vector>
#include <utility>
#include <iostream>
#include <stack>

typedef int TKey;

typedef int TValue;

typedef std::pair<TKey, TValue> TElem;

typedef bool(*Relation)(TKey, TKey);

#define NULL_TVALUE -1

class SortedMapIterator;

class SortedMap {

public:
    BSTNode *root;
    int numberOfElements;
    Relation rel;

    BSTNode* getMaximum(BSTNode* startingRoot);
    BSTNode* removeRecursively(BSTNode* node, TKey k, bool &removed);

public:
    //constructor
    SortedMap(Relation r);


    // adds a pair (key,value) to the map

    //if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned

    //if the key does not exist, a new pair is added and the value null is returned

    TValue add(TKey c, TValue v);


    //removes a key from the map and returns the value associated with the key if the key existed or null: NULL_TVALUE otherwise

    TValue remove(TKey c);


    //searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise

    TValue search(TKey c) const;

    //returns a vector with all the keys from the sorted map
    std::vector<TKey> keySet() const;

    //returns the number of elements from the sorted map
    int size() const;

    //checks if the sorted map is empty
    bool isEmpty() const;

    //returns an iterator for the sorted map
    SortedMapIterator iterator() const;

    // destructor
    ~SortedMap();
};


#endif //DSALAB7_SORTEDSET_H
