#include "Node.h"
#include <exception>
#include <iostream>

#pragma once

using namespace std;

template <typename T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;

public:
  LinkedList();
  ~LinkedList();

  Node<T> &getHead() const;
  Node<T> &getTail() const;

  void append(const T);

  void prepend(const T);

  void printList() const;

  void removeFront();

  void insert(const T);

  bool remove(const T);

  bool find(const T);
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr){};

template <typename T> LinkedList<T>::~LinkedList() {
  Node<T> *current = head;
  Node<T> *next;

  while (current) {
    next = current->next;
    delete current;
    current = next;
  }
}

template <typename T> void LinkedList<T>::append(const T data) {
  if (!head) {
    head = new Node<T>(data);
    tail = head;
  } else {
    Node<T> *node = new Node<T>(data);
    tail->next = node;
    tail = node;
  }
}

template <typename T> void LinkedList<T>::prepend(const T data) {
  if (!head) {
    head = new Node<T>(data);
    tail = head;
  } else {
    Node<T> *node = new Node<T>(data);
    node->next = head;
    head = node;
  }
}

template <typename T> void LinkedList<T>::printList() const {
  Node<T> *iter = head;
  while (iter) {
    cout << iter->data << '\n';
    iter = iter->next;
  }
}

template <typename T> void LinkedList<T>::removeFront() {
  Node<T> *target = head;
  head = head->next;
  delete target;
}

template <typename T> void LinkedList<T>::insert(const T data) {
  // If list doesn't exist or data is smaller than every element
  if (!head || data <= head->data) {
    prepend(data);
    return;
  }

  Node<T> *current = head;

  while (current->next) {
    if (data <= current->next->data) {
      Node<T> *temp = current->next;
      current->next = new Node<T>(data);
      current->next->next = temp;
      if (!temp->next)
        tail = temp;
      return;
    }

    current = current->next;
  }

  // If data is greater than every element
  current->next = new Node<T>(data);
  tail = current->next;
}

template <typename T> bool LinkedList<T>::remove(const T data) {
  if (!head)
    return false;

  if (head->data == data) {
    Node<T> *temp = head->next;
    delete head;
    head = temp;
    return true;
  }

  Node<T> *current = head;

  while (current->next) {
    if (current->next->data == data) {
      Node<T> *temp = current->next;

      current->next = temp->next;

      if (temp == tail)
        tail = current;

      delete temp;

      return true;
    }
    current = current->next;
  }

  return false;
}

template <typename T> bool LinkedList<T>::find(const T data) {
  Node<T> *current = head;
  while (current) {
    if (current->data == data) {
      return true;
    }
    current = current->next;
  }
  return false;
}

template <typename T> Node<T> &LinkedList<T>::getHead() const { return *head; }

template <typename T> Node<T> &LinkedList<T>::getTail() const { return *tail; }
