//
// Created by Teodora Dan on 2019-05-15.
//

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include "ValueIterator.h"
#include <iostream>
#include <typeinfo>


SortedMultiMap::SortedMultiMap(Relation r):rel(r) // Complexity: Theta(m)
{
    int prime_numbers[] = { 11, 23, 47, 97, 197, 397, 853, 1709, 3433, 6203, 12409, 25153, 50951, 100003, 200003, 400009, 800011, 1600033 };
    for (int i = 0; i < 18; i++)
        this->primes[i] = prime_numbers[i];
    this->posPrime = 0;

    this->m = this->primes[this->posPrime];
    this->number_of_elements = 0;
    this->hash = new Node[this->m];
    for (int i = 0; i < this->m; i++)
        this->hash[i].key = MY_NULL;  //initialize each element from the hash with a null value (INT_MIN)
}

void SortedMultiMap::add(TKey c, TValue v) // Complexity: O(m)
{
    int i = 0;
    int pos = this->h(c, i);
    int pos_deleted = -1;
    while (i < this->m && this->hash[pos].key != MY_NULL && this->hash[pos].key != c)
    {
        if (this->hash[pos].key == DELETED)
            pos_deleted = pos;
        i++;
        pos = this->h(c, i);
    }
    if (this->hash[pos].key == c)
    {
        // we have that key in the hash -> add the value to the list of values of the key
        this->hash[pos].value.add(v);
        this->number_of_elements ++;
    }

    else if (pos_deleted != -1)
    {
        // this means that we found a position "DELETED" -> we insert the key and value here
        this->hash[pos_deleted].key = c;
        this->hash[pos_deleted].value.add(v);
        this->number_of_elements++;
    }

    else
    {
        // we do not have the key in the multimap -> we add also the key and the list of values associated
        if (i == this->m) { // this is the case where hashtable is full -> resize it + add element
            this->resize();
            this->add(c, v);

        } else {
            this->hash[pos].key = c;
            this->hash[pos].value.add(v);
            this->number_of_elements++;
        }
    }
}

vector<int> SortedMultiMap::search(TKey c) // Complexity: O(m)
{
    int i = 0;
    int pos = this->h(c, i);
    while (i < this->m && this->hash[pos].key != MY_NULL && this->hash[pos].key != c)
    {
        i++;
        pos = this->h(c, i);
    }

    if (this->hash[pos].key == c)
    {
        // we found that key in the hash -> return its list of values
        std::vector<TValue> vector_of_values;
        for (int j = 0; j < this->hash[pos].value.getSize(); j++)
            vector_of_values.push_back(this->hash[pos].value[j]);
        return vector_of_values;
    }

    // we do not have the element in the hash -> return an empty vector
    std::vector<TValue> empty_vector;
    return empty_vector;
}


bool SortedMultiMap::remove(TKey c, TValue v) // Complexity: O(m)
{
    int i = 0;
    int pos = this->h(c, i);
    while (i < this->m && this->hash[pos].key != MY_NULL && this->hash[pos].key != c)
    {
        i++;
        pos = this->h(c, i);
    }

    if (this->hash[pos].key == c)
    {
        // we found the element in the hash -> start remove
        int position = -1;
        for(i = 0; i < this->hash[pos].value.getSize(); i++) {
            if (this->hash[pos].value[i] == v)
                position = i;
        }

        if (position == -1)
        {
            return false; //the value was not found in the list of the key -> return false
        }

        // remove the value from dynamic vector found at position "position"
        this->hash[pos].value.remove(position);

        // check if the vector of values of k is empty (only the key has remained) -> mark as DELETED
        if (this->hash[pos].value.getSize() == 0)
            this->hash[pos].key = DELETED;

        this->number_of_elements--;
        return true;
    }

    // we do not have found the element in the hash -> return false
    return false;
}


int SortedMultiMap::size() const // Complexity: Theta(1)
{
    return this->number_of_elements;
}

bool SortedMultiMap::isEmpty() const // Complexity: Theta(1)
{
    if (this->number_of_elements != 0)
        return false;
    else
        return true;
}

void SortedMultiMap::resize() // Complexity: O( old_m * m * vector_of_values.size() )
{
    // we take the next prime number -> set m with this value
    this->posPrime++;
    int old_m = this->m; // we need old_m for "transfer"

    Node* new_table = new Node[this->primes[this->posPrime]];
    this->m = this->primes[this->posPrime];

    for (int i = 0; i < this->m; i++)
        //initialize each element from the hash with a null value (INT_MIN)
        new_table[i].key = MY_NULL;

    for (int index = 0; index < old_m; index++)
    {
        TKey c = this->hash[index].key;
        if (c != MY_NULL && c != DELETED)
        {
            // create the vector associated with the TKey c
            DynamicVector vector_of_values = this->hash[index].value;
            for (int i = 0; i < this->m; i++)
                if (new_table[this->h(c, i)].key == MY_NULL)
                {
                    new_table[this->h(c, i)].key = c;
                    for (int j = 0; j < vector_of_values.getSize(); j++)
                        new_table[this->h(c, i)].value.add(vector_of_values[j]);
                    break;
                }
        }
    }
    this->hash = new_table;
}

SMMIterator SortedMultiMap::iterator() // Complexity: Theta(1)
{
    return SMMIterator(*this);
}

ValueIterator SortedMultiMap::value_iterator(TKey k)
{
    return ValueIterator(k, *this);
}

SortedMultiMap::~SortedMultiMap()
{
}
