//****************************************************************************************************
//
//		File:					student.h
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
//		Defines student structure for data
//		 
//		
//****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

//****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year;
	float credits;
	float gpa;
	char major[6];

	Student();
	friend ostream & operator<< (ostream & out, const Student & data);
	bool operator == (const Student & rhs) const;
	bool operator == (int value) const;
	bool operator != (const Student & rhs) const;
	bool operator != (int value) const;
	bool operator < (const Student & rhs) const;
	bool operator < (int value) const;
	bool operator > (const Student & rhs) const;
	bool operator > (int value) const;
	bool operator <= (const Student & rhs) const;
	bool operator <= (int value) const;
	bool operator >= (const Student & rhs) const;
	bool operator >= (int value) const;
	int operator % (int value) const;
	Student & operator = (int value);
};

//****************************************************************************************************

Student::Student()
{
	id = 0;
}

//****************************************************************************************************

ostream & operator<< (ostream & out, const Student & data)
{
	out << left << setfill(' ') << setw(5) << data.id << " "
		<< setw(25) << data.name << " "
	    << data.gender << " "
		<< "    " << setw(3) << data.credits << " "
		<< "   " << setw(4) << data.gpa << " "
		<< "  " << data.major;

	return out;
}

//****************************************************************************************************

bool Student::operator == (const Student & rhs) const
{
	return (this -> id == rhs.id);
}

//****************************************************************************************************

bool Student::operator != (const Student & rhs) const
{
	return (this -> id != rhs.id);
}

//****************************************************************************************************

bool Student::operator < (const Student & rhs) const
{
	return (this -> id < rhs.id);
}

//****************************************************************************************************

bool Student::operator > (const Student & rhs) const
{
	return (this -> id > rhs.id);
}

//****************************************************************************************************

bool Student::operator <= (const Student & rhs) const
{
	return (this -> id <= rhs.id);
}

//****************************************************************************************************

bool Student::operator >= (const Student & rhs) const
{
	return (this -> id >= rhs.id);
}

//****************************************************************************************************

bool Student::operator == (int value) const
{
	return (this -> id == value);
}

//****************************************************************************************************

bool Student::operator != (int value) const
{
	return (this -> id != value);
}

//****************************************************************************************************

bool Student::operator < (int value) const
{
	return (this -> id < value);
}

//****************************************************************************************************

bool Student::operator > (int value) const
{
	return (this -> id > value);
}

//****************************************************************************************************

bool Student::operator <= (int value) const
{
	return (this -> id <= value);
}

//****************************************************************************************************

bool Student::operator >= (int value) const
{
	return (this -> id >= value);
}

//****************************************************************************************************

int Student::operator % (int value) const
{
	return (this -> id % value);
}

//****************************************************************************************************

Student & Student::operator = (int value)
{
	this -> id = value;
	return *this;
}

//****************************************************************************************************

#endif 
