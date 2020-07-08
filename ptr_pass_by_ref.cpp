#include <iostream>
using namespace std;

void DoIt(int &foo, int goo) {
	foo = goo + 3;
	goo = foo + 4;
	foo = goo + 3;
	goo = foo;
}

void update_speed(float& speed, float amount){
	speed = speed + amount;
}

void accept_input_from_user(){
	float speed, amount;
	cout << " Enter speed and fixed amount values: " << endl;
	cin >> speed >> amount;
	update_speed(speed, amount);
	cout << " Speed updated to " << speed << endl;
}

int main() {
	int *foo, *goo;
	foo = new int;
	*foo = 1;
	goo = new int;
	*goo = 3;
	*foo = *goo + 3;
	foo = goo;
	*goo = 5;
	*foo = *goo + *foo;
	DoIt(*foo, *goo);
	cout << (*foo) << endl;
	accept_input_from_user();
} 
