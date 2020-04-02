#include <unistd.h>
#include <iostream>
using namespace std;

#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include "ValueIterator.h"

bool relation3(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testLab() {
    SortedMultiMap smm = SortedMultiMap(relation3);
    smm.add(1,2);
    smm.add(1,3);
    ValueIterator it = smm.value_iterator(1);
    it.first();
    while (it.valid()){
        TValue e = it.getCurrent();
        it.next();
    }
}

int main()
{
    testAll();
    cout << "Short test passed\n";
    testAllExtended();
    cout << "Extended test passed\n";
    testLab();
    cout << "Laboratory test passed\n";
    return 0;
} 