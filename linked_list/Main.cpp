#include <iostream>

using namespace std;

template <typename T> class Node {
private:
public:
  T data;
  Node<T> *next;

  Node(int data) : data(data), next(nullptr){};

  T getData() { return data; }
};

template <typename T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;

public:
  LinkedList() : head(nullptr), tail(nullptr){};

  ~LinkedList() {
    Node<T> *current = head;
    Node<T> *next;

    while (current) {
      next = current->next;
      delete current;
      current = next;
    }
  }

  Node<T> &getHead() { return *head; }
  Node<T> &getTail() { return *tail; }

  void append(const T data) {
    if (!head) {
      head = new Node<T>(data);
      tail = head;
    } else {
      Node<T> *node = new Node<T>(data);
      tail->next = node;
      tail = node;
    }
  };

  void prepend(const T data) {
    if (!head) {
      head = new Node<T>(data);
      tail = head;
    } else {
      Node<T> *node = new Node<T>(data);
      node->next = head;
      head = node;
    }
  };

  void printList() const {
    Node<T> *iter = head;
    while (iter) {
      cout << iter->data << '\n';
      iter = iter->next;
    }
  }

  void removeFront() {
    Node<T> *target = head;
    head = head->next;
    delete target;
  }

  void insert(const T data) {
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
};

int main() {
  LinkedList<int> *list = new LinkedList<int>();

  list->prepend(100);
  list->append(300);
  list->prepend(200);
  list->insert(1000);
  list->insert(0);

  list->printList();

  delete list;
}
