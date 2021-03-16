#include <Second.hpp>
int main() {
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
    string value3;
  };

  Stack2<int> stack1;
  stack1.push(10);
  int value1 = 15;
  stack1.PushEmplace(value1);
  cout << stack1.pop() << "\n";
  cout << stack1.head() << "\n";
}