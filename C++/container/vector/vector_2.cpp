#include <iostream>
using namespace std;
#include <vector>   //向量的头文件；
#include <algorithm> //算法的头文件；
int main()
{
	vector <int> vec(5,8);
	//--类型是vector<int>，该容器向量中含有5个int类型的数值8，变量名为vec。
	//vector是一个类模板（class template）,所以必须要声明其类型，int，一个容器中所有的对象必须是同一种类型；
	// 定义一个容器对象；直接构造出一个数组；用法和数组一样；
	// 	
 	for(int i=0;i<vec.size();i++)   //size()是指容器里当前有多少个使用的元素；
	{
 		cout<<vec[i]<<"  ";
 	}	
	cout<<endl<<"size:"<<vec.size()<<" "<<"capacity:"<<vec.capacity()<<endl;  //得到容器里用的多少个空间，和总共的大小；
	vector<int>::iterator ite;  //定义了一个向量的迭代器；相当于定义了一个指针；
	for(ite=vec.begin();ite!=vec.end();ite++)   //得到开始、结束
	{
		cout<<*ite <<" ";  //迭代器返回的是引用：
	}
        cout<<endl;
	//在尾部插入；
	vec.push_back(9);  //VS6.0扩充的空间是两倍；在VS2005扩充的空间是1.5倍；
	for(ite=vec.begin();ite!=vec.end();ite++)   //得到开始、结束
	{
		cout<<*ite <<" ";
	}
	cout<<endl<<vec.size()<<" "<<vec.capacity()<<endl;

	//尾部删除;容量没变【capacitty】，但是使用空间减少一个；容量一旦增加就不会减小；
	vec.pop_back();
	for(ite=vec.begin();ite!=vec.end();ite++)   //得到开始、结束
	{
		cout<<*ite <<" ";
	}
	cout<<endl<<vec.size()<<" "<<vec.capacity()<<endl;

	vec.push_back(88);  
	vec.push_back(99); //容量刚好够；

	for(ite=vec.begin();ite!=vec.end();ite++)   //得到开始、结束
	{
		cout<<*ite <<" ";
	}
	cout<<endl<<vec.size()<<" "<<vec.capacity()<<endl;

	ite = find(vec.begin(),vec.end(),88);   //查找这个元素；
	vec.erase(ite);  //利用迭代器指针删除这个元素；
	for(int i=0;i<vec.size();i++)   //size()是指容器里当前有多少个使用的元素；
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl<<vec.size()<<" "<<vec.capacity()<<endl;  //得到容器里用的多少个空间，和总共的大小；

	vec.clear(); //只是清除了数据，没有回收空间，空间的等到对象的生命周期结束时回收；
	//使用空间为0，但是容量的空间还在，只有在调用析构函数的时候空间才会回收；

	for(int i=0;i<vec.size();i++)   //size()是指容器里当前有多少个使用的元素；
	{
		cout<<vec[i]<<"  ";
	}
	cout<<endl<<vec.size()<<" "<<vec.capacity()<<endl;

	ite=find(vec.begin(),vec.end(),88);
	vec.insert(ite,2,77);  //迭代器标记的位置前，插入数据；

	//cout<<*ite<<endl;  //会崩溃，因为迭代器在使用后就释放了，*ite的时候就找不到它的地址了；
	//和向量的用法一样，但是链表list不同，它的迭代器在使用后还可以继续用；链表特有的；</span>

	for(int i=0;i<vec.size();i++)   
	{
		cout<<vec[i]<<"  ";
	}
	cout<<endl<<vec.size()<<" "<<vec.capacity()<<endl;

	system("pause");
	return 0;
}
