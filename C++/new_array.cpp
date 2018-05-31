#include <iostream>
#include <unistd.h>
using namespace std;
 
class Box
{
   public:
      Box() {
	 sleep(1);
         cout << "调用构造函数！" <<endl; 
      }
      ~Box() { 
	sleep (1);
         cout << "调用析构函数！" <<endl; 
      }
};
 
int main( )
{
   Box* myBoxArray = new Box[4];
 
   delete [] myBoxArray; // 删除数组
   return 0;
}
