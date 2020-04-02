//
// Created by Teodora Dan on 2019-04-03.
//

#include "BagIterator.h"
#include "Bag.h"
#include <exception>

using namespace std;


BagIterator::BagIterator(const Bag& c): bag (c)
{
    this->current = 0;
}


BagIterator::BagIterator(const BagIterator& it) : bag(it.bag )
{
    this->current = it.current;
}

void BagIterator::first()
{
    this->current = 0;
}

void BagIterator::next()
{
    if (!this->valid())
        throw exception();
    this->current++;
}

bool BagIterator::valid() const
{
    if (this->current < this->bag.size())
        return true;
    else
        return false;
}

TElem BagIterator::getCurrent()
{
    if (!this->valid())
        throw exception();

    int position;
    position = this->bag.positions[this->current];
    return this->bag.unique[position];
    return 0;
}