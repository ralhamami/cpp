
#ifndef BST_H
#define BST_H

#include <iostream>
#include <cstdlib>
#include <new>
#include <deque>
using namespace std;

#include "TNode.h"

// Binary Search Tree
template <typename T>
class BST {
  private:
    TNode<T>* root;

    // INTERNAL IMPLEMENTATION
    TNode<T>* insert(T data, TNode<T>* r);
    TNode<T>* remove(T data, TNode<T>* r);
    void inOrder(TNode<T>* r, void (*visit)(T));
    void traverseLevel(TNode<T>* r);
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
    void traverseLevel(){traverseLevel(root);}
    bool search(T data) { return search(root, data); }
    int getNodeCount() { return getNodeCount(root); }
    int getLeafCount() { return getLeafCount(root); }
    int getHeight() { return getHeight(root); }
    T findMin() { return findMin(root)->data; }
};

template <typename T>
BST<T>::BST() {
  root = NULL;
}

template <typename T>
BST<T>::~BST() {
  if (root)
    deleteTree(root);
}

template <typename T>
void BST<T>::deleteTree(TNode<T>* rt) {
  if (rt) {
    deleteTree(rt->left);
    deleteTree(rt->right);
    delete rt;
  }
}

template <typename T>
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

template <typename T>
TNode<T>* BST<T>::remove(T data, TNode<T>* rt) {
  if (rt == NULL)
    return rt; // data not found. Do nothing.
  if (data < rt->data)
    rt->left = remove(data, rt->left);
  else if (data > rt->data)
    rt->right = remove(data, rt->right);

  // now, 'rt' holds 'data' to be removed
  else if (rt->left != NULL && rt->right != NULL)
  {
    // two children exist
    T minData = findMin(rt->right)->data;
    rt->data = minData;
    rt->right = remove(minData, rt->right);
  }
  else {
   // only one child exists
    TNode<T>* discard = rt;
    rt = (rt->left != 0) ? rt->left : rt->right;
    delete discard; // free memory allocated when 'insert'
  }

  return rt;
}

template <typename T>
void BST<T>::inOrder(TNode<T>* rt, void (*visit)(T)) {
  if (rt != NULL) {
    inOrder(rt->left, visit);
    (*visit)(rt->data);
    inOrder(rt->right, visit);
  }
}

//private: Print tree level by level, from left to right, top to bottom
template <typename T>
void BST<T>::traverseLevel(TNode<T>* rt)
 {if (rt != NULL)
   {deque<TNode<T>*> nq; //Queue for storing TNode pointers(data)
    int currLevel = 1; //Track current level in BST
    int nextLevel = 0; // Track next level, which will be root
    int count = 1; // Keeps count of level for output
    nq.push_back(rt);
    cout << "\n\n*** level traverse ***\nlevel 0 (root): ";
    while (!nq.empty())//While queue had data 
      {TNode<T>* currNode = nq.front();
       nq.pop_front();
       currLevel--;//Decrement after popping to keep track of level
       if (currNode) //If currNode is not NULL
         {cout << currNode->data << " ";
          nq.push_back(currNode->left);//Add left child to queue
          nq.push_back(currNode->right);//Add right child to queue
          nextLevel += 2;//Add 2 children for each parent
         }
       if (currLevel == 0 && count < getHeight())//If there are no more children
         {cout << endl;
          currLevel = nextLevel;
          cout << "level " << count++ << " ==> ";
          nextLevel = 0;
         }
      }
    cout << endl;
   }
 }

// private: search data in the BST with rt as root
template <typename T>
bool BST<T>::search(TNode<T>* rt, T data) {
  if (rt == NULL) return false;
  else if (rt->data == data) return true;
  else if (data < rt->data)
    return search(rt->left, data);
  else
    return search(rt->right, data);
}

template <typename T>
int BST<T>::getNodeCount(TNode<T>* r) {
  if (r == NULL) return 0;
  return getNodeCount(r->left) + getNodeCount(r->right) + 1;
}

template <typename T>
int BST<T>::getLeafCount(TNode<T>* r) {
  if (r == NULL) return 0;
  else if (r->left == NULL && r->right == NULL) return 1;
  else return getLeafCount(r->left) + getLeafCount(r->right);
}

template <typename T>
int BST<T>::getHeight(TNode<T>* r) {
  if (r == NULL) return 0;
  else if (r->left == NULL && r->right == NULL) return 1;
  else {
    int rh = getHeight(r->right);
    int lh = getHeight(r->left);
    return rh > lh ? rh+1 : lh+1;
  }
}

template <typename T>
TNode<T>* BST<T>::findMin(TNode<T>* r) {
  if (r == 0)
    return 0;
  else if (r->left == NULL)
    return r;
  else
    return findMin(r->left);
}

#endif
