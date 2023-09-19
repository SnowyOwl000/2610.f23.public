#include <iostream>
#include <cmath>

using namespace std;

const float
  TOL = 1e-6;		// tolerance; anything smaller than this is assumed to be 0

int main() {
  float
    x = 1.0 / 10.0;

  cout << "Raw comparison: ";    
  if (x - 0.1 == 0.0)
    cout << "Equal" << endl;
  else
    cout << "Not equal" << endl;
    
  cout << "With tolerance: ";
  if (fabs(x - 0.1) < TOL)		// right way to compare real #s to 0
    cout << "Equal" << endl;
  else
    cout << "Not equal" << endl;
    
  cout << "Actual value: " << x - 0.1 << endl;
  
  return 0;
}

