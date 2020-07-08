// This programs takes a 4 char input from user and deciphers the expiration date
// Algorithm:
// encode/decode the months from Jan to Dec as 'A' through 'L'
// encode/decode each digit of the date as 'Q' through 'Z'
// encode/decode the year as 'A' through 'Z' meaning 1 through 26 which is then added to 1995

#include <iostream>
using namespace std;

#define TRUE (1)
#define FALSE (0)
#define YEAR_ADDITION (1995)
#define MONTH_ENCODING_START ('A')
#define MONTH_ENCODING_END ('L')
#define DATE_ENCODING_START ('Q')
#define DATE_ENCODING_END ('Z')
#define YEAR_ENCODING_START ('A')
#define YEAR_ENCODING_END ('Z')

bool month_found = FALSE;
bool dat	

e_found = FALSE;

void decipher(char ch) {
	cout << "Input character: " << ch << endl;
	int i;
	char c;
	if (!month_found) {
		i = 0;
		c = MONTH_ENCODING_START;
		while (c <= MONTH_ENCODING_END) {
			//cout << "'c' value: " << c << endl;
			if(c == ch)
				break;
			i++;
			c++;
		}
		if ( i < 12) {
			month_found = TRUE;
			cout << "Found month !!: It is : " << i+1 << endl;
			return;
		}
	}

	i = 0;
	c = DATE_ENCODING_START;
	while (c <= DATE_ENCODING_END) {
		//cout << "'c' value: " << c << endl;
		if(c == ch) 
			break;
		i++;
		c++;
	}
	if (i < 31) { 
		cout << "Date found: " << i << endl;
		return;
	}

	i = 0;
	c = YEAR_ENCODING_START;
	while (c <= YEAR_ENCODING_END) {
		//cout << "'c' value: " << c << endl;
		if(c == ch)
			break;
		i++;
		c++;
	}
	cout << "Found Year !!: It is : " << (i + YEAR_ADDITION) << endl;
}

int main(){
	char input_string[4];
	cout << "Enter the expiry date string: " << endl;
	cin >> input_string;

	//cout << "User entered: " << input_string << endl;


	for (int i =0 ; input_string[i] != '\0'; i++) {
		int ch = input_string[i];
		decipher(ch);
	}

	return 0;
}

