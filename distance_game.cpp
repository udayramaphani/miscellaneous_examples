// This program depicts a game, where user enters an angle to aim at incoming enemy
// The control requests for input angle and uses a pre-defined formula to estimate
// the distance and compares if it meets the enemy's distance.
// Enemy distance is a random number generator.
#include <iostream>
#include <cmath>
using namespace std;


#define FIXED_VELOCITY (200.0)
#define FIXED_GRAVITY  (32.2)
#define PI (22/7)

void start_message(){
	cout << "Welcome to Artillery game!!!!" << endl;
	cout << "You are in middle of war and being charged by enemies." << endl;
	cout << "You have one cannon and 10 cannon balls. The cannon can be shot at any angle" << endl;
	cout << "Lets start...." << endl;
	cout << endl;
}

float distance_estimate(float inp_angle_from_user){
	float time_in_air = (2.0 * FIXED_VELOCITY * sin(inp_angle_from_user))/FIXED_GRAVITY;
	return (round((FIXED_VELOCITY * cos(inp_angle_from_user)) * time_in_air));
}

int shoot(){
	float enemy_distance = 0;
	float inp_angle = 0;
	float proj_distance = 0;
	enemy_distance = (float)(rand()%1000);
	int num_attempts = 0;

	do {
		cout << "The enemy is at " << enemy_distance << " feet distance from you" << endl;
		cout << "Enter the angle to shoot: " << endl;
		cin >> inp_angle;
		// convert angle into radians
		inp_angle = (inp_angle * PI)/180.0;

		proj_distance = distance_estimate(inp_angle);
		cout << "Projectile distance : " << proj_distance << endl;
		if (proj_distance > enemy_distance)
			cout << "You over shot by " << (proj_distance - enemy_distance) << endl;
		else if (proj_distance < enemy_distance) 
			cout << " You under shot by " << (enemy_distance - proj_distance) << endl;
		else
			cout << "You hit the enemy!!!" << endl;

		num_attempts++;
	}while(num_attempts < 10 && (proj_distance != enemy_distance));

	if (num_attempts < 10) {
		cout << "You took " << num_attempts << " attempts" << endl;
		return 1;
	} else {
		return 0;
	}
}
int main(){
	char user_input;
	start_message();
	int num_shot = 0;

	do {
		num_shot += shoot();
		cout << " Would like to play again!!! ? (Yes or No)" << endl;
		cin >> user_input;
		if (user_input == 'N' || user_input == 'n')
			break;
	} while(1);

	cout << "Number of enemies shot are : " << num_shot << endl;
	return 0;
}
