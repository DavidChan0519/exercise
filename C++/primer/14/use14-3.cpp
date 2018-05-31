// workmi.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <string>
#include "14-3.h"
const int SIZE=5;

int main()
{
   using std::cin;
   using std::cout;
   using std::endl;
   using std::strchr;
  /* Queue<Worker *>pt;
   Worker temp1[2],*temp2;
   for(int i=0;i<2;i++)
   {
	   temp1[i].setworker();
	   pt.enqueue(&temp1[i]);
   }
   for(int i=0;i<2;i++)
   {
	   pt.dequeue(temp2);
	   temp2->show();
   }*/
   Queue<Worker>*pt=new Queue<Worker>(2);
   Worker temp1,temp2;
   temp2.setworker();
   if(!pt->enqueue(temp2))
   {
	   cout<<"en queue is full failed";
	   return 0;
   }
   pt->dequeue(temp1);
   temp1.show();


    return 0; 
}
