#include <iostream>
#include <csignal>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

void signalHandler( int signum )
{
cout << "Interrupt signal (" << signum << ") received.\n";
// 清理并关闭
// 终止程序
exit(signum);
}
 
int main ()
{
	int i =0;
	// 注册信号 SIGINT 和信号处理程序
	signal(SIGINT, signalHandler);
	
	while(1){
		cout << "Going to sleep...." << endl;
		sleep(1);
		if(i==3)
		{
			raise(SIGINT);
		}
		i++;
	} 
	return 0;
}
