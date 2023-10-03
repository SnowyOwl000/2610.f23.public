#include <iostream>

using namespace std;

int main() {
  int32_t
    sum=0,
    count=0,
    score;
  double
    average;
    
  cout << "Enter score (-1 to quit): ";
    
  cin >> score;
    
  while (score != -1) {
    sum += score;	// same as sum = sum + score
    
    count++;

    cout << "Enter score (-1 to quit): ";
    
    cin >> score;
  }
  
  average = sum / (double)count;
  
  cout << "Average: " << average << endl;
  
  return 0;
}

