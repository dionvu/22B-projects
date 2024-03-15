#pragma once

/**
 * @file Node.h
 * @brief A template class representing a node in a singly linked list.
 */
template <typename T> class Node {
private:
public:
  T data;
  Node<T> *next;

  /**
   * @brief Constructs a new Node object with given data and a nullptr next
   * pointer.
   *
   * @param data The data to be stored in the node.
   */
  Node(T data) : data(data), next(nullptr){};
};
