#include "Node.h"

#ifndef BST_H
#define BST_H

class BST
{
    private:
        void deletionByMergingP(Node*,Node*);   //merging by attaching smaller first
        void deletionByMergingS(Node*,Node*);   //merging by attaching larger first
        void deletionByCopyingP(Node*);         //by copying predeccesor
        void deletionByCopyingS(Node*);         //by copying successor

    public:
        BST();
        //BST(const BST&);
        Node* root;

        bool noTree() const;

        void insertI1(int);
        void insertI2(int);
        void insertR1(Node*  ,int);
        void insertR2(Node*, Node* ,int);
        void insertR3(Node*& ,int);
        Node* insertR4(Node* ,int);

        void deletionM1(int);           //merging by attaching smaller first
        void deletionM2(int);           //merging by attaching larger first
        void deletionC1(int);           //by copying predeccesor
        void deletionC2(int);           //by copying successor

        void mirror(Node*);
        int calc_height(Node*);
        int calc_sum(Node*);
        int noOfNodes(Node*);
        int calcMin(Node*);
        int calcMax(Node*);

        void preorder(Node*) const;
        void inorder(Node*) const;
        void postorder(Node*) const;
        void BFS() const;
        void DFS() const;

        //~BST();

};

#endif // BST_H
