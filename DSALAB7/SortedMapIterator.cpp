//
// Created by Teodora Dan on 2019-05-28.
//

#include "SortedMapIterator.h"

#include <stdexcept>

SortedMapIterator::SortedMapIterator(const SortedMap &map): map{map}, currentNode{nullptr}, stack{std::stack<BSTNode*>{}} {
    first();
}

//Inorder binary tree iterator
void SortedMapIterator::first() {
    //Complexity: O(n)
    currentNode = map.root;
    stack = std::stack<BSTNode*>{};
    while (currentNode != nullptr) {
        stack.push(currentNode);
        currentNode = currentNode->getLeftChild();
    }

    if (!stack.empty()) {
        currentNode = stack.top();
    }
    else {
        currentNode = nullptr;
    }
}

void SortedMapIterator::next() {
    //Complexity: Theta(1)
    if (!valid())
        throw std::runtime_error("");

    BSTNode* node = stack.top();
    stack.pop();

    if (node->getRightChild() != nullptr) {
        node = node->getRightChild();
        while (node != nullptr) {
            stack.push(node);
            node = node->getLeftChild();
        }
    }

    if (!stack.empty()) {
        currentNode = stack.top();
    }
    else {
        currentNode = nullptr;
    }
}

bool SortedMapIterator::valid() const {
    //Complexity: Theta(1)
    return currentNode != nullptr;
}

TElem SortedMapIterator::getCurrent() const {
    //Complexity: Theta(1)
    if (!valid())
        throw std::runtime_error("");
    TElem e;
    e.first = currentNode->getKey();
    e.second = currentNode->getValue();
    return e;
}
