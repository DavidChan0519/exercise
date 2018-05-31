#include <iostream>
using namespace std;

const int SLEN=30;
struct student{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[],int n);

void display1(student st);
void display2(const student *ps);
void display3(const student pa[],int n);

int main()
{
	cout<<"Enter class size:";
	int class_size;
	cin>>class_size;
	while(cin.get()!='\n')
		continue;

	student *ptr_stu=new student[class_size];
	int entered =getinfo(ptr_stu,class_size);
	for(int i=0;i<entered;i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu,entered);
	delete [] ptr_stu;
	return 0;
}

void display1(student st)
{
	cout<<"fullname:"<<st.fullname<<" "<<"hobby:"<<st.hobby<<" "<<"ooplevel:"<<st.ooplevel<<endl;
}
void display2(const student *ps)
{
	cout<<"fullname:"<<ps->fullname<<" "<<"hobby:"<<ps->hobby<<" "<<"ooplevel:"<<ps->ooplevel<<endl;
}
void display3(const student pa[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"fullname:"<<pa[i].fullname<<" "<<"hobby:"<<pa[i].hobby<<" "<<"ooplevel:"<<pa[i].ooplevel<<endl;
	}
}

int getinfo(student pa[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter fullname:";
		cin>>pa[i].fullname;
		cout<<"Enter hobby:";
		cin>>pa[i].hobby;
		cout<<"Enter ooplevel:";
		cin>>pa[i].ooplevel;
		count++;

	}
	return count;
}