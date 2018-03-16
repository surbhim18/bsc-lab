#ifndef PQUEUEH_H
#define PQUEUEH_H


class PQueueH
{
    private:
        int* a;
        int heapSize;
        int maxSize;
        void maxHeapify(int);
    public:
        PQueueH(int n = 10);
        int retHeapSize();
        int retMax();
        void increaseKey(int, int);
        void insertEle(int);
        int extractMax();
        void printQueue();
        ~PQueueH();
};

#endif // PQUEUEH_H
