#include <iostream>
using namespace std;
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_box(box b)
{
	cout<<"maker:"<<b.maker<<"\nHeight:"<<b.height<<"\nwidth:"<<b.width<<"\nlength:"<<b.length<<"\nvolume:"<<b.volume<<endl;
}
void set_box_volume(box *b)
{
	b->volume = b->height*b->length*b->width;
}
int main()
{
	box b1={"zhaohang",4,4,4,16};
	show_box(b1);
	set_box_volume(&b1);
	show_box(b1);
	return 0;
}




