#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
	string lastName;
	string firstName;
	string email;
	string phoneNumber;
	int studentCode;
public:
	Student(){}
	
	void setStudentCode(int studentCode)
	{
		this->studentCode = studentCode;
	}
	
	int getStudentCode()
	{
		return this->studentCode;
	}
	
	friend istream& operator >> (istream& in, Student &a)
	{
		cout<<"Nhap ten: ";
		in>>a.lastName;
		cout<<"Nhap ho va ten dem: ";
		in.ignore();
		getline(in,a.firstName);
		cout<<"Nhap email: ";
		in>>a.email;
		cout<<"Nhap so dien thoai: ";
		in>>a.phoneNumber;
		return in;
	}
	
//	friend ostream& operator << (ostream& out, Student &a)
//	{
//		out<<
//	}
};

#endif
