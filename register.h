#ifndef REGISTER_H
#define REGISTER_H
#include "subject.h"
#include "student.h"
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(){}
	Date(int day, int month, int year)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
};

class Register
{
private:
	Student sinhVien[100];
	Subject monHoc[100];
	Date ngay[100];
public:
	int count=0;
	
	Register(){}
	
	void subjectRegister(Student sv, Subject mh, Date ng)
	{
		sinhVien[count] = sv;
		monHoc[count] = mh;
		ngay[count] = ng;
		count++;
	}
	
	void totalSubjectFee()
	{
		for (int i=0;i<count;i++)
		{
			for (int j=i;j<count;j++)
			{
				if (sinhVien[i].getStudentCode() > sinhVien[j].getStudentCode())
				{
					Student temp = sinhVien[i];
					sinhVien[i] = sinhVien[j];
					sinhVien[j] = temp;
					
					Subject temp1 = monHoc[i];
					monHoc[i] = monHoc[j];
					monHoc[j] = temp1;
					
					Date temp2 = ngay[i];
					ngay[i] = ngay[j];
					ngay[j] = temp2;
				}
			}
		}
		
		long long int total=0;
		for (int i=0;i<count;i++)
		{
			total += (350000 * monHoc[i].getCoefficient() * monHoc[i].getCredit());
			if (sinhVien[i].getStudentCode() != sinhVien[i+1].getStudentCode() || i+1 == count)
			{
				cout<<sinhVien[i].getStudentCode()<<" "<<total<<endl;
				total = 0;
			}
		}
	}
};

#endif
