//
// Created by Teodora Dan on 2019-05-28.
//

#include "BSTNode.h"

BSTNode::BSTNode(std::pair<TKey, TValue> value, BSTNode *leftChild, BSTNode *rightChild) : value{value}, leftChild{leftChild}, rightChild{rightChild} {}

TKey BSTNode::getKey() const {
    return value.first;
}

TValue BSTNode::getValue() const {
    return value.second;
}

void BSTNode::setKey(TKey key) {
    BSTNode::value.first = key;
}

void BSTNode::setValue(TValue value) {
    BSTNode::value.second = value;
}

BSTNode *BSTNode::getLeftChild() const {
    return leftChild;
}

void BSTNode::setLeftChild(BSTNode *leftSon) {
    BSTNode::leftChild = leftSon;
}

BSTNode *BSTNode::getRightChild() const {
    return rightChild;
}

void BSTNode::setRightChild(BSTNode *rightSon) {
    BSTNode::rightChild = rightSon;
}

bool BSTNode::isLeaf() {
    return leftChild == nullptr && rightChild == nullptr;
}