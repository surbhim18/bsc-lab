#ifndef RODCUT_H
#define RODCUT_H


class RodCut
{
    private:
        int* p;
        int* r;
        int* s;
        int maxLen;
        void rod_cut_opt();

    public:
        RodCut(int len=0);
        void enterPrices();
        void printOptimalValue(int len);
        void printOptimalSolution(int len);
        void printAll();
        ~RodCut();

};

#endif // RODCUT_H
