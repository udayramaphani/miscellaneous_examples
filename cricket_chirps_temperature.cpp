#include <iostream>
using namespace std;

#define DIVISION_FACTOR (4)
#define ADDITION_FACTOR (40)
int chirps_to_temp(int num_chirps) {
	return ((num_chirps + ADDITION_FACTOR)/DIVISION_FACTOR);
}

int main(){
	int num_input_chirps;
	cout << "Enter the number of chirps: "<< endl;
	cin >> num_input_chirps;

	cout << "The ambient temperature is : " << chirps_to_temp(num_input_chirps) << " degrees" << endl;
	return 0;
}
