#include <iostream>
#include<string>
using namespace std;
class Person {
protected:
	char name[30];
public:
	void getName() {
		cout << "Enter the name: ";
		cin >> name;
	}
	void printName() {
		cout << name << " ";
	}
	virtual void getData() = 0;
	virtual void printIndData() = 0;
	virtual void enterIndData() = 0;
	virtual void ind() = 0;
	virtual ~Person() {
		cout << "c\n";
	}

};
class Student : public Person {
private:
	int gpa;
public:
	~Student() { cout<<"d."; }
	void getData() {
		Person::getName();
	}
	void enterIndData() {
		cout << "Enter the gpa: ";
		cin >> gpa;
	}
	void printIndData() {
		cout << "gpa: " << gpa << endl;
	}
	void ind() {
		cout << "Student ";
	}

};
class GradStudent : public Student {
public:
	int numb_of_publ;

	void printIndData() {
		cout << "publications: " << numb_of_publ << endl;
	}
	void ind() {
		cout << "Graduate student  ";
	}
	void enterIndData() {
		cout << "Enter the number of publications: ";
		cin >> numb_of_publ;
	}
};

void main() {
	bool flag = true;
	int numberOfPersons = 0;
	int choice;
	while (flag == true) {
		cout << "1-add a Student\n2-add a Graduate Student\n3-list of persons\n4-exit\n";
		cin >> choice;
		Person* persArr[100];//массив указателей
		switch (choice)
		{
		case 1:persArr[numberOfPersons] = new Student;
			persArr[numberOfPersons]->getData();
			persArr[numberOfPersons]->enterIndData();
			numberOfPersons++; break;
		case 2: persArr[numberOfPersons] = new GradStudent;
			persArr[numberOfPersons]->getData();
			persArr[numberOfPersons]->enterIndData();
			numberOfPersons++; break;
		case 3: for (int i = 0; i < numberOfPersons; i++) {
			persArr[i]->ind();
			persArr[i]->printName();
			persArr[i]->printIndData();
		}
			  break;
		case 4:flag = false; break;
		case 5: delete persArr[1];
		}
	}
}



