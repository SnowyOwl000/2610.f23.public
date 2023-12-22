#include <iostream>

using namespace std;

int main() {
   //step 0: variables
   char
   input,
   current = '#';   // current location in diagram
                    // called "ch" in algorithm

   // step 1 loop over all input characters
      cout << "Enter Morse Code: ";
   do {
   
      // step 1.1: get an input char
      cin >> input;
      
      // step 1.2 if input is ., move left one link
      if (input == '.') {
         // ^ if value of input is a . proform the brackets. not not skip bracket data
        // will need a swtich statement or if-else-if here
        if (current == '#') 
          current = 'E';
        else if (current == 'E')
          current = 'I';
        else if (current == 'I')
          current = 'S';
        else if (current == 'S')
          current = 'H';
        else if (current == 'H')
          current = '5';
        else if (current == 'U')
          current = 'F';
        else if (current == 'A')
          current = 'R';
        else if (current == 'R')
          current = 'L';
        else if (current == 'W')
          current = 'P';
        else if (current == 'T')
          current = 'N';
        else if (current == 'N')
          current = 'D';
        else if (current == 'D')
          current = 'B';
        else if (current == 'B')
          current = '6';
        else if (current == 'K')
          current = 'C';
        else if (current == 'M')
          current = 'G';
        else if (current == 'G')
          current = 'Z';
        else if (current == 'Z')
          current = '7';
        else if (current == 'O')
          current = 'o';
        else if (current == 'o')
          current = '8';
        else if (current == 'c')  //CH
          current = '9';   
      //cout << current;
     }
      // step 1.3 if input is -, move right one link
      if (input == '-') {
           // will need a swtich statement or if-else-if here
        if (current == '#') 
          current = 'T';
        else if (current == 'M')
          current = 'M';
        else if (current == 'O')
          current = 'o';
        else if (current == 'c')
          current = 'c';
        else if (current == 'o')
          current = '8';
        else if (current == 'Q')
          current = 'N';
        else if (current == 'K')
          current = 'K';
        else if (current == 'Y')
          current = 'D';
        else if (current == 'X')
          current = 'E';
        else if (current == 'A')
          current = 'A';
        else if (current == 'W')
          current = 'W';
        else if (current == 'J')
          current = 'J';
        else if (current == '1')
          current = 'I';
        else if (current == 'U')
          current = 'U';
        else if (current == 'u')
          current = 'u';
        else if (current == '2')
          current = 'S';
        else if (current == 'V')
          current = 'V';
        else if (current == '3')
          current = 'H';
        else if (current == '4');
        
        //cout << current;
     }      
      // step 1.4 if input is =, output current and reset
      if (input == '=') {
        // output current
        cout << current;
        // set current to #
        current = '#';
     } 
      // step 1.5 if input is #, output current, a space and reset
      if (input == '#') {
      	// output current and a space
      	cout << current << ' ';
      	// set current to #
      	current = '#';
     }
     // step 1.6 if input is /, stop the loop
   
   // end loop
   }  while (input != '/');

   cout << endl;
// all done
return 0;

}
