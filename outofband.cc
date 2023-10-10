#include <iostream>

using namespace std;

int main() {
  int
    sum = 0,
    score;
    
  while (true) {
    cout << "Enter a score: ";
    cin >> score;
    
    if (!cin)		// out-of-band check
      break;		// if cin fails, stop the loop
    
    sum = sum + score;
  }
  
  cout << "\nSum is " << sum << endl;
  
  return 0;
}
