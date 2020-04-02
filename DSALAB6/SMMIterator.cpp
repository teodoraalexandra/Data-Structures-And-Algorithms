//
// Created by Teodora Dan on 2019-05-15.
//

#include "SMMIterator.h"

SMMIterator::SMMIterator(const SortedMultiMap& input_smm) : smm( input_smm ) // Complexity: Theta(m)
{
    this->size_of_array = smm.size();
    this->sorted_array = new Node[this->size_of_array];
    this->current_position = 0;

    int index = 0;
    for (int i = 0; i < smm.m; i++)
        if (smm.hash[i].key != MY_NULL && smm.hash[i].key != DELETED)
        {
            this->sorted_array[index] = smm.hash[i];
            index++;
        }

    bool unsorted;
    Node aux;
    do
    {
        unsorted = false;
        for (int i = 0; i < this->size_of_array - 1; i++)
            if (!smm.rel(this->sorted_array[i].key, this->sorted_array[i+1].key))
            {
                aux = this->sorted_array[i];
                this->sorted_array[i] = this->sorted_array[i + 1];
                this->sorted_array[i + 1] = aux;
                unsorted = true;
            }

    } while (unsorted);
}

SMMIterator::SMMIterator(const SMMIterator& it) : smm(it.smm) // Complexity: Theta(1)
{
    this->current_position = it.current_position;
}

void SMMIterator::first() // Complexity: Theta(1)
{
    this->current_position = 0;
}

void SMMIterator::next() // Complexity: Theta(1)
{
    if (!this->valid())
        throw exception();
    this->current_position++;
}

bool SMMIterator::valid() const  // Complexity: Theta(1)
{
    return (this->current_position < this->size_of_array);
}

TElem SMMIterator::getCurrent() const  // Complexity: Theta(1)
{
    if (!this->valid())
        throw exception();

    TElem e;
    e.first = this->sorted_array[this->current_position].key;
    e.second = this->sorted_array[this->current_position].value;
    return e;
}

SMMIterator::~SMMIterator()
{
}

