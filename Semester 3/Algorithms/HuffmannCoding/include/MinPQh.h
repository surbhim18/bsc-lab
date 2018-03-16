#ifndef MINPQH_H
#define MINPQH_H
#include "Tree.h"
#include "Tree.h"

class MinPQh
{
    private:
        Tree* a;
        int heapSize;
        int maxSize;
        void minHeapify(int);
        void increaseKey(int index, Tree node);
    public:
        MinPQh(int n = 10);
        int retHeapSize();
        Tree retMax();
        void insertEle(Tree);
        TreeNode extractMin();
        void printQueue();
        ~MinPQh();
};

#endif // MINPQH_H
