template <typename T> class Node {
private:
public:
  T data;
  Node<T> *next;
  Node(T data) : data(data), next(nullptr){};
};
