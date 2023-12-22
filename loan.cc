#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  // step 0: variables
  double
    pv,		// amount of loan
    rate,	// interest rate per period
    nPmts,	// number of payments
    pmt,	// payment
    apr;	// APR
    
  // step 0.5: configure output for 2 decimal places
  cout << fixed << setprecision(2);
  
  // step 1: input values for pv, apr, nPmts
  cout << "Enter loan amount: ";
  cin >> pv;
  
  cout << "Enter APR (5.25% = 5.25): ";
  cin >> apr;
  
  cout << "Enter number of payments: ";
  cin >> nPmts;
  
  // step 2: calculate
  // step 2.1: calculate rate
  rate = apr * 0.01 / 12;
  // rate = apr / 1200;
  
  // step 2.2: calculate pmt
  pmt = (rate * pv) / (1 - pow(1 + rate,-nPmts));
  
  // step 3: output result
  cout << "Payment: $" << pmt << endl;

  // all done
  return 0;
}

