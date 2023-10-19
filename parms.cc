#include <iostream>

using namespace std;

int main(int argc,char *argv[]) {

  cout << "Number of command-line arguments: " << argc << endl;
  cout << "Argument list:" << endl;
  
  for (int i=0;i<argc;i++)
    cout << '[' << argv[i] << ']' << endl;
    
  return 0;
}

