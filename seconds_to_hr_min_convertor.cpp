//seconds to hr/min/seconds convertor
#include <iostream>
using namespace std;
#define SECONDS_PER_MIN (60)
#define MINS_PER_HR     (60)

int seconds_to_hrs(int seconds){
    return (seconds/(SECONDS_PER_MIN * MINS_PER_HR));
}

int seconds_to_mins(int seconds){
    int hrs = (seconds/(SECONDS_PER_MIN * MINS_PER_HR));
    seconds = seconds - (hrs * SECONDS_PER_MIN * MINS_PER_HR);
    return (seconds/MINS_PER_HR);
}

int main() {
    int seconds;
    cout << "Enter the time in seconds: ";
    cin >> seconds;
    cout << endl;

    cout << "Hours: " << seconds_to_hrs(seconds) << endl;
    cout << "Minutes: " << seconds_to_mins(seconds) << endl;
    cout << "Seconds: " << (seconds % SECONDS_PER_MIN) << endl;
}
