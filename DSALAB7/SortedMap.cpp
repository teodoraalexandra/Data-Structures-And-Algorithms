//
// Created by Teodora Dan on 2019-05-28.
//

#include "SortedMap.h"
#include <iostream>
#include <vector>
#include <utility>


BSTNode *SortedMap::getMaximum(BSTNode *startingRoot) {
    //Complexity: O(n)
    BSTNode *currentNode = root;
    BSTNode *maxNode = root;

    while (currentNode != nullptr) {
        maxNode = currentNode;
        currentNode = currentNode->getRightChild();
    }
    return maxNode;
}

BSTNode *SortedMap::removeRecursively(BSTNode *node, TKey k, bool &removed) {
    if (node == nullptr) {
        return node;
    }

    if (k == node->getKey()) {
        removed = true;
        if (node->getLeftChild() == nullptr) {
            BSTNode* rightSon = node->getRightChild();
            delete node;
            return rightSon;
        }
        else if (node->getRightChild() == nullptr) {
            BSTNode* leftSon = node->getLeftChild();
            delete node;
            return leftSon;
        }
        else {
            BSTNode *maxNode = getMaximum(node->getLeftChild());
            node->setValue(maxNode->getValue());
            node->setLeftChild(removeRecursively(node->getLeftChild(), maxNode->getValue(), removed));
        }
    }
    else if (rel(k, node->getKey())) {
        node->setLeftChild(removeRecursively(node->getLeftChild(), k, removed));
    }
    else {
        node->setRightChild(removeRecursively(node->getRightChild(), k, removed));
    }
    return node;
}

SortedMap::SortedMap(Relation r): root{nullptr}, numberOfElements{0}, rel{r} {
}

TValue SortedMap::add(TKey k, TValue v) {
    //Complexity: O(n)
    BSTNode *current = root;
    BSTNode *parent = nullptr;

    while (current != nullptr) {
        //Search for key
        //If it exists -> replace with the new value -> return the old value
        parent = current;

        if (k == current->getKey() and v != current->getValue()) {
            TValue oldValue = current->getValue();
            current->setValue(v);
            return oldValue;
        }

        else if (rel(k, current->getKey())) {
            current = current->getLeftChild();
        }
        else {
            current = current->getRightChild();
        }
    }

    TElem e;
    e.first = k;
    e.second = v;
    BSTNode *newNode = new BSTNode{e};
    if (root == nullptr) {
        root = newNode;
    }
    else if (rel(k, parent->getKey())) {
        parent->setLeftChild(newNode);
    }
    else {
        parent->setRightChild(newNode);
    }
    numberOfElements++;
    return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
    //The three cases:
    //  The node to be removed has no descendant -> Set the corresponding child of the parent to NIL
    //  The node to be removed has one descendant -> Set the corresponding child of the parent to the descendant
    //  The node to be removed has two descendants
    //         -> Find the maximum of the left subtree, move it to the node to be deleted, and delete the maximum
    //         -> Find the minimum of the right subtree, move it to the node to be deleted, and delete the minimum
    BSTNode *current = root;

    while (current != nullptr) {
        if (k == current->getKey()) {
            //We find the node -> we remove it using removeRecursively
            TValue valueDeleted = current->getValue();
            bool removed = false;
            root = removeRecursively(root, k, removed);
            if (removed)
                numberOfElements--;
            return valueDeleted;
        }
        else if (rel(k, current->getKey())) {
            current = current->getLeftChild();
        }
        else {
            current = current->getRightChild();
        }
    }
    return NULL_TVALUE;
}

TValue SortedMap::search(TKey k) const {
    //Complexity: O(n)
    BSTNode *current = root;

    while (current != nullptr) {
        if (k == current->getKey()) {
            return current->getValue();
        }
        if (rel(k, current->getKey())) {
            current = current->getLeftChild();
        }
        else {
            current = current->getRightChild();
        }
    }
    return NULL_TVALUE;
}

std::vector<TKey> SortedMap::keySet() const {
    //Complexity: Theta(n)
    std::vector<TKey> empty;
    if (numberOfElements == 0) {
        return empty;
    } else {
        std::vector<TKey> all_keys;
        SortedMapIterator it = this->iterator();

        while (it.valid()) {
            TElem e = it.getCurrent();
            all_keys.push_back(e.first);
            it.next();
        }
        return all_keys;
    }
}

int SortedMap::size() const {
    //Complexity: Theta(1)
    return numberOfElements;
}

bool SortedMap::isEmpty() const {
    //Complexity: Theta(1)
    return numberOfElements == 0;
}

SortedMapIterator SortedMap::iterator() const {
    //Complexity: Theta(1)
    return SortedMapIterator(*this);
}

SortedMap::~SortedMap()
{
}

