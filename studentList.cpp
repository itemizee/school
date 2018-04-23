//****************************************************************************************************
//
//		File:					studentList.cpp
//		
//		Student:				Josh Gerber
//
//		Assignment:	 			Program  # 11
//
//		Course Name:			Data Structures   II 
//
//		Course Number:			COSC 3100 - 01
//
//		Due:					April 5, 2016
//
//
//		Functions to process a student list. add, search, update, delete, print list, list info, quit
//		 
//		
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;
#include "BST.h"
#include "student.h"

//****************************************************************************************************

void process (BST <Student> &);
char getChoice();
void buildList(BST <Student> &);
void displayStudents(BST <Student> &);
void display1Student(Student myStudent);
void addStudent(BST <Student> &);
void findStudent(BST <Student> &);
void removeStudent(BST <Student> &);
void listInformation(BST <Student> &);
void updateStudent(BST <Student> &);

//****************************************************************************************************

int main()
{
	BST <Student> studentList;

	buildList(studentList);
	process(studentList);

	return 0;
}

//****************************************************************************************************

void process (BST <Student> & studentList)
{
	char choice;

	do
	{
		choice = getChoice();

		switch(choice)
		{
			case'A':	addStudent(studentList);
						break;
			case'S':	findStudent(studentList);
						break;
			case'U':	updateStudent(studentList);
						break;
			case'D':	removeStudent(studentList);
						break;
			case'P':	displayStudents(studentList);
						break;
			case'X':	listInformation(studentList);
						break;
			case'Q':	break;
		}
	}
	while(choice != 'Q');
}

//****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << "======== MENU ======== \n"
		 << " A: Add a new Student \n"
		 << " S: Search for a student \n"
		 << " U: Update a Student Record \n"
		 << " D: Delete a Student \n"
		 << " P: Print Student list \n"
		 << " X: List Information \n"
		 << " Q: Quit \n\n"
		 << "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch(choice)
		{
			case 'A':
			case 'S':
			case 'U':
			case 'D':
			case 'P':
			case 'X':
			case 'Q':	valid = true;
						break;
			default:	valid = false;
						cout << "Invalid choice\n Please try again: ";
						break;
		}
	}
	while(!valid);

	return choice;
}

//****************************************************************************************************

void buildList(BST <Student> & studentList)
{
	Student student;
	ifstream studentData;

	studentData.open("studentFile.txt");

	while(studentData >> student.id)
	{
		studentData.ignore();
		studentData.getline(student.name, 50);
		studentData.getline(student.citystate, 50);
		studentData >> student.phone
					>> student.gender
					>> student.year
					>> student.credits
					>> student.gpa
					>> student.major;

		studentList.insert(student);
	}

	studentData.close();
}

//****************************************************************************************************

void displayStudents(BST <Student> & studentList)
{
	cout << "\n\t STUDENT LIST" << endl;
	cout << left << setw(5) << "ID" << " "
		 << setw(25) << "NAME"
		 << "M/F"
		 << "  Credits"
		 << "  GPA"
		 << "    Major\n";

	studentList.inorderTraverse(display1Student);
	cout << endl << endl;
}

//****************************************************************************************************

void display1Student(Student myStudent)
{
	cout << myStudent << endl;
}

//****************************************************************************************************

void addStudent(BST <Student> & studentList)
{
	Student tempStudent;
	cout << "\nEnter student ID: ";
	cin >> tempStudent.id;
	cin.ignore();
	cout << "Enter student full name: ";
	cin.getline(tempStudent.name, 50);
	cout << "Enter student city and state: ";
	cin.getline(tempStudent.citystate, 50);
	cout << "Enter student phone number: ";
	cin >> tempStudent.phone;
	cout << "Enter student gender (M/F): ";
	cin >> tempStudent.gender;
	cout << "Enter student year: ";
	cin >> tempStudent.year;
	cout << "Enter student credits: ";
	cin >> tempStudent.credits;
	cout << "Enter student gpa: ";
	cin >> tempStudent.gpa;
	cout << "Enter student major: ";
	cin >> tempStudent.major;

	if (studentList.insert(tempStudent))
		cout << "\nNew student added:\n" << tempStudent << endl;
	else
		cout << "\nError adding student\n\n";
}

//****************************************************************************************************

void findStudent(BST <Student> & studentList)
{
	Student tempStudent;
	cout << "\nEnter student ID: ";
	cin >> tempStudent.id;

	if (studentList.search(tempStudent))
		cout << "\nStudent found:\n" << tempStudent << endl;
	else
		cout << "\nnot found\n\n";
}

//****************************************************************************************************

void removeStudent(BST <Student> & studentList)
{
	Student tempStudent;
	cout << "\nEnter student ID: ";
	cin >> tempStudent.id;

	if (studentList.remove(tempStudent))
		cout << "\nStudent removed:\n" << tempStudent << endl;
	else
		cout << "\nnot found\n\n";
}

//****************************************************************************************************

void listInformation(BST <Student> & studentList)
{
	cout << "LIST INFORMATION:\n";
	cout << "Number of students: " << studentList.getCount() << endl;
	cout << "Height of tree: " << studentList.getHt() << endl;

	if(studentList.isEmpty())
		cout << "Student list is empty\n";
	else
		cout << "Student list is not empty\n";

	if(studentList.isFull())
		cout << "Student list is full\n";
	else
		cout << "Student list is not full\n";

	if(studentList.isComplete())
		cout << "Student list is complete\n";
	else
		cout << "Student list is not complete\n";

	if(studentList.isBalanced())
		cout << "Student list is balanced\n";
	else
		cout << "Student list is not balanced\n";
}

//****************************************************************************************************

void updateStudent(BST <Student> & studentList)
{
	Student tempStudent;
	cout << "\nEnter student ID: ";
	cin >> tempStudent.id;
	cin.ignore();
	cout << "Enter student full name: ";
	cin.getline(tempStudent.name, 50);
	cout << "Enter student city and state: ";
	cin.getline(tempStudent.citystate, 50);
	cout << "Enter student phone number: ";
	cin >> tempStudent.phone;
	cout << "Enter student gender (M/F): ";
	cin >> tempStudent.gender;
	cout << "Enter student year: ";
	cin >> tempStudent.year;
	cout << "Enter student credits: ";
	cin >> tempStudent.credits;
	cout << "Enter student gpa: ";
	cin >> tempStudent.gpa;
	cout << "Enter student major: ";
	cin >> tempStudent.major;

	if (studentList.update(tempStudent))
		cout << "\nStudent updated:\n" << tempStudent << endl;
	else
		cout << "\nError updating student\n\n";
}

//****************************************************************************************************

//list info output
/*
LIST INFORMATION:
Number of students: 61
Height of tree: 12
Student list is not empty
Student list is not full
Student list is not complete
Student list is not balanced
*/


