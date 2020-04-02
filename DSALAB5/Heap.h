//
// Created by Teodora Dan and her groupmate <3 on 2019-05-07.
//

#pragma once
#include <utility>
#include <vector>
#include "DynamicArray.h"

typedef int TElem;

using namespace std;


typedef bool(*Relation)(TElem p1, TElem p2);

//removes the last k elements from the vector (considering the relation)
//if k is less than or equal to zero, throws an exception
//if k is greater than the size of the array, all elements will be removed

/* FROM OLD IMPLEMENTATION
void removeLast(vector<TElem>& elements, Relation r, int k);
void bubble_down(DynamicArray dynamicArray, int len, int index, Relation r);
void buildHeap(DynamicArray dynamicArray, int n, Relation r);
void extractRoot(DynamicArray dynamicArray, int &n, Relation r); */

void removeLast(vector<TElem>& elements, Relation r, int k);
void restoreDown(DynamicArray& vec, int len, int index, Relation r);
DynamicArray buildHeap(vector<TElem>& elements, int k, Relation r);
void extractRoot(DynamicArray& vec, int k, Relation r);
void restoreUp(DynamicArray& vec, int index, Relation r);
void insert(DynamicArray& vec, int k, int elem, Relation r);

