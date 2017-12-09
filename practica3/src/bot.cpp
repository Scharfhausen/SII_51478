#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include "DatosMemCompartida.h"
#include "Esfera.h"
#include "Raqueta.h"


	int main()
	{

//Creacion del fichero,puntero a memoria y el puntero para la proyeccion
	int file;
	DatosMemCompartida* pMemComp;
	char* proyeccion;

	//Apertura del fichero

	file=open("/tmp/datosBot.txt",O_RDWR);

	//Proyecto el fichero

	proyeccion=(char*)mmap(NULL,sizeof(*(pMemComp)),PROT_WRITE|PROT_READ,MAP_SHARED,file,0);


	//Cierre del fichero

	close(file);


	//Apunto el puntero de Datos a la proyeccion del fichero en memoria

	pMemComp=(DatosMemCompartida*)proyeccion;



	//Acciones de control de la raqueta

	while(1)
	{

		usleep(25000);  //Se suspende durante 25 milisegundos
		float posRaqueta1;
		float posRaqueta2;
		posRaqueta1=((pMemComp->raqueta1.y2+pMemComp->raqueta1.y1)/2);
		posRaqueta2=((pMemComp->raqueta2.y2+pMemComp->raqueta2.y1)/2);
		if(posRaqueta1<pMemComp->esfera.centro.y)
			pMemComp->accion1=1;

		else if(posRaqueta1>pMemComp->esfera.centro.y)
			pMemComp->accion1=-1;

 		else
			pMemComp->accion1=0;

		if(posRaqueta2<pMemComp->esfera.centro.y)
			pMemComp->accion2=1;

		else if(posRaqueta2>pMemComp->esfera.centro.y)
			pMemComp->accion2=-1;
		else
			pMemComp->accion2=0;

	}

	//Se desmonta la proyeccion de memoria

	munmap(proyeccion,sizeof(*(pMemComp)));

	}
