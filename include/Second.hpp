

#ifndef LAB_05_STACK_STACK2_H
#define LAB_05_STACK_STACK2_H
#include <memory>
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::forward;

template <typename T>
class Node
{
 public:
  Node(T a = T(), Node<T> *b = nullptr) {
    data = a;
    pPast = b;
  }

  const T& GetData(){return data;}

  Node<T>*& GetPointerPast(){return pPast;}
 private:
  Node<T> *pPast;
  T data;
};

template <typename T>
class Stack2
{
 public:
  template <typename ... Args>
  void push_emplace(Args&&... value){
    if (!pHead){
      pHead = new Node<T>(T(forward<Args>(value)...));
    } else {
      pHead = new Node<T>(T(forward<Args>(value)...), pHead);
    }
  }
  void push(T&& value){
    if (!pHead){
      pHead = new Node<T>(forward<T>(value));
    } else {
      pHead = new Node<T>(forward<T>(value), forward<Node<T>*>(pHead));
    }
  };
  const T& head() const{return pHead->GetData();};
  T pop(){
    Node<T> *pTemp = pHead->GetPointerPast();
    T out = pHead->GetData();
    delete pHead;
    pHead = pTemp;
    return out;
  };

  Stack2(){pHead = nullptr;}
  Stack2(const Stack2&) = delete;
  Stack2 operator=(const Stack2&) = delete;
  ~Stack2(){
    while (pHead){
      pop();
    }
  }

 private:
  Node<T> *pHead;
};
#endif  // LAB_05_STACK_STACK2_H