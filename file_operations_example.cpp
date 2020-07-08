//file operations example
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_PERSON_NAME_WIDTH   (30)
#define MAX_FILE_NAME_WIDTH     (30)

class person{
private:
    char first_name[MAX_PERSON_NAME_WIDTH];
    char last_name[MAX_PERSON_NAME_WIDTH];
    int age;
public:
    person();
    void update_single_record(std::ofstream &f_people);
};

person::person() {
}

void person::update_single_record(std::ofstream &f_people) {
    // Collect the data.
    cout << "Enter First Name: ";
    cin >> first_name;
    cout << "Enter Last Name: ";
    cin >> last_name;
    cout << "Enter Age: ";
    cin >> age;

    // Write the output to the stream.
    f_people << first_name << endl << last_name << endl << age << endl;
}

int main() {
    char file_name[MAX_FILE_NAME_WIDTH];
    cout << endl << "Enter the name of the file: ";
    cin >> file_name;

    // Create an ofstream called People, open the stream for output.
    ofstream f_people(file_name, ios::out);

    person p;
    char inputs_done;
    int i = 0;
    do {
        p.update_single_record(f_people);
        cout << "Do you want another record (yes or no)?: ";
        cin >> inputs_done;
        i++;
    } while ('n' != inputs_done);

    f_people << "total entries: " << i << endl;
    f_people.close();

    // Create an ifstream called i_People, open the stream for input.
    // ifstream i_People(file_name, ios::in);
    // i_People >> first_name >> last_name >> age;
    // cout << first_name << endl << last_name << endl << age << endl;
    return 0;
}
