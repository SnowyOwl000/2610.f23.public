#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
  char
    choice;
  bool
    hasAnchovies = false,
    hasPepperoni = false,
    hasSausage = false,
    hasXCheese = false,
    hasHam = false,
    hasJPeppers = false,
    hasPineapple = false;
    
  do {
    // clear screen
    cout << "\033[2J\033[H";

    // output toppings
    cout << "Toppings:";
    if (hasAnchovies)
      cout << " anchovies";
    if (hasPepperoni)
      cout << " pepperoni";
    if (hasSausage)
      cout << " sausage";
    if (hasXCheese)
      cout << " extra-cheese";
    if (hasHam)
      cout << " ham";
    if (hasJPeppers)
      cout << " jalapenos";
    if (hasPineapple)
      cout << " pineapple";
    cout << endl;
  
    // show menu
    cout << "\nAvailable toppings:\n\n"
      "(A)nchovies\n"
      "(P)epperoni\n"
      "(S)ausage\n"
      "e(X)tra cheese\n"
      "(H)am\n"
      "(J)alapeno peppers\n"
      "p(I)neapple\n"
      "\n(Q)uit\n"
      "\nEnter your choice: ";
    
    // get choice
    cin >> choice;
    
    // process choice  
    switch (choice) {
    case 'A':
    case 'a':
      hasAnchovies = !hasAnchovies;
      break;
    case 'P':
    case 'p':
      hasPepperoni = !hasPepperoni;
      break;
    case 'S':
    case 's':
      hasSausage = !hasSausage;
      break;
    case 'X':
    case 'x':
      hasXCheese = !hasXCheese;
      break;
    case 'H':
    case 'h':
      hasHam = !hasHam;
      break;
    case 'J':
    case 'j':
      hasJPeppers = !hasJPeppers;
      break;
    case 'I':
    case 'i':
      hasPineapple = !hasPineapple;
      break;
    case 'Q':
    case 'q':
      break;
    default:
      cout << "Invalid choice '" << choice << "'" << endl;
      sleep(2);
    }
    
  } while (choice != 'Q' && choice != 'q');
  
  return 0;
}

