#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
    
    int fd, valor;
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    sleep(10);
    while(valor!=-1){
    valor= read(fd, buf, MAX_BUF);
    printf("Received: %s\n", buf);
    }
    close(fd);
    unlink(myfifo);

    return 0;
}
