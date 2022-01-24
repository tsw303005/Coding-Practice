#include <iostream>

using namespace std;

template <class T>
class Node {
private:
  
public:
  Node(T data);
  T data;
  Node *next;
};

template <typename T>
Node<T>::Node(T data) {
  this->data = data;
  this->next = nullptr;
}

template <class T>
class circular_buffer {
private:
  int capatcity;
  int len;
  Node<T> *head;
  Node<T> *tail;
public:
  circular_buffer(int cap);
  void push_back(T data);
  void pop_front();
  int size();
  T &operator[](int i);
};

template <typename T>
circular_buffer<T>::circular_buffer(int cap) {
  this->capatcity = cap;
  this->head = nullptr;
  this->tail = nullptr;
  this->len = 0;
}

template <typename T>
int circular_buffer<T>::size() {
  return this->len;
}

template <typename T>
void circular_buffer<T>::push_back(T data) {
  //cout << "now len = " << this->len << endl;
  if (this->capatcity == 0) return ;
  if (this->head == nullptr) {
    this->head = new Node<T>(data);
    this->tail = this->head;
    this->len = 1;
  } else if (this->len < this->capatcity) {
    this->tail->next = new Node<T>(data);
    this->tail = this->tail->next;
    this->len += 1;
  } else {
    this->tail->next = new Node<T>(data);
    Node<T> *del = this->head;
    this->head = this->head->next;
    this->tail = this->tail->next;
    delete del;
  }
}

template <typename T>
void circular_buffer<T>::pop_front() {
  if (this->len == 0) return ;
  else if (this->len == 1) {
    delete this->head;
    this->head = this->tail = nullptr;
    this->len = 0;
  } else {
    Node<T> *del = this->head;
    this->head = this->head->next;
    delete del;
    this->len -= 1;
  }
}


template <typename T>
T& circular_buffer<T>::operator[](int i) {
  Node<T>* cur = this->head;
  for (int j = 0; j < i; j++) {
    cur = cur->next;
  }
  return cur->data;
}


int main()
{
    int capacity;
    cin >> capacity;
    circular_buffer<int> cbi(capacity);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if(cmd == "push_back") {
            int data;
            cin >> data;
            cbi.push_back(data);
        } else if(cmd == "pop_front") {
            cbi.pop_front();
        } else if(cmd=="print") {
            for(int j = 0; j < cbi.size(); j++) {
                cout << cbi[j] << endl;
            }
            cout << "----" << endl;
        }
    }
    return 0;
}