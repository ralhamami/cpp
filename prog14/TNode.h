#ifndef TNODE_H
#define TNODE_H

#include <iostream>
using namespace std;

template <class T>
class TNode {
  private:
    TNode<T>* right; // pointer to right child
    TNode<T>* left; // pointer to left child
    T data;
  public:
    TNode(T data);
    virtual ~TNode();

    template <class U> friend class BST;
};

template <class T>
TNode<T>::TNode(T data) {
  this->data = data; 
  right = left = NULL;
}

template <class T>
TNode<T>::~TNode() {
}

#endif	/* TNode_H */

