#include <iostream>
using namespace std;

class Person{
	protected:
		string name, id, address, phoneNumber, email;

	public:
	    Person(string name, string id, string add, string num, string mail) : name(name), id(id), address(add), phoneNumber(num),email(mail){}
	    virtual void displayInfo(){ cout <<"Name: " << name << endl << "ID: " << id << endl << "Address: " << address << endl << "Phone Number: " << phoneNumber << endl << "Email: " << email << endl << endl;}
		void updateInfo(string type, string info){
			if(type== "address") address = info;
			else if(type == "phone number") phoneNumber = info;
			else if (type == "email") email = info;
			else {cout << "unable to update type provided" << endl << endl; return;}
			cout << "Info Update Successfully" << endl << endl;
		} 
};

class Student : public Person{
	int coursesEnrolled, enrollmentYear;
	double GPA;
	
	public:
		Student(string name, string id, string add, string num, string mail, int courses, double gpa, int year) : Person(name, id, add, num, mail), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year){}
		void displayInfo() override{
			cout << "\t\t\t\t_______________________Academic Record_______________________" << endl << endl;
			cout <<"\t\t\t\tName: " << name << endl << "\t\t\t\tID: " << id << endl << "\t\t\t\tEmail: " << email << endl << "\t\t\t\tNo. Of Courses Enrolled In: " << coursesEnrolled << endl<< "\t\t\t\tEnrollment Year: " << enrollmentYear << endl << "\t\t\t\tGPA: " << GPA << endl << endl;
		}
};

class Professor : public Person{
	string department;
	int coursesTaught;
	double salary;
	
	public:
		Professor(string name, string id, string add, string num, string mail, string dept, int courses,double salary) : Person(name, id, add, num, mail), department(dept), coursesTaught(courses), salary(salary){}
		void displayInfo() override{
			cout << "\t\t\t\t_______________________Faculty Detail_______________________" << endl << endl;
			cout <<"\t\t\t\tName: " << name << endl << "\t\t\t\tID: " << id << endl << "\t\t\t\tEmail: " << email << endl <<"\t\t\t\tDepartment: " << department << endl<< "\t\t\t\tNo. Of Courses Taught: " << coursesTaught << endl<< "\t\t\t\tSalary: " << salary << endl << endl;
		}
};

class Staff : public Person{
	string department, position;
	double salary;
	
	public:
		Staff(string name, string id, string add, string num, string mail, string dept, string poisition, double salary) : Person(name, id, add, num, mail), department(dept), position(position), salary(salary){}
		void displayInfo() override{
			cout << "\t\t\t\t_______________________Administrative Role_______________________" << endl << endl;
			cout <<"\t\t\t\tName: " << name << endl << "\t\t\t\tID: " << id << endl << "\t\t\t\tEmail: " << email << endl <<"\t\t\t\tDepartment: " << department << endl<< "\t\t\t\tPosition: " << position << endl<< "\t\t\t\tSalary: " << salary << endl << endl;
		}
};

class Course{
	string courseID, courseName, instructor, schedule;
	int credits;
	
	public:
		Course(string id, string name, string instruct, int cred, string sched) : courseID(id), courseName(name), instructor(instruct), credits(cred), schedule(sched){}
		void registerStudents(string std_ID){cout<< std_ID << " has been successfully registered in " << courseID << endl << endl;}
		void calculateGrade(){
			double marks;
			cout << "Enter Marks: ";
			cin >> marks;
			switch((int)marks/10){
				case 10: cout<< "A+ in " << courseName << endl << endl; break;
				case 9: cout<< "A in " << courseName << endl << endl; break;
				case 8: cout<< "B in " << courseName << endl << endl; break;
				case 7: cout<< "C in " << courseName << endl << endl; break;
				case 6: cout<< "D in " << courseName << endl << endl; break;
				case 5: cout<< "E in " << courseName << endl << endl; break;
				default: cout<<"F in " << courseName << endl << endl; 
			}
		}
};
int main(){

    Student s("Aaisha","25K-0031","Karachi","+923333337777","k250031@nu.edu.pk",6,3.41,2025);
    s.displayInfo();

    Professor p("Saif Ur Rehman","PR-101","Karachi","+92222221111","saifurrehman@nu.edu.pk","Computer Science",2,500000);
    p.displayInfo();

    Staff st("Zainab","STF-126","Karachi","+927777799","zainu@gmail.com","Administration","Manager",800000);
    st.displayInfo();
    st.updateInfo("email","Zainab@nu.edu.pk");

    Course c("CS101","Object Oriented Programming","Sir Saif Ur Rehman",3,"Tuesday 10AM");
    c.registerStudents("25K-0031");
    c.calculateGrade();

}
