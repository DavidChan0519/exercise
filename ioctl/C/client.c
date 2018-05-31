#include <iostream>  
#include <unistd.h>  
#include <cstdio>  
#include <sys/ioctl.h>  
#include <linux/types.h>  
#include <fcntl.h>
#include <sys/syscall.h>
#include <string.h>
#include <errno.h>
using namespace std;

#define HEPENG_TEST 0  
#define TEST_IOC_MAGIC 'k'  //device command type  
#define IOCTL_HEPENGCMD     _IOWR ( TEST_IOC_MAGIC, 2, struct COMMAND_STRU_T)

struct COMMAND_STRU_T  
{  
    short op;   
    short error;  
};

int main()  
{  
    int fd = open("/dev/hepeng", O_RDWR);  
    if(fd < 0)  
    {     
        cout << "error open:" << strerror(fd) <<endl;  
        return -1;   
    }
	
    COMMAND_STRU_T cmd;  
    cmd.op = HEPENG_TEST; 

    cout << "current pid for process:" << getpid() << endl;
    cout << "current pid for thread:" << syscall(SYS_gettid) << endl;

    if( ioctl(fd, IOCTL_HEPENGCMD, (void*)&cmd) < 0 )   
    { 
        cout << "error ioctl" << endl;  
        cout << "cmd.error:" << cmd.error << endl;  
        return -1;   
    }     
    cout << "cmd.error:" << cmd.error << endl;  
    close(fd);  
    return 0;  
} 
