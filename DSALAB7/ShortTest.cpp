//
// Created by Teodora Dan on 2019-05-28.
//

#include "ShortTest.h"
#include "SortedMap.h"
#include "SortedMapIterator.h"
#include <assert.h>
#include <iostream>

using namespace std;

bool relatie1(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

bool relatie2(TKey cheie1, TKey cheie2) {
    if (cheie1 >= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testAll(){
    SortedMap sm(relatie1);
    assert(sm.size() == 0);
    assert(sm.isEmpty());
    sm.add(1,2);
    assert(sm.size() == 1);
    assert(!sm.isEmpty());
    assert(sm.search(1)!=NULL_TVALUE);
    TValue v =sm.add(1,3);
    assert(v == 2);
    assert(sm.search(1) == 3);
    SortedMapIterator it = sm.iterator();
    it.first();
    while (it.valid()) {
        TElem e = it.getCurrent();
        assert(e.second != NULL_TVALUE);
        it.next();
    }
    assert(sm.remove(1) == 3);
    assert(sm.isEmpty());
}

void testLabFirst() {
    SortedMap sm1(relatie1);
    assert(sm1.keySet().size() == 0);
    sm1.add(2, 3);
    sm1.add(1, 4);
    sm1.add(3, 5);
    assert(sm1.keySet().size() == 3);
}

void testLabSecond() {
    SortedMap sm2(relatie2);
    assert(sm2.keySet().size() == 0);
    sm2.add(5, 6);
    sm2.add(6, 7);
    sm2.add(1, 3);
    sm2.add(8, 9);
    assert(sm2.keySet().size() == 4);
}