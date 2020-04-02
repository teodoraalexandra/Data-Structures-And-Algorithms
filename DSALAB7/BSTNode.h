//
// Created by Teodora Dan on 2019-05-28.
//

#ifndef DSALAB7_BSTNODE_H
#define DSALAB7_BSTNODE_H

#include "utility"
typedef int TKey;

typedef int TValue;

typedef std::pair<TKey, TValue> TElem;

class BSTNode {
private:
    TElem value;
    BSTNode *leftChild;
    BSTNode *rightChild;

public:
    BSTNode(std::pair<TKey, TValue> value, BSTNode *leftChild = nullptr, BSTNode *rightChild = nullptr);
    TKey getKey() const;
    void setKey(TKey key);
    TValue getValue() const;
    void setValue(TValue value);

    BSTNode *getLeftChild() const;
    void setLeftChild(BSTNode *leftSon);
    BSTNode *getRightChild() const;
    void setRightChild(BSTNode *rightSon);
    bool isLeaf(); //Leaf means that it has no children
};


#endif //DSALAB7_BSTNODE_H
