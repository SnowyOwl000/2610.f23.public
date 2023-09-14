#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  int
    n = 12345,
    j = -67890;
    
  cout << '|' << n << '|' << j << '|' << endl;
  cout << '|' << setw(10) << n << '|' << j << '|' << endl << endl;
  
  cout << '|' << "This" << '|' << "is a test" << '|' << endl;
  cout << '|' << setw(10) << "This" << '|' << "is a test" << '|' << endl;
  cout << '|' << "This" << '|' << setw(5) << "is a test" << '|' << endl << endl;
  
  cout << '|' << M_PI << '|' << setw(15) << M_PI << '|' << endl;
  cout << M_PI << "   " << M_E << endl;
  cout << setprecision(10) << M_PI << "   " << M_E << endl;
  cout << setprecision(40) << M_PI << endl;
  cout << setprecision(3) << M_PI << endl;
  cout << endl;
  
  cout << fixed << setprecision(10) << setprecision(5);
  cout << M_PI << "   " << M_E << endl;
  cout << showpoint << 1.0 << endl;
  
  /*
  int
    a=0,b=1,f;
    
  for (int i=0;i<20;i++) {
    f = a + b;
    cout << setw(5) << f << endl;
    
    a = b;
    b = f;
  }
  */
  
  
  return 0;
}

