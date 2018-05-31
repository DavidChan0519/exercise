#include <stdio.h>
enum class yy { //default type: int
 a,
 b,
 c,
 d,
 e,
 f,
};

enum class zz:char {
  x,
  y,
  z
};

int main()
{
    enum yy y1 = yy::b; // as to strong type enum, u must specify the type
    printf("y1 sizeof =%lu\n", sizeof(y1));
    enum yy y2 = yy::e;
    printf("y2 sizeof =%lu\n", sizeof(y2));
    enum zz z = zz::x;
    printf("enum zz sizeof =%lu\n", sizeof(enum zz));
    printf("z sizeof =%lu\n", sizeof(z));

    if (y1 > y2) {
       printf("y1i > y2\n");
    } else {
       printf("y1 <= y2\n");
    }


    if ((int)y1 > (int)z) { // compile error
       printf("y1 > z\n");
    } else {
       printf("y1 <= z\n");
    }

    return 0;
}
