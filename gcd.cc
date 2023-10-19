#include <iostream>

using namespace std;

int64_t gcd(int64_t a,int64_t b) {
  int64_t
    r;
    
  // step 0: a and b cannot be negative
  if (a < 0)		// flip the sign if negative
    a = -a;		// here's one way to do that
    
  b = (b < 0) ? -b : b;	// here's another way
  
  // repeat until b is 0
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  
  return a;
}

int main(int argc,char *argv[]) {

  if (argc != 3) {
    cout << "Usage: " << argv[0] << " number1 number2" << endl;
    return 1;
  }
    
  int val1 = atoi(argv[1]);
  int val2 = atoi(argv[2]);
    
  int64_t ans = gcd(val1,val2);
  
  cout << "gcd is " << ans << endl;
    
  return 0;
}

