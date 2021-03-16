#include <gtest/gtest.h>
#include <First.hpp>

TEST(Example, EmptyTest) {
  EXPECT_TRUE(true);
}

TEST(Stack1, CorrectPrimitive) {
  Stack1<int> stack;
  stack.push(10);
  int value1 = 15, value2 = 33;
  stack.push(value1);
  EXPECT_EQ(value1, stack.head());
  stack.pop();
  EXPECT_EQ(10, stack.head());
  stack.push(value2);
  EXPECT_EQ(value2, stack.head());
  stack.push(1200);
  EXPECT_EQ(1200, stack.head());
}

class MyClass {
 public:

  MyClass(){
    value1 = 0;
    value2 = 0.1;
    value3 = "0";
  }
  int value1;
  double value2;
  std::string value3;
};

TEST(Stack1, CorrectMyClass) {
  Stack1<MyClass> stack;
  MyClass MyClass1;
  MyClass MyClass2;
  MyClass2.value1 = 15;
  MyClass2.value3 = "1";
  MyClass2.value2 = 1.1;
  stack.push(MyClass1);
  EXPECT_EQ(MyClass1.value2, stack.head().value2);
  EXPECT_EQ(MyClass1.value3, stack.head().value3);
  EXPECT_EQ(MyClass1.value1, stack.head().value1);
  stack.push(MyClass2);
  EXPECT_EQ(MyClass2.value2, stack.head().value2);
  EXPECT_EQ(MyClass2.value3, stack.head().value3);
  EXPECT_EQ(MyClass2.value1, stack.head().value1);
  stack.pop();
  EXPECT_EQ(MyClass1.value2, stack.head().value2);
  EXPECT_EQ(MyClass1.value3, stack.head().value3);
  EXPECT_EQ(MyClass1.value1, stack.head().value1);
}

TEST(Stack1, type_traits) {
  EXPECT_TRUE(std::is_move_constructible<int>::value);
  EXPECT_TRUE(std::is_move_assignable<int>::value);
  EXPECT_TRUE(std::is_move_constructible<MyClass>::value);
  EXPECT_TRUE(std::is_move_assignable<MyClass>::value);
}