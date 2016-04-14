#ifndef HEAP_H
#define HEAP_H

#include <vector>
using namespace std;

template <class T>
class Heap {
private:
    vector<T> elements;
    
public:
    Heap();
    ~Heap();
    void push(T e); // adds a new element to this heap
    T top() const; // gets the max element in the heap
    void pop(); // removes the max element from the heap
    int size() const; // returns the # of elements in the heap
    
private: // utility functions
    // fixes the heap where only the root node violates the heap condition
    void fix_heap();
    
    int get_left_child_index(int index); // index of left child for the node at 'index'
    int get_right_child_index(int index);
    int get_parent_index(int index);
    
    T get_left_child(int index); // value of the left child
    T get_right_child(int index);
    T get_parent(int index);
};

template <class T>
Heap<T>::Heap() {
    elements.push_back(T()); //Default constructor of type T to push not-used value
}

template <class T>
Heap<T>::~Heap() {
    cout << "Destructor called!\n";
}

template <class T>
void Heap<T>::push(T new_element) {
    // add a new leaf
    elements.push_back(T()); //Default constructor of type T to push not-used value
    int index = elements.size() - 1;
    
    // demote parents that are smaller than the new element
    while (index >1 && get_parent(index) < new_element) {
        elements[index] = get_parent(index);
        index = get_parent_index(index);
    }
    
    // store the new element into the vacant slot
    elements[index] = new_element;
}

template <class T>
T Heap<T>::top() const {
    return elements[1];
}

template <class T>
void Heap<T>::pop() {
    // remove the last element
    int last_index = elements.size() - 1;
    T last = elements[last_index];
    elements.pop_back(); // remove
    
    if (last_index > 1) {
        elements[1] = last;
        fix_heap();
    }
}

template <class T>
int Heap<T>::size() const {
    return elements.size() - 1; // note: elements[0] is not used
}

template <class T>
void Heap<T>::fix_heap() {
    T root = elements[1];
    int last_index = elements.size() - 1;
    
    // promote children of removed root while they are larger than last
    int index = 1;
    bool more = true;
    while (more) {
        int child_index = get_left_child_index(index);
        if (child_index <= last_index) {
            // get larger child
            // get left child first
            T child = get_left_child(index);
            // use right child instead if it is larger
            if (get_right_child_index(index) <= last_index &&
                    get_right_child(index) > child) {
                child_index = get_right_child_index(index);
                child = get_right_child(index);
            }
            
            // check if smaller child is larger than root
            if (child > root) {
                // promote child
                elements[index] = child;
                index = child_index;
            } else {
                // root is larger than both children
                more = false;
            }
        } else {
            // no children
            more = false;
        }
    }
    
    // store root element in vacant slot
    elements[index] = root;
}

template <class T>
int Heap<T>::get_left_child_index(int index) {
    return 2 * index;
}

template <class T>
int Heap<T>::get_right_child_index(int index) {
    return 2 * index + 1;
}

template <class T>
int Heap<T>::get_parent_index(int index) {
    return index / 2;
}

template <class T>
T Heap<T>::get_left_child(int index) {
    return elements[get_left_child_index(index)];
}

template <class T>
T Heap<T>::get_right_child(int index) {
    return elements[get_right_child_index(index)];
}

template <class T>
T Heap<T>::get_parent(int index) {
    return elements[get_parent_index(index)];
}


#endif	/* Heap_H */
