#include <stdio.h>
#include <aio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <strings.h>

int main()
{
	int fd , ret;
	struct aiocb my_aiocb;
	
	fd = open("./file.txt", O_CREAT|O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return -1;
	}

	bzero(&my_aiocb,sizeof(struct aiocb));

	my_aiocb.aio_buf = malloc(128);
	if (!my_aiocb.aio_buf)
	{
		perror("malloc");
		return -1;
	}

	my_aiocb.aio_fildes = fd;
	my_aiocb.aio_nbytes  = 128;
	my_aiocb.aio_offset = 0;

	ret = aio_read(&my_aiocb);
	if (ret < 0)
	{
		perror("aio read");
		return -1;
	}

	while(aio_error(&my_aiocb) == EINPROGRESS)
	continue;

	if ((ret = aio_return(&my_aiocb)) >= 0)
	{
		printf("ret:%d\n",ret);
	}
	else
	{
		printf("error ret:%d\n",ret);
	}
	return 0;
}
