#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // step 0: variables
  double
    a,b,c,	// coefficients of quadratic equation
    x1,x2;	// roots of equation

  // step 1: input a, b, c
  cout << "Enter value for a: ";
  cin >> a;
  
  cout << "Enter value for b: ";
  cin >> b;
  
  cout << "Enter value for c: ";
  cin >> c;
  
  // step 2a: calculate (+)
  x1 = (-b + sqrt(b*b - 4*a*c)) / (2 * a);
  
  // step 2b: calculate (-)
  x2 = (-b - sqrt(b*b - 4*a*c)) / (2 * a);
  
  // step 3: output x1 and x2
  cout << "The roots are " << x1
       << " and " << x2 << endl;

  // all done
  return 0;	// end function, give back a 0 value
}

