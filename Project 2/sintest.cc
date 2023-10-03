#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double
  TOL = 1e-12;		// 1.0 x 10^(-12)

int main() {
  double
    x = 0.5,
    term,
    d,
    yOld,yNew,
    realSin;
  bool
    okay=true;
  
  for (x=-M_PI/2.0;x<=M_PI/2.0;x+=0.0000001) {  
    term = x;
    d = 2;
    yNew = 0;
  
    do {
      yOld = yNew;
    
      yNew = yNew + term;
    
      term = -term * x * x / (d * (d+1));
    
      d += 2;
    } while (yOld != yNew);
    
    realSin = sin(x);	// cmath's sin
    
    if (fabs(realSin - yNew) > TOL)
      okay = false;
  }

  if (okay)
    cout << "Tests pass" << endl;
  else
    cout << "Tests fail" << endl;  
    
  return 0;
}

