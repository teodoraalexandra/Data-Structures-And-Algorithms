//
// Created by Teodora Dan on 2019-05-23.
//

#include <iostream>
#include "ValueIterator.h"

bool ValueIterator::valid() const  // Complexity: Theta(1)
{
    int i = 0;
    int pos = this->smm.h(key, i);
    while (i < this->smm.m && this->smm.hash[pos].key != MY_NULL && this->smm.hash[pos].key != key) {
        i++;
        pos = this->smm.h(key, i);
    }

    if (this->smm.hash[pos].key == key and this->current_element < this->values_added)
        // we found that key in the hash -> the iterator is valid
        return true;
    return false;
}

ValueIterator::ValueIterator(TKey k, const SortedMultiMap& input_smm) : smm( input_smm ) , key(k) // Complexity: Theta(m)
{
    this->current_element = 0;
    int i = 0;
    int pos = this->smm.h(key, i);
    while (i < this->smm.m && this->smm.hash[pos].key != MY_NULL && this->smm.hash[pos].key != key)
    {
        i++;
        pos = this->smm.h(key, i);
    }

    values_added = 0;
    if (this->smm.hash[pos].key == key)
    {
        // we found that key in the hash -> return its list of values
        for (int j = 0; j < this->smm.hash[pos].value.getSize(); j++) {
            vector_of_values.add(this->smm.hash[pos].value[j]);
            values_added ++;
        }
    }
}

ValueIterator::ValueIterator(TKey k, const ValueIterator& it) : smm(it.smm) , key(k) // Complexity: Theta(1)
{
    this->current_element = it.current_element;
}

void ValueIterator::first() // Complexity: Theta(1)
{
    if (!this->valid())
        throw exception();
    this->current_element = 0;
}

void ValueIterator::next() // Complexity: Theta(1)
{
    if (!this->valid())
        throw exception();
    this->current_element++;
}

TValue ValueIterator::getCurrent() const  // Complexity: Theta(1)
{
    if (!this->valid())
        throw exception();

    return this->vector_of_values[this->current_element];
}

ValueIterator::~ValueIterator()
{
}

