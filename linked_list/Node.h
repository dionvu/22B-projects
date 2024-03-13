template <typename T> class Node {
private:
public:
  T data;
  Node<T> *next;
  Node(int data) : data(data), next(nullptr){};
};
