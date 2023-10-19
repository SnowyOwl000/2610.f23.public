#include <iostream>

using namespace std;

int main() {
  char
    choice;
    
  cout << "Options:\n\n"
  	"A. Alpha.\n"
  	"B. Bravo.\n"
  	"C. Charlie.\n\n"
  	"Enter your choice: ";
  	
  cin >> choice;
  
  switch (choice) {
    case 'a':  
    case 'A': cout << "You chose option A." << endl;
    	      break;
    	     
    case 'b': 
    case 'B': cout << "You chose option B." << endl;
              break;
            
    case 'c':
    case 'C': cout << "You chose option C." << endl;
              break;

    default: cout << "Now for something completely different" << endl;
  }
  
  return 0;
}
