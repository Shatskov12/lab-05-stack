// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include <Second.hpp>

TEST(Stack2, correct_primitive) {
  Stack2<int> stack;
  stack.push(10);
  int value1 = 15, value2 = 33;
  stack.push_emplace(value1);
  EXPECT_EQ(value1, stack.pop());
  EXPECT_EQ(10, stack.head());
  stack.push_emplace(value2);
  EXPECT_EQ(value2, stack.head());
  stack.push(1200);
  EXPECT_EQ(1200, stack.head());
}

class My_class {
 public:
  My_class() {
    value1 = 0;
    value2 = 0.1;
    value3 = "0";
  }
  My_class(int a, double b, std::string c){
    value1 = a;
    value2 = b;
    value3 = c;
  }
  int value1;
  double value2;
  std::string value3;
};

TEST(Stack2, correct_my_class) {
  Stack2<My_class> stack;
  My_class my_class1;
  My_class my_class2(15, 1.1, "1");
  stack.push_emplace(my_class1);
  EXPECT_EQ(my_class1.value2, stack.head().value2);
  EXPECT_EQ(my_class1.value3, stack.head().value3);
  EXPECT_EQ(my_class1.value1, stack.head().value1);
  stack.push_emplace(my_class2);
  EXPECT_EQ(my_class2.value2, stack.head().value2);
  EXPECT_EQ(my_class2.value3, stack.head().value3);
  EXPECT_EQ(my_class2.value1, stack.pop().value1);
  EXPECT_EQ(my_class1.value2, stack.head().value2);
  EXPECT_EQ(my_class1.value3, stack.head().value3);
  EXPECT_EQ(my_class1.value1, stack.head().value1);
}

TEST(Stack2, emplace) {
  Stack2<My_class> stack;
  int value1 = 5;
  double value2 = 5.5;
  string value3 = "Hi";
  stack.push_emplace(100, 10.1, "102");
  stack.push_emplace(value1, value2, value3);
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
  EXPECT_TRUE(std::is_move_constructible<My_class>::value);
  EXPECT_TRUE(std::is_move_assignable<My_class>::value);
}