#include <iostream>

using namespace std;

int main() {
  int
    data[] = {17,31,33,69,256,12,1,13,0,-50,7,270270,35};
  const int
    N_ITEMS = sizeof(data) / sizeof(data[0]);
    
  int
    guess = 0;		// position of largest element
    
  for (int i=1;i<N_ITEMS;i++)	// scan through all other elements
    if (data[i] > data[guess])	// is my last guess wrong?
      guess = i;		// yes? change the guess
      
  cout << "Largest element is in position " << guess << endl;
  cout << "Largest element is " << data[guess] << endl;
  
  return 0;
}

