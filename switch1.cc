#include <iostream>

using namespace std;

int main() {
  int
    choice;
    
  cout << "Options:\n\n"
  	"1. This.\n"
  	"2. That.\n"
  	"3. The other.\n\n"
  	"Enter your choice: ";
  	
  cin >> choice;
  
  switch (choice) {
    case 1: cout << "You chose this." << endl;
    
    case 2: cout << "You chose that." << endl;
            break;
            
    case 3: cout << "Now for something completely different" << endl;
  }
  
  return 0;
}
