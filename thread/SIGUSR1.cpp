#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

void catchSigUsr1(int sig)
{
	cout <<"catch usr1 signal:"<<sig<<endl;
}

void catchSigUsr2(int sig)
{
	cout <<"catch usr2 signal:"<<sig<<endl;
}


int main()
{
	signal(SIGUSR1,catchSigUsr1);
	signal(SIGUSR2,catchSigUsr2);
	pause();
	return 0;
}
