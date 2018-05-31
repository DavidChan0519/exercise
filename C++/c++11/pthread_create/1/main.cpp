#include <stdio.h>
#include "pthread.h"

void foo()
{
    while(1)
    {
        printf("=== created thread: foo ===\n");
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    Thread t(&foo);

    t.start();
    t.join();

    return 0;
}

