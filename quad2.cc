#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // step 0: variables
  double
    a,b,c,	// coefficients of quadratic equation
    d,		// discriminant... b^2 - 4ac
    x1,x2;	// roots of equation

  // step 1: input a, b, c
  cout << "Enter value for a: ";
  cin >> a;
  
  cout << "Enter value for b: ";
  cin >> b;
  
  cout << "Enter value for c: ";
  cin >> c;
  
  // step 2: calculate d
  d = b * b - 4 * a * c;
  
  if (a == 0) {
    if (b == 0) {
    	// a == 0, b == 0
      cout << "Error: a and b cannot both be zero" << endl;
    } else {
    	// a == 0, b != 0, linear equation
    	x1 = -c / b;
    	cout << "Linear equation, root is " << x1 << endl;
    }
  } else if (d < 0) {
    // complex conjugate roots
    double
      re,im;		// real and imaginary parts of complex number
      
    re = -b / (2 * a);
    im = sqrt(-d) / (2 * a);
    
    cout << "Complex roots: " << re << " + " << im << "i and "
         << re << " - " << im << 'i' << endl;
  } else if (d == 0) {
    // double root
    x1 = -b / (2 * a);
    cout << "Double root: " << x1 << endl;
  } else {
    // d > 0, "normal" case
    x1 = (-b + sqrt(b*b - 4*a*c)) / (2 * a);
    x2 = (-b - sqrt(b*b - 4*a*c)) / (2 * a);

    cout << "The roots are " << x1
         << " and " << x2 << endl;
  }
  
  // all done
  return 0;	// end function, give back a 0 value
}

