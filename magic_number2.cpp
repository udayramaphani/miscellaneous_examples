// The integer 36 has a peculiar property: it is a perfect square, and is also the sum of the integers from 1 through 8.
// The next such number is 1225 which is 352, and the sum of the integers from 1 through 49.
// This program finds the next number that is a perfect square and also the sum of a series 1...n. 
// This next number may be greater than 32767.

#include <iostream>
#include <cmath>
using namespace std;

void sum_of_n_integers(long int *sum, int n) {
 	*sum = (n * (n+1))/2; 
}

bool is_perfect_square(long int *num) {
	float sq_root = sqrt(*num);
	if (sq_root - floor(sq_root)) 
		return 0;
	else
		return 1;
}

int main(){
	int ctr = 0;
	long int i = 0;
	long int sum = 0;

	while (ctr < 10) {
		sum_of_n_integers(&sum, i);
		if ( is_perfect_square(&sum) ) {
			ctr++;
			cout << "Magic Number " << ctr << " is: " << sum << endl;
		}
		i++;
	}
	return 0;
}
