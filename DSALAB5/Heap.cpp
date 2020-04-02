//
// Created by Teodora Dan and her groupmate <3 on 2019-05-07.
//

#include "Heap.h"
#include <iostream>
#include <stdexcept>
using namespace std;

/* FROM OLD IMPLEMENTATION
void bubble_down(DynamicArray dynamic_array, int len, int index, Relation r) // COMPLEXITY : O(log4n)
{
    // child array to store indexes of all the children of given node
    int child[5];

    while (true)
    {
        // child[i] = -1 if the node is a leaf children (no children)
        for (int i = 1; i <= 4; i++)
            child[i] = ((4 * index + i) < len) ? (4 * index + i) : -1;

        // min_max stores the maximum child and
        // min_max_index holds its index
        int min_max = r(INT_MIN, INT_MAX) ? INT_MIN : INT_MAX, min_max_index;

        //MIN HEAP -> int_max
        //MAX HEAP -> int_min

        // loop to find the maximum of all the children of a given node
        for (int i = 1; i <= 4; i++)
        {

            if (child[i] != -1 && !r(dynamic_array[child[i]], min_max))
                //if (child[i] != -1 && (elements[child[i]] > min_max))
                // "<" relation for MIN HEAP   ">" relation for MAX HEAP
            {
                min_max_index = child[i];
                min_max = dynamic_array[child[i]];
            }
        }

        // leaf node
        int original_min_max = r(INT_MIN, INT_MAX) ? INT_MIN : INT_MAX;
        if (min_max == original_min_max)
            //MIN HEAP -> int_max
            //MAX HEAP -> int_min
            break;

        // swap only if the key of min_max_index is greater than the key of node
        if (r(dynamic_array[index], dynamic_array[min_max_index]))
            swap(dynamic_array[index], dynamic_array[min_max_index]);

        // ">" relation for MIN HEAP   "<" relation for MAX HEAP
        index = min_max_index;
    }
}


void buildHeap(DynamicArray dynamic_array, int n, Relation r)
{

    // Heapify all internal nodes starting from last non-leaf node all the way up
    // to the root node and calling restore down on each
    for (int i = (n - 1) / 4; i >= 0; i--)
        bubble_down(dynamic_array, n, i, r);
}

void extractRoot(DynamicArray dynamic_array, int &n, Relation r)
{
    //COMPLEXITY: theta(1)
    // Copy the last node's key to the root node
    dynamic_array[0] = dynamic_array[n - 1];

    // Decrease heap size by 1
    n = n - 1;
    dynamic_array.removeLast();

    // Call bubble_down on the root node to restore it to the correct position in the heap
    bubble_down(dynamic_array, n, 0, r);
}

void removeLast(vector<TElem>& elements, Relation r, int k)
{
    //COMPLEXITY : theta(1)
    DynamicArray dynamic_array;
    for (int i = 0; i < elements.size(); i++) {
        dynamic_array.add(elements[i]);
    }

    //int n = elements.size();
    int n = dynamic_array.getSize();

    buildHeap(dynamic_array, n, r);
    if (k <= 0) {
        throw exception();
    }
    if (k >= n) {
        //clear the dynamic array
        for (int i = 0; i < elements.size(); i++) {
            dynamic_array.removeLast();
        }
        return;
    }
    for (int i = 0; i < k; i++) {
        extractRoot(dynamic_array, n, r);
    }
} */

void restoreDown(DynamicArray& vec, int len, int index, Relation r) //O(log4 k)
{
    // child array to store indexes of all the children of given node
    int child[5];

    while (true)
    {
        // child[i]=-1 if the node is a leaf
        // children (no children)
        for (int i = 1; i <= 4; i++)
            child[i] = ((4 * index + i) < len) ? (4 * index + i) : -1;

        // min_max stores the maximum child and
        // min_max_index holds its index
        int min_max = r(INT_MIN, INT_MAX) ? INT_MAX : INT_MIN, min_max_index;

        //MIN HEAP -> int_max
        //MAX HEAP -> int_min

        // loop to find the maximum of all the children of a given node
        for (int i = 1; i <= 4; i++)
        {

            if (child[i] != -1 && r(vec[child[i]], min_max))
                //if (child[i] != -1 && (elements[child[i]] > min_max))
                // "<" relation for MIN HEAP   ">" relation for MAX HEAP
            {
                min_max_index = child[i];
                min_max = vec[child[i]];
            }
        }

        // leaf node
        int original_min_max = r(INT_MIN, INT_MAX) ? INT_MAX : INT_MIN;
        if (min_max == original_min_max)
            //MIN HEAP -> int_max
            //MAX HEAP -> int_min
            break;

        // swap only if the key of min_max_index
        // is greater than the key of node
        //if (elements[index] < elements[min_max_index])
        if (!r(vec[index], vec[min_max_index]))
            swap(vec[index], vec[min_max_index]);
        // ">" relation for MIN HEAP   "<" relation for MAX HEAP

        index = min_max_index;
    }
}


DynamicArray buildHeap(vector<TElem>& elements, int k, Relation r) //O(k)
{
    // Heapify all internal nodes starting from last
    // non-leaf node all the way upto the root node
    // and calling restore down on each
    //for (int i= (n-1)/4; i >= 0 ; i--)
    DynamicArray vec{ k+1 }; // our heap will contain exactly k elements
    for (int i = 0; i < k; i++)
        vec.add(elements[i]); //add first k elements from the std::vector into the dynamic vector
    for (int i = (k - 1) / 4; i >= 0; i--)
        restoreDown(vec, k, i, r);
    return vec;
}

void extractRoot(DynamicArray& vec, int k, Relation r)//O(log4 k)
{
    // Copy the last node's key to the root node
    vec[0] = vec[k - 1];



    // Call restoreDown on the root node to restore
    // it to the correct position in the heap
    restoreDown(vec, k, 0, r);


}

void restoreUp(DynamicArray& vec, int index, Relation r)//O(log4 k)
{
    // parent stores the index of the parent variable
    // of the node
    int parent = (index - 1) / 4;

    // Loop should only run till root node in case the
    // element inserted is the maximum restore up will
    // send it to the root node
    while (parent >= 0)
    {
        if (r(vec[index], vec[parent])) //cross-check for errors
        {
            swap(vec[index], vec[parent]);
            index = parent;
            if (index == 0)
                break;
            parent = (index - 1) / 4;
        }

            // node has been restored at the correct position
        else
            break;
    }
}

void insert(DynamicArray& vec, int k, int elem, Relation r) //O(log4 k)
{
    // Put the new element in the last position
    vec[k-1] = elem;

    // Call restoreUp on the last index
    restoreUp(vec, k-1, r);
}

void removeLast(vector<TElem>& elements, Relation r, int k) //Theta(k*(n-k))
{
    //build heap from the first k elements in the vector
    DynamicArray vec = buildHeap(elements, k, r); //O(k)
    if (k <= 0) {
        throw exception();
    }
    if (k >= elements.size()) {
        elements.clear();
        return;
    }
    //parse the elements from index k to n-1 and if they are
    //greater than the root of a min heap or smaller than the
    //root of a max heap, extract the root and insert them into
    //the heap
    for (int i = k; i < elements.size(); i++)// O((n-k)*log4 k)
    {
        if (!r(elements[i], vec[0]))
        {
            extractRoot(vec, k, r);
            insert(vec, k, elements[i], r);
        }
    }
    //parse all the elements in the heap and erase them from the input vector
    for (int i = 0; i < k; i++)// Theta(k(n-k))
    {
        elements.erase(find(elements.begin(), elements.end(), vec[i]));
    }
}
