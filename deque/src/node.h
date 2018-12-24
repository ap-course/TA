#ifndef DEQUE_NODE_H
#define DEQUE_NODE_H

template<class T>
class Node {
public:
    Node() : next(nullptr) {}

    Node(T data, Node<T> *next = nullptr, Node<T> *prev = nullptr) : data(data), next(next), prev(prev) {}

    T data;
    Node<T> *next;
    Node<T> *prev;
};

#endif //DEQUE_NODE_H
