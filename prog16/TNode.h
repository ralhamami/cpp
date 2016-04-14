#ifndef TNODE_H
#define TNODE_H

template <typename T>
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

template <typename T>
TNode<T>::TNode(T data) {
  this->data = data; 
  right = left = NULL;
}

template <typename T>
TNode<T>::~TNode() {
}

#endif
