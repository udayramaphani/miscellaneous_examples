// Example program to demonstrate pointers

#include <iostream>
#include <cstring>
using namespace std;

struct user_inputs {
	char name[10];
	int age;
	float height;
	float weight;
};

class Person {
private:
	char name[10];
	int age;
	float height;
	float weight;

public:
	Person();
	void set_person_params(user_inputs *user_params);
	void get_person_params();

};

Person::Person() {
}

void Person::set_person_params(user_inputs *user_params) {
	strncpy(this->name, user_params->name, sizeof(this->name));
	this->age = user_params->age;
	this->height = user_params->height;
	this->weight = user_params->weight;
}

void Person::get_person_params(){
	cout << "Person name: " << this->name << endl;
	cout << "Person age: " << this->age << endl;
	cout << "Person height: " << this->height << endl;
	cout << "Person weight: " << this->weight << endl;
}

void passByValue(int num){
	cout << "Executing passByValue" << endl;

	//incrementing the input value
	num++;

	cout << "Incoming value incremented to " << num << endl;
}

void passByRef(int &num){
	cout << "Executing passByRef" << endl;

	//incrementing the input value
	num = 50;

	cout << "Incoming value incremented to " << num << endl;
}

void ModifyPerson(Person *p){
	cout << "Changing the Person details" << endl;
	user_inputs modified_params;
	strncpy(modified_params.name,"Madhuri", 10);
	modified_params.age = 32;
	modified_params.height = 60;
	modified_params.weight = 155;

	p->set_person_params(&modified_params);
}
int main() {
	int num1, num2;
	int &pNum = num2;

	num1 = 3;
	pNum = 5;

	cout << "Before executing passByValue, num1 value is "<< num1 << endl;
	passByValue(num1);
	cout << "After executing passByValue, num1 value is " << num1 << endl;

	cout << "Before executing passByRef, pNum value is " << pNum << endl;
	passByRef(pNum);
	cout << "After executing passByRef, pNum value is " << pNum << endl;


	cout << "Before executing passByValue, pNum value is " << pNum << endl;
	passByValue(pNum);
	cout << "After executing passByValue, pNum value is " << pNum << endl;


	double *pDouble = new double;
	*pDouble = 9.9;

	cout << "Pointer to Double is assigned value " << *pDouble << endl;
	delete pDouble;

	Person p1;

	user_inputs user_inp;
	//user_inp.name = "Poorvi";
	strncpy(user_inp.name, "Poorvi", 10);
	user_inp.age = 6;
	user_inp.height = 45;
	user_inp.weight = 50;

	p1.set_person_params(&user_inp);
	cout << "Before executing ModifyPerson,";
	cout << "Person details are as follows:" << endl;
	p1.get_person_params();

	ModifyPerson(&p1);
	cout << "After executing ModifyPerson, Person details have changed to:" << endl;
	p1.get_person_params();

	return 0;
}
