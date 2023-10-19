#include <iostream>

using namespace std;

int main() {
  int
    val = 1;
    
  // don't try this at home!
  
  cout << (val++ + val++) << endl;	// Don't do this.
  
  val = 1;
  cout << (++val + ++val) << endl;	// Never do this.
  
  return 0;
}

