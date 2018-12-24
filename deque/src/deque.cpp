#include "deque.h"

#ifndef DEQUE_IMPL
#define DEQUE_IMPL


template<class T>
Deque<T>::Deque() {
    this->dummy = new Node<T>;
    this->dummy->next = this->dummy;
    this->dummy->prev = this->dummy;
    size = 0;
}

template<class T>
T Deque<T>::get(int index) {
    auto node = find_node(index);
    return node->data;
}

template<class T>
void Deque<T>::insert(T data, int index) {
    auto prev_node = this->find_node(index - 1);
    this->insert_after(prev_node, data);
    this->size++;
}

template<class T>
void Deque<T>::push_back(T data) {
    auto last_node = this->find_node(size - 1);
    this->insert_after(last_node, data);
    this->size++;
}

template<class T>
void Deque<T>::push_front(T data) {
    this->insert_after(this->dummy, data);
    this->size++;
}

template<class T>
T Deque<T>::pop_front() {
    auto first_node = dummy->next;
    if (first_node == dummy) {
        throw "you can't pop from empty list";
    }
    T data = first_node->data;
    dummy->next = first_node->next;
    first_node->next->prev = dummy;
    delete first_node;
    this->size--;
    return data;
}

template<class T>
T Deque<T>::pop_back() {
    auto last_node = dummy->prev;
    if (last_node == dummy) {
        throw "you can't pop from empty list";
    }
    T data = last_node->data;
    dummy->prev = last_node->prev;
    last_node->prev->next = dummy;
    delete last_node;
    this->size--;
    return data;
}

template<class T>
Node<T> *Deque<T>::insert_after(Node<T> *prev_node, T new_data) {
    auto *new_node = new Node<T>(new_data);
    if (prev_node == nullptr) {
        throw "the given previous node cannot be null";
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    new_node->next->prev = new_node;
    return new_node;
}

template<class T>
Node<T> *Deque<T>::find_node(int index) {
    auto current_node = dummy;
    int i = -1;
    while (i < index) {
        current_node = current_node->next;
        i++;
    }
    return current_node;
}

#endif ////DEQUE_IMPL
