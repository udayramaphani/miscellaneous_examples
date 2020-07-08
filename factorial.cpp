// program to compute factorial of number
#include <iostream>
using namespace std;

class fact {
private:
public:
    fact(int *inp){
        int result = 1;
        int input = *inp;
        for (int i = input; i > 0; i--)
            result *= i;
        *inp = result;
    }
};

int main(){
    int inp;
    cout << "Enter the number to find factorial" << endl;
    cin >> inp;
    cout << "Factorial of " << inp <<" is: " << endl;
    fact f(&inp);
    cout << inp << endl;
    return 0;
}
