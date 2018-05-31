#include <iostream>
#include <csignal>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

void signalHandle(int Num)
{
	cout << "interrupt signal (" << Num << ") received" <<endl;
	exit(Num);
}


int main()
{
	signal(SIGINT, signalHandle);
	
	while (1) {
		cout << "going to sleep..." << endl;
		sleep(1);
	}
	
	return 0;
}


