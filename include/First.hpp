// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_FIRST_HPP_
#define INCLUDE_FIRST_HPP_
#include <memory>
#include <iostream>
#include <string>
#include <utility>

using std::move;

template <typename T>
class Node
{
 public:
  explicit Node(T a = T(), Node<T> *b = nullptr) {
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
class Stack1
{
 public:
  void push(T&& value){
    if (!pHead){
      pHead = new Node<T>(move(value));
    } else {
      pHead = new Node<T>(move(value), move(pHead));
    }
  }
  void push(const T& value) {
    if (!pHead){
      pHead = new Node<T>(value);
    } else {
      pHead = new Node<T>(value, pHead);
    }
  }
  void pop(){
    Node<T> *pTemp = pHead->GetPointerPast();
    delete pHead;
    pHead = pTemp;
  }
  const T& head() const{return pHead->GetData();}

  Stack1(){pHead = nullptr;}
  Stack1(const Stack1&) = delete;
  Stack1 operator=(const Stack1&) = delete;
  ~Stack1(){
    while (pHead){
      pop();
    }
  }

 private:
  Node<T> *pHead;
};

#endif // INCLUDE_FIRST_HPP_