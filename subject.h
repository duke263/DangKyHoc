#ifndef SUBJECT_H
#define SUBJECT_H

class Subject
{
private:
	string subjectCode;
	string subjectName;
	int credit;
	float coefficient;
	string subjectType;
public:
	Subject(){}
	
	void setSubjectCode(int subjectCode)
	{
		this->subjectCode = subjectCode;
	}
	
	int getCredit()
	{
		return credit;
	}
	
	float getCoefficient()
	{
		return coefficient;
	}
	
	friend istream& operator >> (istream& in, Subject &a)
	{
		cout<<"Nhap ten mon: ";
		in.ignore();
		getline(in,a.subjectName);
		cout<<"Nhap so tin chi cua mon: ";
		in>>a.credit;
		cout<<"Nhap he so cua mon: ";
		in>>a.coefficient;
		cout<<"Nhap loai mon: ";
		in>>a.subjectType;
		return in;
	}
};

#endif
