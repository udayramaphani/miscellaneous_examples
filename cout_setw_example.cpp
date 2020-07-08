// program to demonstrate cout and setw usage
#include <iostream>
#include <iomanip>
using namespace std;
#define num_rows 6
#define num_columns 4

int main(){
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++)
            cout << setw(17) << "Hello World!";
        cout<<endl;
    }

    return 0;
}
