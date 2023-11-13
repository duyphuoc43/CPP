#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
using namespace std;

class employee
{
    private:
            
        string name;
        double id;
        string birthday;

    public:

        employee()
        {
            cout << "Create an employee" << endl;
        }

        employee(string name, double id, string birthday)
        {
            setname(name);
            setid(id);
            setbirthday(birthday);
        }

        virtual void show_information()
        {
            cout << getname() << endl;
            cout << getid() << endl;
            cout << getbirthday() << endl;
        }

        void setname(string name)
        {
            this->name = name;
        }

        void setid(double id)
        {
            this->id = id;
        }

        void setid(string id)
        {
            
            this->id = stod(id);
        }

        void setbirthday(string birthday)
        {
            this->birthday = birthday;
        }

        string getname() const
        {
            return name;
        }

        double getid() const
        {
            return id;
        }

        string getbirthday() const
        {
            return birthday;
        }
        
        friend class ADMIN;
};
class ADMIN {
    public:

        void showAllEmployee(const vector<vector<employee*>>& employees) 
        {
            showAllEmployeeEX(employees);
            showAllEmployeeFresher(employees);
            showAllEmployeeIntern(employees);
        }

        void showAllEmployeeEX(const vector<vector<employee*>>& employees) 
        {
            for (int i = 0; i < employees[0].size(); i++)
            {
                employees[0][i]->show_information();
            }
        }

        void showAllEmployeeFresher(const vector<vector<employee*>>& employees) 
        {
            for (int i = 0; i < employees[1].size(); i++)
            {
                employees[1][i]->show_information();
            }
        }

        void showAllEmployeeIntern(const vector<vector<employee*>>& employees) 
        {
            for (int i = 0; i < employees[2].size(); i++)
            {
                employees[2][i]->show_information();
            }
        }

        void modifyInformationEmployee(employee* employee,const string nameReplace)
        {
            employee->name = nameReplace;
        }
};

class employee_experience : public employee
{
    private:

        int expln_year;
        string proskill;

    public:

        employee_experience()
        {
            cout << "Create an employee_experience" << endl;
        }

        employee_experience(string name, double id, string birthday, int expln_year, string proskill)
            : employee(name, id, birthday)
        {
            setexpln_year(expln_year);
            setproskill(proskill);
        }

        void show_information() 
        {
            cout << getname() << endl;
            cout << getid() << endl;
            cout << getbirthday() << endl;
            cout << getexpln_year() << endl;
            cout << getproskill() << endl << endl;
        }

        void setexpln_year(const int expln_year) 
        {
            this->expln_year = expln_year;
        }

        void setproskill(const string proskill)
        {
            this->proskill = proskill;
        }

        int getexpln_year() const
        {
            return expln_year;
        }

        string getproskill() const
        {
            return proskill;
        }
};

class employee_fresher : public employee
{
    private:

        double gradution_date;
        double GPA;

    public:
        employee_fresher()
        {
            cout << "Create an employee_fresher" << endl;
        }

        employee_fresher(string name, double id, string birthday, double gradution_date, double GPA)
            : employee(name, id, birthday)
        {
            setgradution_date(gradution_date);
            setGPA(GPA);
        }

        void show_information() 
        {
            cout << getname() << endl;
            cout << getid() << endl;
            cout << getbirthday() << endl;
            cout << getgradution_date() << endl;
            cout << getGPA() << endl << endl;
        }

        void setgradution_date(double gradution_date) 
        {
            this->gradution_date = gradution_date;
        }

        void setGPA(double GPA)
        {
            this->GPA = GPA;
        }

        void setGPA(string GPA)
        {
            this->GPA = stof(GPA);
        }

        double getgradution_date() const
        {
            return gradution_date;
        }

        double getGPA() const
        {
            return GPA;
        }
};

class employee_intern : public employee
{
    private:
        string majors;
        int semester;

    public:
        employee_intern()
        {
            cout << "Create an employee_intern" << endl;
        }

        employee_intern(const string name,const double id,const string birthday,const int semester,const string majors)
            : employee(name, id, birthday)
        {
            setsemester(semester);
            setmajors(majors);
        }

        void show_information() 
        {
            cout << getname() << endl;
            cout << getid() << endl;
            cout << getbirthday() << endl;
            cout << getsemester() << endl;
            cout << getmajors() << endl << endl;
        }

        void setmajors(const string majors)
        {
            this->majors = majors;
        }

        void setsemester(const int semester)
        {
            this->semester = semester;
        }

        string getmajors() const
        {
            return this->majors;
        }

        int getsemester() const
        {
            return this->semester;
        }
};

void create_employee_experience(vector<vector<employee*>>& employees)
{
  /*  static int couter_employee_experience = 1;*/
    employees[0].push_back(new employee_experience("Nguyen Van A", 1005, "01/01/1990", 5, "Programming"));
    employees[0].push_back(new employee_experience("Tran Thi X", 1009, "02/02/1995", 7, "Data Analysis"));
    employees[0].push_back(new employee_experience("Hoang Van Y", 1010, "03/03/1988", 8, "Machine Learning"));
    employees[0].push_back(new employee_experience("Le Van Z", 1011, "04/04/1992", 6, "Software Development"));
    //couter_employee_experience++;
}
void create_employee_fresher(vector<vector<employee*>>& employees)
{
    //static int couter_employee_fresher = 1;
    employees[1].push_back(new employee_fresher("Nguyen Thi B", 1002, "02/02/1995", 2023, 3.5));
    employees[1].push_back(new employee_fresher("Tran Van F", 1006, "03/03/1996", 2022, 3.6));
    employees[1].push_back(new employee_fresher("Le Thi D", 1004, "04/04/1997", 2021, 3.7));
 /*   couter_employee_fresher++;*/
}
void create_employee_intern(vector<vector<employee*>>& employees)
{
    //static int couter_employee_intern = 1;
    employees[2].push_back(new employee_intern("Tran Van C", 1003, "03/03/2000", 2, "Computer Science"));
    employees[2].push_back(new employee_intern("Nguyen Thi E", 1001, "05/05/1998", 3, "Information Technology"));
    employees[2].push_back(new employee_intern("Le Van G", 1007, "07/07/1999", 1, "Electrical Engineering"));
    employees[2].push_back(new employee_intern("Hoang Thi H", 1008, "08/08/2001", 4, "Mechanical Engineering"));
    //couter_employee_intern++;
}

bool DEC(const employee* a, const employee* b) {
    return a->getid() > b->getid();
}
bool ASEC(const employee* a, const employee* b) {
    return a->getid() < b->getid();
}

int main()
{
    vector<vector<employee*>>employees(3);
    char key;
    //cin >> key;
    //switch (key)
    //{
    //case 'a':
    //    sh
    //    break;
    //default:
    //    break;
    //}
    create_employee_experience(employees);
    create_employee_fresher(employees);
    create_employee_intern(employees);

    bool (*compareFunction)(const employee*, const employee*) = DEC;
    sort(employees[2].begin(), employees[2].end(), compareFunction);
    ADMIN phuoc;

    phuoc.modifyInformationEmployee(employees[0][1], "phuoc");
    phuoc.showAllEmployee(employees);

    return 0;
}
