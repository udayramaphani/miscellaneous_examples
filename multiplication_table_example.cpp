// program to print multiplication table from 1x1 to 9x9

#include <iostream>
using namespace std;

int main() {
    cout << "  1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t" << endl;
    for (int c = 1; c < 10; c++) {
        cout << c << "|";
        for (int i = 1; i < 10; i++)
            cout << i * c << "\t";
        cout << endl;
    }
    return 0;
}
