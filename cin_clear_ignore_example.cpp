// program to demonstrate cin, cin.clear and cin.ignore

#include <iostream>
using namespace std;
#define ignore_limit 1000

int main() {
    int input_value = 0;

    // in a loop, continously take inputs from command prompt
    // if user enteres a non-integer value, ignore the error and
    // prompt for next input.

    // if user enters -1, exit the loop
    do {
            cout << "Enter an integer ( -1 to Quit)" << endl;
            if (! (cin >> input_value)) {
                cout << "Entered a non-integer value. Please re-enter"<< endl;
                cin.clear();
                cin.ignore(ignore_limit, '\n');
            }
            if (-1 == input_value) {
                cout << "User Quiting !! Exiting the program" <<endl;
                break;
            }
    }while (input_value != -1);

    return 0;
}
