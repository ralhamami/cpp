#ifndef BST_H
#define BST_H

#include <iostream>
#include <cstdlib>
#include "TNode.h"
using namespace std;

template <class T>
class BST {
  private:
    TNode<T>* root;

    // INTERNAL IMPLEMENTATION
    TNode<T>* insert(T data, TNode<T>* r);
    TNode<T>* remove(T data, TNode<T>* r);
    void inOrder(TNode<T>* r, void (*visit)(T));
    bool search(TNode<T>* r, T data);
    int getNodeCount(TNode<T>* r);
    int getLeafCount(TNode<T>* r);
    int getHeight(TNode<T>* r);
    TNode<T>* findMin(TNode<T>* r);
    void deleteTree(TNode<T>* r);

  public:
    BST();
    virtual ~BST();

    // USER INTERFACE MEMBER FUNCTIONS
    void insert(T data) { root = insert(data, root); }
    void remove(T data) { root = remove(data, root); }
    void inOrder( void (*visit)(T) ) { inOrder(root, visit); }
    bool search(T data) { return search(root, data); }
    int getNodeCount() { return getNodeCount(root); }
    int getLeafCount() { return getLeafCount(root); }
    int getHeight() { return getHeight(root); }
    T findMin() { return findMin(root)->data; }
};

template <class T>
BST<T>::BST() {
  root = NULL;
}

template <class T>
BST<T>::~BST() {
  if (root != NULL)
    deleteTree(root);
  cout << "Destructor Called!" <<  endl;
}

template <class T>
void BST<T>::deleteTree(TNode<T>* rt) {
  if (rt) {
    deleteTree(rt->left);
    deleteTree(rt->right);
    delete rt;
  }
}

template <class T>
TNode<T>* BST<T>::insert(T data, TNode<T>* rt) {
  try {
    if (rt == NULL) {
      rt = new TNode<T>(data);
    } else if (data < rt->data) {
      rt->left = insert(data, rt->left);
    } else if (data > rt->data)
      rt->right = insert(data, rt->right);

    // else already exists. Ignore or Update counter.

    return rt;
  } catch (bad_alloc &e) {
    cout << "mem allocation exception: " << e.what() << endl;
    exit(1);
  }
}

template <class T>
TNode<T>* BST<T>::remove(T data, TNode<T>* rt) {
  if (rt == NULL)
    return rt; // data not found. Do nothing.
  if (data < rt->data)
    rt->left = remove(data, rt->left);
  else if (data > rt->data)
    rt->right = remove(data, rt->right);

  // now, 'rt' holds 'data' to be removed
  else if (rt->left !=NULL && rt->right != NULL)
  {
    // two children exist
    T minData = findMin(rt->right)->data;
    rt->data = minData;
    rt->right = remove(minData, rt->right);
  }
  else {
   // only one child exists
    TNode<T>* discard = rt;
    rt = (rt->left != NULL) ? rt->left : rt->right;
    delete discard; // free memory allocated when 'insert'
  }

  return rt;
}

template <class T>
void BST<T>::inOrder(TNode<T>* rt, void (*visit)(T)) {
  if (rt != 0) {
    inOrder(rt->left, visit);
    (*visit)(rt->data);
    inOrder(rt->right, visit);
  }
}

// private: search data in the BST with rt as root
template <class T>
bool BST<T>::search(TNode<T>* rt, T data) {
  if (rt == NULL) return false;
  else if (rt->data == data) return true;
  else if (data < rt->data)
    return search(rt->left, data);
  else
    return search(rt->right, data);
}

template <class T>
int BST<T>::getNodeCount(TNode<T>* r) {
  if (r == 0) return 0;
  return getNodeCount(r->left) + getNodeCount(r->right) + 1;
}

template <class T>
int BST<T>::getLeafCount(TNode<T>* r) {
  if (r == 0) return 0;
  else if (r->left == NULL && r->right == NULL) return 1;
  else return getLeafCount(r->left) + getLeafCount(r->right);
}

template <class T>
int BST<T>::getHeight(TNode<T>* r) {
  if (r == NULL) return 0;
  else if (r->left == NULL && r->right == NULL) return 1;
  else {
    int rh = getHeight(r->right);
    int lh = getHeight(r->left);
    return rh > lh ? rh+1 : lh+1;
  }
}

template <class T>
TNode<T>* BST<T>::findMin(TNode<T>* r) {
  if (r == 0)
    return 0;
  else if (r->left == NULL)
    return r;
  else
    return findMin(r->left);
}


#endif	/* BST_H */

