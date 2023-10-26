#include <iostream>

using namespace std;

void foo() {
  static int val=5;
  
  cout << "Start of foo, val is " << val << endl;
  
  val = 3;
  
  cout << "End of foo, val is " << val << endl;
  
  cout << "val is at location " << &val << endl;
}

int main() {

  foo();
  cout << "in between calls to foo" << endl;
  foo();
  
  return 0;
}

