#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char
    str1[64],
    str2[64];

  cout << "Enter two words: ";
  cin >> str1 >> str2;
  
  // this is not what you want! You are comparing locations of the arrays here
  cout << "This is the bad version here..." << endl;
  if (str1 < str2)
    cout << "str1 comes first asciibetically" << endl;
  else if (str1 > str2)
    cout << "str2 comes first asciibetically" << endl;
  else
    cout << "words are the same" << endl;
    
  cout << "str1 is at location " << (void *)str1 << endl;  
  cout << "str2 is at location " << (void *)str2 << endl;  
  
  // this is what you want
  cout << "\nThis is the good version..." << endl;
  if (strcmp(str1,str2) < 0)
    cout << "str1 comes first asciibetically" << endl;
  else if (strcmp(str1,str2) > 0)
    cout << "str2 comes first asciibetically" << endl;
  else
    cout << "words are the same" << endl;
  
  return 0;
}

