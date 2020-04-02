//
// Created by Teodora Dan on 2019-04-03.
//

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <stdexcept>

SMMIterator::SMMIterator(const SortedMultiMap& m) : m(m)
{
    currentNode = m.dllMap->head;
}

void SMMIterator::first()
{
    currentNode = m.dllMap->head;
}

void SMMIterator::next()
{
    if (!this->valid())
    {
        throw exception();
    }
    if (currentNode != NULL)
    {
        currentNode = currentNode->next;
    }
}

bool SMMIterator::valid() const
{

    if (currentNode!= NULL)
        return true;
    return false;

}

TElem SMMIterator::getCurrent() const
{
    if (!this->valid())
    {
        throw exception();
    }
    return currentNode->element;
}
