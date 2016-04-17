#include <stdlib.h>
#include <time.h>
#include <deque>
#include <stack>
#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    heap test;
    cout << "previous:" << endl;
    test.output();
    test.build_max_heap();
    cout << "build:" << endl;
    test.output();
    cout << "sort:" << endl;
    test.heap_sort();
    for(int i = 0; i < MAX_NUM; i++) {
        cout << test.get_value(i )<< " ";
    }
}
