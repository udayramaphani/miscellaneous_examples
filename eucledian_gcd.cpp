// program to calculate gcd of two numbers using Euclidean algorithm

#include <iostream>
using namespace std;

int gcd(int a, int b){
    int rem;
    do {
        rem =  a % b;
        a = b;
        b = rem;
    } while (a % b > 0);
    return b;
}

int main () {
    int a,b;

    cout << "Enter first number" << endl;
    cin >> a;
    cout << "Enter second number(different from first one)" << endl;
    cin >> b;
    cout << " GCD for "<< a << " and " << b << " is : " << endl;
    // sanity check
    if ( a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    cout << gcd(a,b) << endl;
    return 0;
}
