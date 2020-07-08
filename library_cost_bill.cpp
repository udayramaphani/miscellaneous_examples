// College book store needs help in estimating its business for next year.
// Book sales depend greatly on
//	- whether a book is required for a course or just optional.
//	- whether or not it has been used in the class before.
//	- A new, required textbook will sell to 90% of prospective enrollment.
//	- old, required textbook will sell to only 65% of prospective enrollment.
//	- A new ,optional textbook will sell to 40% of prospective enrollment.
//	- old, optional textbook will sell to only 20% of prospective enrollment

// This program accepts as input a series of books (until the user enters a sentinel).
// For each book ask for:
//	- a code for the book
//	- the single copy cost for the book
//	- the current number of books on hand
//	- the prospective class enrollment
//	- and data that indicates if the book is required/optional, new/used in past.

// Output, 
//	- all the input information in a nicely formatted screen along with how many books must be ordered 
// 		(if any, note that only new books are ordered), the total cost of each order.

// Then, after all input is complete, show the total cost of all book orders, and the expected profit if the store pays 80% of list price. 

// Since we have not yet discussed any ways of dealing with a large set of data coming into a program (stay tuned!),
// just process one book at a time and show the output screen for that book.

// Then, when the user has finished entering all the data, your program should output the total and profit values.

#include <iostream>
#include <cstring>
using namespace std;
#define REQ_NEW_BOOK_FACTOR	(0.90)
#define REQ_OLD_BOOK_FACTOR	(0.65)
#define OPT_NEW_BOOK_FACTOR	(0.40)
#define OPT_OLD_BOOK_FACTOR	(0.20)
#define PROFIT_FACTOR		(0.2) //20% below list price

#define ASTERIK_PRINT		"***********************************************************************"
#define MAX_MESSAGE_LENGTH	50
class book{
private:
	int code;
	int books_in_inventory;
	int enrolled_students;
	float cost;
	float book_factor;

	int books_needed;
	float total_cost;

	char message_string[MAX_MESSAGE_LENGTH];

public:
	void get_book_record();
	void get_user_inputs();
	void add_up_cost(float &total_cost);
};

void book::get_user_inputs(){
	cout << "Please enter book code" << endl;
	cin >> this->code;

	cout << "What is the single copy price?" << endl;
	cin >> this->cost;

	cout << "How many copies already present?" << endl;
	cin >> this->books_in_inventory;

	bool is_book_required;
	cout << "Is this required or optional (Please enter 1 or 0 for required)?" << endl;
	cin >> is_book_required;

	bool is_book_new;
	cout << "Is this new or old (Please enter 1 or 0 for new)?" << endl;
	cin >> is_book_new;

	if(is_book_required) {
		if(is_book_new) {
			this->book_factor = REQ_NEW_BOOK_FACTOR;
			strcpy(this->message_string, "This book is new and required");
		} else {
			this->book_factor = REQ_OLD_BOOK_FACTOR;
			strcpy(this->message_string, "This book is old and required");
		}
	} else {
		if(is_book_new) {
			this->book_factor = OPT_NEW_BOOK_FACTOR;
			strcpy(this->message_string, "This book is new and optional");
		} else {
			this->book_factor = OPT_OLD_BOOK_FACTOR;
			strcpy(this->message_string, "This books is old and optional");
		}
	}

	cout << "What is the total enrollment for this course?" << endl;
	cin >> this->enrolled_students;

	this->books_needed = (this->enrolled_students * this->book_factor) - this->books_in_inventory;
	if (this->books_needed < 0)
		this->books_needed = 0;
	else
		this->total_cost = (this->books_needed * this->cost);
}

void book::get_book_record(){
	cout << ASTERIK_PRINT << endl;
	cout << "Book code: "; cout << this->code << endl;
	cout << "Price: "; cout << this->cost << endl;
	cout << "Inventory: "; cout << this->books_in_inventory << endl;
	cout << "Enrollment: "; cout << this->enrolled_students << endl;
	cout << endl;
	cout << this->message_string << endl;
	cout << ASTERIK_PRINT << endl;
	cout << endl;
	cout << "Need to order:"; cout << this->books_needed << endl;
	cout << "Total Cost: "; cout << this->total_cost << endl;

}

void book::add_up_cost(float &total_cost) {
	total_cost += this->total_cost;
	cout << "The Total cost so far: "<< total_cost << endl;
}

void welcome_message(){
	cout << "Welcome to booksales center!!" << endl;
	cout << endl;
	cout << "Please enter the book information to help estimate costs" << endl;
	cout << "Follow prompts!!!" << endl;
	cout << endl;
}

void exit_message(){
	cout << "Thanks for updating the information." << endl;
	cout << "Have a nice day!!" << endl;
}

int main() {
	welcome_message();
	char add_another_record;
	int num_records_added = 0;
	float total_cost = 0;

	do {
		book *ptr = new book;
		ptr->get_user_inputs();
		ptr->get_book_record();

		cout << " Would like to add another book details? (y or n):" << endl;
		cin >> add_another_record;

		ptr->add_up_cost(total_cost);

		num_records_added++;
	}while (add_another_record == 'y');

	cout << "Total cost of all orders: " << total_cost << endl;
	cout << "Profit: " << (total_cost * PROFIT_FACTOR) << endl;

	exit_message();

	return 0;
}
