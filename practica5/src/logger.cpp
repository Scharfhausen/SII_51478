#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	mkfifo("/tmp/loggerfifo",0777);
	int fd=open("/tmp/loggerfifo", O_RDONLY);
	int salir=0;
	int aux;
	while(salir==0)
	{
		char buff[200];
		aux=read(fd,buff,sizeof(buff));
		printf("%s\n", buff);
		if((buff[0]=='-')||(aux==-1)) //De esta manera nos aseguramos tambien que no se produce ningún error el read.
		{

			printf("----Tenis cerrado. Cerrando logger...--- \n");
			salir=1; //si se da la condición salimos del bucle
		}

	}
	close(fd);
	unlink("/tmp/loggerfifo");
	return 0;
}
