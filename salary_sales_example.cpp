// sales vs salary problem
#include <iostream>
using namespace std;
#define SHOE_PAIR_PRICE     (225)
#define PER_HOUR_SALARY     (7)
#define BASE_PRICE_PER_PAIR (20)
#define DIRECT_SALARY       (600)
#define NUM_WORK_HRS_DAY    (8)
#define NUM_WORK_DAYS_WEEK  (5)

#define PERCENTAGE_1        (10/100)
#define PERCENTAGE_2        (20/100)

class sales_salary{
private:
    int weekly_sales;
    int num_work_hrs_per_day;
    int num_work_days_per_week;
    int salary;
public:
    sales_salary();
    void salary_calc_sales_comm_method_1();
    void salary_calc_sales_comm_method_2();
    int get_salary();
    void get_weekly_stats_from_user();
};

sales_salary::sales_salary(){
    salary=DIRECT_SALARY;
    num_work_hrs_per_day = NUM_WORK_HRS_DAY;
    num_work_days_per_week = NUM_WORK_DAYS_WEEK;
    cout << "salary in first method set to: " << salary << endl;
}

void sales_salary::salary_calc_sales_comm_method_1(){
    salary = (PER_HOUR_SALARY * num_work_hrs_per_day * num_work_days_per_week)
            + (weekly_sales * (SHOE_PAIR_PRICE * PERCENTAGE_1));

    cout << "salary in second method set to: " << salary << endl;
}

void sales_salary::salary_calc_sales_comm_method_2(){
    salary = (weekly_sales *
                    ( (SHOE_PAIR_PRICE * PERCENTAGE_2)
                        + BASE_PRICE_PER_PAIR
                    )
            );
    cout << "salary in third method set to: " << salary << endl;
}

int sales_salary::get_salary(){
    return salary;
}

void sales_salary::get_weekly_stats_from_user() {
    cout << "Please enter weekly sales:";
    cin >> weekly_sales;

    if (weekly_sales > 0){
        char yes_or_no;
        cout << "Default Work days per week is set to 5. ";
        cout << "Change this default value? (yes or no)";
        cin >> yes_or_no;
        cout << endl;
        if ('y' == yes_or_no){
            cout << "Please enter new work days per week:";
            cin >> num_work_days_per_week;
        }

        cout << "Default Work hours per day is set to 8. ";
        cout << "Change this default value? (yes or no)";
        cin >> yes_or_no;
        cout << endl;
        if ('y' == yes_or_no){
            cout << "Please enter new work hours per day:";
            cin >> num_work_hrs_per_day;
        }
    }
    else {

    }
}

int max_value_index(int *p_array, int array_size){
    int index = 0;
    int max = p_array[0];
    for (int i = 1; i < array_size; i++) {
        if (p_array[i] > max) {
            max = p_array[i];
            index = i;
        }
    }
    return index;
}

int main(){
    sales_salary ss; //constructor sets the default salary
    int salary[3] = {0,0,0};
    salary[0] = ss.get_salary();
    ss.get_weekly_stats_from_user();

    ss.salary_calc_sales_comm_method_1();
    salary[1] = ss.get_salary();
    ss.salary_calc_sales_comm_method_2();
    salary[2] = ss.get_salary();

    int index = max_value_index(salary, 3);
    cout << "For the given stats, it is better to opt for method: "
    << (index + 1) << " with a value "<< salary[index] << endl;
}
