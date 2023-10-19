#include <iostream>

using namespace std;

void foo(int &num) {

  num = num + 1;
  
  cout << "In foo, num is " << num << endl;
}

int main() {
  int val = 3;
  
  cout << "Start of main, val is " << val << endl;
  
  foo(val);
  
  cout << "End of main, val is " << val << endl;

  return 0;
}

