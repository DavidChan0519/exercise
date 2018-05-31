#include <iostream>
using namespace std;
#include "14-5.h"
int main(void)
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	highfink hf(ma, "Curly Kew"); // recruitment?
	hf.ShowAll();
	highfink hi(fi,50);
	hi.ShowAll();
	cout << "Press a key for next phase:\n";
	cin.get();
	highfink hf2;
	hf2.SetAll();
	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
	for (int i = 0; i < 4; i++)
	{
		tri[i]->ShowAll();
		cout<<endl;
	}
	//abstr_emp tri[4] = {em, fi, hf, hf2};
	//for (int i = 0; i < 4; i++)
	//{
	//	tri[i].ShowAll();
	//	cout <<endl;
	//}
	return 0;
}