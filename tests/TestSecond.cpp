// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include <Second.hpp>

TEST(Stack2, CorrectPrimitive) {
  Stack2<int> stack;
  stack.push(10);
  int value1 = 15, value2 = 33;
  stack.PushEmplace(value1);
  EXPECT_EQ(value1, stack.pop());
  EXPECT_EQ(10, stack.head());
  stack.PushEmplace(value2);
  EXPECT_EQ(value2, stack.head());
  stack.push(1200);
  EXPECT_EQ(1200, stack.head());
}

class MyClass {
 public:
  MyClass() {
    value1 = 0;
    value2 = 0.1;
    value3 = "0";
  }
  MyClass(int a, double b, string c){
    value1 = a;
    value2 = b;
    value3 = c;
  }
  int value1;
  double value2;
  std::string value3;
};

TEST(Stack2, CorrectMyClass) {
  Stack2<MyClass> stack;
  MyClass MyClass1;
  MyClass MyClass2(15, 1.1, "1");
  stack.PushEmplace(MyClass1);
  EXPECT_EQ(MyClass1.value2, stack.head().value2);
  EXPECT_EQ(MyClass1.value3, stack.head().value3);
  EXPECT_EQ(MyClass1.value1, stack.head().value1);
  stack.PushEmplace(MyClass2);
  EXPECT_EQ(MyClass2.value2, stack.head().value2);
  EXPECT_EQ(MyClass2.value3, stack.head().value3);
  EXPECT_EQ(MyClass2.value1, stack.pop().value1);
  EXPECT_EQ(MyClass1.value2, stack.head().value2);
  EXPECT_EQ(MyClass1.value3, stack.head().value3);
  EXPECT_EQ(MyClass1.value1, stack.head().value1);
}

TEST(Stack2, emplace) {
  Stack2<MyClass> stack;
  int value1 = 5;
  double value2 = 5.5;
  string value3 = "Hi";
  stack.PushEmplace(100, 10.1, "102");
  stack.PushEmplace(value1, value2, value3);
  EXPECT_EQ(value1, stack.head().value1);
  EXPECT_EQ(value2, stack.head().value2);
  EXPECT_EQ(value3, stack.pop().value3);
  EXPECT_EQ(100, stack.head().value1);
  EXPECT_EQ(10.1, stack.head().value2);
  EXPECT_EQ("102", stack.head().value3);
}

TEST(Stack2, type_traits) {
  EXPECT_TRUE(std::is_move_constructible<int>::value);
  EXPECT_TRUE(std::is_move_assignable<int>::value);
  EXPECT_TRUE(std::is_move_constructible<MyClass>::value);
  EXPECT_TRUE(std::is_move_assignable<MyClass>::value);
}