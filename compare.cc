#include <iostream>

using namespace std;

int main() {
  float
    val1 = 16777216.0,
    val2 = 16777215.0;
    
  val1 = val1 + 1.0;
  val2 = val2 + 1.0;
  
  if (val1 == 16777218.0)
    cout << "They are equal" << endl;
  else
    cout << "They are not equal" << endl;
    
  if (val2 == 16777216.0)
    cout << "They are equal" << endl;
  else
    cout << "They are not equal" << endl;
    
  return 0;
}

