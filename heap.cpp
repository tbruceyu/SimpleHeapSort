#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "heap.h"
using namespace std;
heap::heap()
{
    srand((unsigned)time(NULL));
    for (int loop_var = 0; loop_var != MAX_NUM; loop_var++) {
        this->a[loop_var] = rand() %100;
    }
}
void heap::output()
{
    for (int loop_var = 0; loop_var < MAX_NUM; loop_var = 1 + loop_var * 2) {
        for(int loop_var2 = loop_var; loop_var2 < 1+loop_var*2 && loop_var2 < MAX_NUM; loop_var2++) {
            cout << a[loop_var2] << " ";
        }
        cout << endl;
    }
}
int heap::parent(int pos)
{
    return pos/2;
}
int heap::left(int pos)
{
    return 2*pos+1;
}
int heap::right(int pos)
{
    return 2*pos+2;
}
int heap::get_value(int pos)
{
    return a[pos];
}
void heap::max_heapify(int pos, int max_size)
{
    int left = this->left(pos);
    int right = this->right(pos);
    int largest_pos = pos;
    //如果左节点大于本节点，则最大值为左节点，否则最大值为本身
    if (left < max_size && a[left] > a[pos]) {
        largest_pos = left;
    } else {
        largest_pos = pos;
    }
    //现在比较右节点
    if (right < max_size && a[right] > a[largest_pos]) {
        largest_pos = right;
    }

    if(largest_pos != pos) {
        int temp = a[pos];
        a[pos] = a[largest_pos];
        a[largest_pos] = temp;
        max_heapify(largest_pos, max_size);
    }
}

void heap::build_max_heap()
{
    for (int loop_var = MAX_NUM/2-1; loop_var >= 0; loop_var--) {
        this->max_heapify(loop_var, MAX_NUM);
    }
}
void heap::heap_sort()
{
    int heap_size = MAX_NUM;
    for (int loop_var = MAX_NUM-1; loop_var > 0; loop_var--) {
        int temp = a[loop_var];
        a[loop_var] = a[0];
        a[0] = temp;
        //堆的大小减1
        heap_size -= 1;
        this->max_heapify(0, heap_size);
    }
}
