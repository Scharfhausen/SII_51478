#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_BUF 4096

int main()
{
    
    int fd, valor=3;
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    perror("Open");	
    //sleep(10);
    while(valor!=-1 /*&& valor!=0*/){
    valor= read(fd, buf, MAX_BUF);
    printf("%s\n", buf);
    }
    if(valor==0){
	printf("He llegado al final.");
	exit(1);  //La que asegura que todo se cierra es el return. El exit es muy parecido al return y el mas "salvaje" es el _exit. Los otros cierran los procesos abiertos.
	}
    close(fd);
    unlink(myfifo);

    return 0;
}
