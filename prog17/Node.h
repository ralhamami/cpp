/*
 * Programming II, Dr. Sung
 */
#ifndef NODE_H
#define NODE_H


template <typename T>
class Node {
private:
  T data;
  Node<T>* next;
public:
  Node(T);
  virtual ~Node(); // base class destructor must be virtual

  template <class U> friend class Stack; // allows dStack for private member access
  template <class U> friend class Queue; // allows dQueue for private member access
  template <class U> friend class List;
};
// constructor: create a new Node with d as data
template <class T>
Node<T>::Node(T data) {
  this->data = data;
  next = 0;
}

template <class T>
Node<T>::~Node() {
}
  
#endif
