// note: to see an error message, rename foo.dat to something else

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream
    inFile;
  string
    str;
    
  // step 1: open file
  inFile.open("foo.dat");
  
  // step 2: make sure open worked
//  if (!inFile) {
//  if (inFile.fail()) {
  if (!inFile.is_open()) {
 //   cout << "Open failed" << endl;
    perror("open");
    return 1;
  }
    
  // step 3: use the file
  inFile >> str;
  cout << "String is [" << str << ']' << endl;
  
  // step 4: close the file
  inFile.close();
  
  return 0;
}

