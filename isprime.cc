#include <iostream>

using namespace std;

bool isPrime(int64_t n) {

  // if n < 2, then it is not prime
  if (n < 2)
    return false;
    
  // if n == 2, then it is prime
  if (n == 2)
    return true;
    
  // if n is even, then it is not prime
  if (n % 2 == 0)
    return false;
    
  for (int64_t f=3;f*f<=n;f+=2)
    if (n % f == 0)
      return false;
      
  return true;
}

int main(int argc,char *argv[]) {

  if (argc != 2) {
    cout << "Usage: " << argv[0] << " number" << endl;
    return 1;
  }
    
  int val1 = atoi(argv[1]);
    
  if (isPrime(val1))
    cout << val1 << " is prime" << endl;
  else
    cout << val1 << " is not prime" << endl;
    
  return 0;
}

