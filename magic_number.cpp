
// This program takes in 3 digit input from user and generates an encrypted "magic number"
// Algorithm:
//	1. User enters a three-digit number whose first digit is greater than its last. 
//	2. Reverse the number, and subtract the reversal from the original number. 
//	3. Finally, reverse the resulting number, and add it to its unreversed form. 
//	4. Output the final result. The original number that the user enters must be of integer type (not three chars).
//
// Example:
//	input number: 901
//	reverse it: 109
//	subtract: 901 - 109 = 792
//	reverse it: 297
//	add: 297 + 792 = 1089

#include <iostream>
#include <cmath>
using namespace std;


class magic_num {
private:
	int user_input;
	int magic_num;

public:
	int set_user_input(int user_arg);
	int get_user_input();
	void reverse_int(int *a);
};

int magic_num::set_user_input(int user_arg){
	user_input = user_arg;
	if ((user_input/100) < (user_input % 10)) {
		cout << " Invalid user input, hundred place value is less than unit's place. "<< endl;
		cout << " Please enter a valid input. " << endl;
		return -1;
	}
	return 0;
}

int magic_num::get_user_input() {
	return user_input;
}

void magic_num::reverse_int(int *a){
	int reverse = 0;
	int i = log10(*a);
	//cout << "Reverse of " << *a << " is:" << endl;
	while (i >=0){
		//cout << "Debug, reverse value in iteration " << i << " is:" << reverse << endl;
		reverse += (*a%10)*pow(10,i);
		*a = *a/10;
		i--;
	}
	*a = reverse;
	//cout << *a << endl;
}

int main(){
	magic_num num;
	int inp, temp1, temp2;
	cout << "Enter a three digit number, so that hundred's place value is higher than unit's: " << endl;
	cin >> inp;
	while (num.set_user_input(inp) < 0) {
		cout << "Enter a three digit number, so that hundred's place value is higher than unit's: " << endl;
		cin >> inp;
	}
	// reverse the valid input and subtract from user_input
	num.reverse_int(&inp);
	temp1 = num.get_user_input() - inp;
	temp2 = temp1;
	num.reverse_int(&temp1);
	temp2 += temp1;
	cout << "Magic number is: " << temp2 << endl;
}
