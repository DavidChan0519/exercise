#include <iostream>
const int SIZE = 70;
struct pizza {
    char name[SIZE];
    float weight;
    float diameter;
};

int main()
{
	using namespace std;
	//pizza pie;
	pizza *pie=new pizza;
	cout<<"输入匹萨公司名称：";
	//cin>>pie.name;
	cin.getline(pie->name,70);
	cout<<"input pizza of diameter:";
	//cin>>pie.diameter;
	cin>>pie->diameter;
	cout<<"input pizza of weight:";
	//cin>>pie.weight;
	cin>>pie->weight;
	//cout << "Company: " << pie.name << "\n";
 //   cout << "Diameter: " << pie.diameter << " inches\n";
 //   cout << "Weight: " << pie.weight << " ounces\n";
	cout << "Company: " << pie->name << "\n";
    cout << "Diameter: " << pie->diameter << " inches\n";
    cout << "Weight: " << pie->weight << " ounces\n";
    return 0;


	return 0;
}
