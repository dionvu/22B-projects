/**
 * @file LinkedList.h
 * @brief Declaration of a template class representing a singly linked list.
 * This class provides basic operations such as insertion, deletion,
 * and searching within the linked list.
 */

#include "Node.h"
#include <iostream>

#pragma once

using namespace std;

/**
 * @brief A template class representing a singly linked list.
 *
 * @tparam T The type of data stored in the list.
 */
template <typename T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;

public:
  /**
   * @brief Constructs a new LinkedList object.
   */
  LinkedList();

  /**
   * @brief Destroys the LinkedList object.
   */
  ~LinkedList();

  /**
   * @brief Gets the data of the first element in the list.
   *
   * @return T The data of the first element.
   */
  T getFirst() const;

  /**
   * @brief Gets the data of the last element in the list.
   *
   * @return T The data of the last element.
   */
  T getLast() const;

  /**
   * @brief Appends a new element with the given data to the end of the list.
   *
   * @param data The data of the element to be appended.
   */
  void append(const T);

  /**
   * @brief Prepends a new element with the given data to the beginning of the
   * list.
   *
   * @param data The data of the element to be prepended.
   */
  void prepend(const T);

  /**
   * @brief Prints the elements of the list.
   */
  void printList() const;

  /**
   * @brief Removes the first element from the list.
   */
  void removeFront();

  /**
   * @brief Inserts a new element with the given data into the list.
   *
   * @param data The data of the element to be inserted.
   */
  void insert(const T);

  /**
   * @brief Removes the first occurrence of the given data from the list.
   *
   * @param data The data of the element to be removed.
   * @return true If the element was found and removed.
   * @return false If the element was not found.
   */
  bool remove(const T);

  /**
   * @brief Searches for the given data in the list.
   *
   * @param data The data to search for.
   * @return true If the data is found in the list.
   * @return false If the data is not found in the list.
   */
  bool find(const T) const;

  /**
   * @brief Checks if the list is empty.
   *
   * @return true If the list is empty.
   * @return false If the list is not empty.
   */
  bool isEmpty() const;
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
template <typename T> T LinkedList<T>::getFirst() const { return head->data; }

template <typename T> T LinkedList<T>::getLast() const { return tail->data; }

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
    cout << iter->data;
    iter = iter->next;
  }
}

template <typename T> void LinkedList<T>::removeFront() {
  Node<T> *target = head;
  head = head->next;
  delete target;
}

template <typename T> void LinkedList<T>::insert(const T data) {
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

      if (temp == head)
        head = current;

      delete temp;

      return true;
    }
    current = current->next;
  }

  return false;
}

template <typename T> bool LinkedList<T>::find(const T data) const {
  Node<T> *current = head;
  while (current) {
    if (current->data == data)
      return true;
    current = current->next;
  }
  return false;
}

template <typename T> bool LinkedList<T>::isEmpty() const {
  return head == nullptr;
}
