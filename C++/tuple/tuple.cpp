#include <iostream>
#include <tuple>
using namespace std;

int main()
{
	tuple<int, int, float> ty1(1,2,3);
	tuple<int, int, int> ty = make_tuple(4,5,6);
	cout << "1st:"<< get<0>(ty)<<endl;
	cout << "2nd:"<< get<1>(ty)<<endl;
	cout << "3rd:"<< get<2>(ty)<<endl;
	
	get<0>(ty) = 200;
	cout << "after 1st:"<< get<0>(ty)<<endl;

	if (ty1==ty) {
		cout << "equal" << endl;
	} else {
		cout << "not equal" << endl;
	}
	return 0;
}
