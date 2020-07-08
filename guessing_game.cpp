// decomposition example
// break the program into three parts
//  1. generate random number
//  2. take input from user and compare
//  3. display statement indicating the user

#include <iostream>
using namespace std;

#define ignore_limit 1000

int main() {
    int input_value = 0;

    int random_value = rand()%100;

    // in a loop, continously take inputs from command prompt
    // if user enteres a non-integer value, ignore the error and
    // prompt for next input.

    // if user enters -1, exit the loop
    do {
            cout << endl;
            cout << "Enter an number from 1 to 100 ( -1 to Quit)" << endl;
            if (! (cin >> input_value)) {
                cout << "Entered a out of bound value. Please re-enter"<< endl;
                cin.clear();
                cin.ignore(ignore_limit, '\n');
            }
            if (-1 == input_value) {
                cout << "User Quiting !! Exiting the Game" <<endl;
                break;
            }
            if (input_value > random_value)
                cout << "Entered number is too high" << endl;
            else if (input_value < random_value)
                cout << "Entered number is too low" << endl;
            else {
                cout << "You guessed it right!!" << endl;
                cout << "To continue press 0" << endl;
                cin >> input_value;
                random_value = rand()%100;
            }
    }while (input_value != -1);
    return 0;
}
