//
// Created by Teodora Dan on 2019-05-28.
//

#ifndef DSALAB7_SORTEDSETITERATOR_H
#define DSALAB7_SORTEDSETITERATOR_H


#include "SortedMap.h"
#include "BSTNode.h"
#include <stack>

class SortedMap;
typedef int TKey;

typedef int TValue;

typedef std::pair<TKey, TValue> TElem;

class SortedMapIterator {

private:
    const SortedMap& map;
    BSTNode* currentNode;
    std::stack <BSTNode*> stack;

public:
    SortedMapIterator(const SortedMap& map);
    //sets the iterator to the first element of the container
    void first();

    //moves the iterator to the next element
    //throws exception if the iterator is not valid
    void next();

    //checks if the iterator is valid
    bool valid() const;

    //returns the value of the current element from the iterator
    // throws exception if the iterator is not valid
    TElem getCurrent() const;
};


#endif //DSALAB7_SORTEDSETITERATOR_H
