#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"

template<class T>
class Deque {
public:
    Deque();

    T get(int index);

    void insert(T data, int index);

    void push_back(T data);

    void push_front(T data);

    T pop_front();

    T pop_back();

private:
    Node<T> *dummy;
    int size;

    Node<T> *insert_after(Node<T> *prev_node, T new_data);

    Node<T> *find_node(int index);
};

#include "deque.cpp"

#endif //DEQUE_H
