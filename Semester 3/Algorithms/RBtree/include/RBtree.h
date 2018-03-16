#include "Node.h"

#ifndef RBTREE_H
#define RBTREE_H

class RBtree
{
    private:
        Node* root;
        bool growth_in_same_direction(Node* x);
        void fixInsert(Node* x);
        void fixDelete(Node* x);
        void insert(Node*& _root, int _key, Node*& _p);
        void deletionByCopying(Node* temp);
        void inorder(Node* root);
        void postorder(Node* root);
        void left_rotate(Node* x);
        void right_rotate(Node* x);

    public:
        RBtree();
        void insert(int _key);
        void deletion(int ele);
        void inorder();
        void postorder();
};

#endif // RBTREE_H
