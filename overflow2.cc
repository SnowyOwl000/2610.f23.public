#include <iostream>

using namespace std;

int main() {
  
  int
    n = 2147483647;
    
  cout << n << endl;
  
  n = n + 1;
  
  cout << n << endl;
    
  n = n - 1;
  
  cout << n << endl << endl;
  
  unsigned int
    j = 0;
    
  cout << j << endl;
  
  j -= 1;
  
  cout << j << endl;
  
  j += 1;
  
  cout << j << endl;
    
  return 0;
}

