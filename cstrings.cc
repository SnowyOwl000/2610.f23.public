#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char
    str1[64]="This is a test",
    *str2;
    
  // example of shallow copy
    
  str2 = str1;
  
  cout << "str2 is [" << str2 << ']' << endl;
  
  cout << "str1 is at location " << (void *)str1 << endl;
  cout << "str2 points to location " << (void *)str2 << endl;
  
  str1[0] = '#';
  
  cout << str2 << endl;
  
  str1[0] = 'T';
  
  // regular (deep) copy
  
  char
    str3[64];
    
  strcpy(str3,str1);	// C-string for "str3 = str1"
  
  cout << "str3 is [" << str3 << ']' << endl;
  
  return 0;
}

