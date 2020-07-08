// Program to compute final grade based on internal examinations with the following logic
//	Final grades will be based on the following:
//	40% Assignments   15% Midterm Examination
//	35% Final Examination
//	10% Class Participation Grade 
// 	There are 4 internal assignments

#include <iostream>
#include <fstream>
using namespace std;

#define ASSIGNMENT_FACTOR 		(0.4)
#define NUM_INTERNAL_ASSIGNMENTS	(4)
#define FINAL_EXAM_FACTOR		(.35)
#define MIDTERM_EXAM_FACTOR		(.15)
#define ATTENDENCE_FACTOR		(.1)

class final_grade{
private:
	float internal_marks[NUM_INTERNAL_ASSIGNMENTS];
	float final_exam_marks;
	float midterm_exam_marks;
	float attendance;

public:
	final_grade(){
	}
	float final_grade_computed() {
		float temp = 0;
		final_exam_marks *= FINAL_EXAM_FACTOR;
		midterm_exam_marks *= MIDTERM_EXAM_FACTOR;
		attendance *= ATTENDENCE_FACTOR;

		for (int i = 0; i < NUM_INTERNAL_ASSIGNMENTS; i++) {
			temp += internal_marks[i];
		}
		temp /= NUM_INTERNAL_ASSIGNMENTS;
		temp *= ASSIGNMENT_FACTOR;

		cout << " internal assignments: " << temp << endl;
		cout << " final_exam: " << final_exam_marks << endl;
		cout << " midterm_exam: " << midterm_exam_marks << endl;
		cout << " attendance: " << attendance << endl;

		return (final_exam_marks + midterm_exam_marks + attendance + temp);
	}
};

int main() {
	final_grade f;
	float *ptr_final_grade = (float *)&f;

	//open input_file stream ptr to read grades from file
	ifstream inp_grades_f("grades.txt", ios::in);

	while (!inp_grades_f.eof()){
		inp_grades_f >> *ptr_final_grade++ ;
	}
	//inp_grades_f >> f.internal_marks >> f.final_exam_marks >> f.midterm_exam_marks >> f.attendance;
	cout << "Final grade computed as : " << f.final_grade_computed() << endl;
}
