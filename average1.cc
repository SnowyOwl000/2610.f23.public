#include <iostream>

using namespace std;

int main() {
  int32_t
    sum=0,
    count=0,
    score;
  double
    average;
    
  while (score != -1) {
    cout << "Enter score (-1 to quit): ";
    
    cin >> score;
    
    sum += score;	// same as sum = sum + score
    
    count++;
  }
  
  average = sum / count;
  
  cout << "Average: " << average << endl;
  
  return 0;
}

