#include <iostream>

using namespace std;

int main() {
  float
    big = 1,
    small = 1;
    
  for (int i=0;i<50;i++) {
    cout << "big: " << big << "        small: " << small << endl;
    big = big * 10;	// big *= 10;
    small = small / 10;
  }
  
  return 0;
}

