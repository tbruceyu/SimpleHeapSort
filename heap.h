#ifndef HEAP_H
#define HEAP_H
#define MAX_NUM 10
class heap
{
public:
    heap();
    int get_value(int pos);
    void max_heapify(int pos, int max_size);
    void build_max_heap();
    void heap_sort();
    void output();
private:
    int a[MAX_NUM];
    int parent(int pos);
    int left(int pos);
    int right(int pos);
};

#endif // HEAP_H
