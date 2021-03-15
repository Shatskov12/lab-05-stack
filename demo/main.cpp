#include <Second.hpp>
int main() {
  class My_class {
   public:
    My_class() {
      value1 = 0;
      value2 = 0.1;
      value3 = "0";
    }
    My_class(int a, double b, string c){
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
  stack1.push_emplace(value1);
  cout << stack1.pop() << "\n\n";
  cout << stack1.head() << "\n\n";
}