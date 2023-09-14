#include <iostream>

using namespace std;

int main() {
  string
    name;
    
  cout << "Enter your name: ";
  cin >> name;
  
  cout << "Hello, " << name << endl;
  
  cin.ignore(80,'\n');
  
  cout << "Try again: ";
  getline(cin,name);
  
  cout << "Hello, " << name << endl;
  
  return 0;
}

