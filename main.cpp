#include <iostream>
using namespace std;
#include "student.h"
#include "subject.h"
#include "register.h"

void subjectMenu()
{
	cout<<".=====================."<<endl;
	cout<<"| 1. Them mon hoc     |"<<endl;
	cout<<".=====================."<<endl;
	cout<<"Chon chuc nang: ";
}

void studentMenu()
{
	cout<<".=====================."<<endl;
	cout<<"| 1. Them sinh vien   |"<<endl;
	cout<<".=====================."<<endl;
	cout<<"Chon chuc nang: ";
}

void Menu()
{
	cout<<".=====================."<<endl;
	cout<<"| 1. Sinh vien        |"<<endl;
	cout<<"| 2. Mon hoc          |"<<endl;
	cout<<"| 3. Dang ky hoc      |"<<endl;
	cout<<".=====================."<<endl;
	cout<<"Chon chuc nang: ";
}

int main()
{
	Student listStudent[100];
	Subject listSubject[100];
	Register reg;
	int option=321; //khac 0 la duoc
	int studentCount = 0;
	int subjectCount = 0;
	int studentCode = 10000;
	int subjectCode = 0;
	while(option!=0)
	{
		Menu();
		cin>>option;
		if (option==1)
		{
			int studentOption;
			studentMenu();
			cin>>studentOption;
			if (studentOption==1)
			{
				cin>>listStudent[studentCount];
				listStudent[studentCount++].setStudentCode(studentCode++);
			}
		}
		else if (option==2)
		{
			int subjectOption;
			subjectMenu();
			cin>>subjectOption;
			if (subjectOption==1)
			{
				cin>>listSubject[subjectCount];
				listSubject[subjectCount++].setSubjectCode(subjectCode++);
			}
		}
		else if (option==3)
		{
			int code,subCode;
			int studentMarkup, subjectMarkup;
			int f=0, subF=0;
			cout<<"Nhap ma sinh vien dang ky hoc: ";
			cin>>code;
			
			for (int i=0;i<studentCount;i++)
			{
				if (code==listStudent[i].getStudentCode())
				{
					f = 1;
					studentMarkup = i;
					break;
				}
			}
			
			if (f==1)
			{
				cout<<"Nhap ma mon hoc dang ky: ";
				cin>>subCode;
				for (int i=0;i<studentCount;i++)
				{
					if (subCode==listSubject[i].getSubjectCode())
					{
						subF = 1;
						subjectMarkup = i;
						break;
					}
				}
				if (subF==1)
				{
					int d,m,y;
					cout<<"Nhap ngay thang nam: ";
					cin>>d>>m>>y;
					reg(listStudent[studentMarkup],listSubject[subjectMarkup],Date(d,m,y));
				}
				else
					cout<<"Khong co mon hoc nay\n";			
			}
			else
				cout<<"Khong co sinh vien nay\n";
		}
	}
	return 0;
}
