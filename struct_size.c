#include <stdio.h>


struct A
{
 int num;
 char *name;
 short data;
 char ha;
 short a[5];

};


int main()
{
  struct A dd;
  struct A *p = 0x100;
  printf("struct size=0x%x\n",sizeof(struct A));
  printf("p+0x200= 0x%p\n",p+0x200);
  printf("(unsigned int)p + 0x200=0x%p\n",(unsigned int*)p+0x200);
  printf("(char)p+0x200 = 0x%p\n", (char*)p+0x200);
  return 0;

}
