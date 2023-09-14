#include <iostream>

using namespace std;

int main() {
  double
    x = 1.0 / 0.0;
    
  cout << x << endl;
  
  x = -1.0 / 0.0;
  
  cout << x << endl;
  
  x = 0.0 / 0.0;
  
  cout << x << endl;
  
  int
    n = 0;
    
  n = 2 / n;
    
  cout << n << endl;
  
  return 0;
}

