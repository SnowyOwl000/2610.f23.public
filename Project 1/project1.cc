#include <iostream>

using namespace std;

int main() {
  // step 0: variables
  char
    input,
    current = '#';	// current location in diagram
    			// called "ch" in algorithm
    			
  // step 0.5: prompt
  cout << "Enter Morse code: ";
  
  // step 1: loop over all input characters
  do {
  
    // step 1.1: get an input char
    cin >> input;
    
    // step 1.2: if input is ., move left one link
      // will need a switch statement or if-else-if here
    
    // step 1.3: if input is -, move right one link
      // will need a switch statement or if-else-if here
    
    // step 1.4: if input is =, output current and reset
      // output current
      // set current to #
    
    // step 1.5 if input is #, output current, a space and reset
      // output current and a space
      // set current to #
  
  // end loop
  } while (input != '/');

  // all done!
  return 0;
}

