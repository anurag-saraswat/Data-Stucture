#include "iostream"
#include <unordered_map>
#include <string>

using namespace std;


class Student {
public:

	string fname;
	string lname;
	string rollno;


	Student(string f , string l, string r) {

		fname = f;
		lname = l;
		rollno = r;

	}


	bool operator==(const Student &s) const {

		return rollno == s.rollno ? true : false;
	}

};


class HashFun {
public:

	size_t operator()(const Student &s)  const {
		return s.fname.length() + s.lname.length();
	}
};


int main() {

	unordered_map<Student, int, HashFun> student_map;



	Student s1("Anurag", "Saraswat", "012");
	Student s2("Ajay", "Patel", "123");
	Student s3("Sooraj", "Mishra", "562");
	Student s4("Ajay", "Patel", "789");

	student_map[s1] = 98;
	student_map[s2] = 78;
	student_map[s3] = 58;
	student_map[s4] = 96;

	for (auto i : student_map) {
		cout << endl << i.first.fname << " " << i.first.rollno << endl;
		cout << "Marks : " << i.second << endl;
	}


	return 0;
}