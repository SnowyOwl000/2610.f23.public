#include <iostream>

using namespace std;

int main() {
  int32_t
    sum=0,
    count=0,
    score;
  double
    average;
    
  while (true) {
    cout << "Enter score (-1 to quit): ";
    
    cin >> score;
    
    if (score == -1)
      break;

    sum += score;	// same as sum = sum + score
    
    count++;
  }
  
  average = sum / (double)count;
  
  cout << "Average: " << average << endl;
  
  return 0;
}

