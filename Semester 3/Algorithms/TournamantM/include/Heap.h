#ifndef HEAP_H
#define HEAP_H


class Heap
{
    private:
        int* a;
        int heapSize;
        int maxSize;

    public:
        Heap(int n = 50);
        int retHeapSize();
        int findSecondMin();
        void insertEle(int);
        int retEleAt(int);
        void printHeap();
        ~Heap();
};

#endif // HEAP_H
