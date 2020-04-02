//
// Created by Teodora Dan on 2019-04-03.
//

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <iostream>

SortedMultiMap::SortedMultiMap(Relation r) {
    dllMap = new DLL();
    dllMap->head = NULL;
    dllMap->tail = NULL;
    this->rel = r;
}

void SortedMultiMap::add(TKey c, TValue v)
{
    node* newNode = new node();
    newNode->element.first = c;
    newNode->element.second = v;
    newNode->next = NULL;
    newNode->previous = NULL;

    //If the SMM is empty
    if (dllMap->head == NULL)
    {
        dllMap->head = newNode;
        dllMap->tail = newNode;
    }
    else {
        //The SMM has at least one element
        node* auxiliaryNode = dllMap->head;
        while (auxiliaryNode != NULL && rel(auxiliaryNode->element.first, c))
            auxiliaryNode = auxiliaryNode->next;

        if(auxiliaryNode == dllMap->head)
        {
            //SMM has exactly one element
            newNode->next = dllMap->head;
            dllMap->head = newNode;
            newNode->previous = NULL;
            dllMap->head->previous = NULL;
        }
        else
        {
            node* aux = dllMap->head;
            while(aux->next != auxiliaryNode && aux != NULL)
                aux = aux->next;

            newNode->next = auxiliaryNode;
            aux->next = newNode;
            newNode->previous = aux;
        }
    }
}

bool SortedMultiMap::remove(TKey c, TValue v)
{
    node* n = dllMap->head;
    while (n!=NULL)
    {
        //We iterate through SMM and if element exist, we remove it and return True
        if (n->element.first == c && n->element.second == v)
        {
            if (dllMap->head == n)
                dllMap->head = n->next;
            else{
                node *auxiliaryNode = dllMap->head;
                while(auxiliaryNode->next != n)
                    auxiliaryNode = auxiliaryNode->next;
                auxiliaryNode->next = n->next;
            }

            delete n;
            return true;
        }

        n = n->next;
    }
    return false;
}


vector<TValue> SortedMultiMap::search(TKey c) const {
    vector<TValue> v;
    node* n = dllMap->head;
    while (n != NULL)
    {
        if (n->element.first == c)
            v.push_back(n->element.second);

        n = n->next;
    }
    return v;
}


int SortedMultiMap::size() const
{
    node* n = dllMap->head;
    int count = 0;
    while (n != NULL)
    {
        count++;
        n = n->next;
    }
    return count;
}


bool SortedMultiMap::isEmpty() const
{
    return size() == 0;
}

SMMIterator SortedMultiMap::iterator() const
{
    return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap()
{
}



