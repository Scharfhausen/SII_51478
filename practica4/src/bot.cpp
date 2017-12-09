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
	//Creo el fichero, el puntero a la memoria y el puntero para la proyeccion
	int file;
	DatosMemCompartida* pMemComp;
	char* proyeccion;

	//Abro el fichero
	file=open("/tmp/datosBot.txt",O_RDWR);

	//Proyecto el fichero
	proyeccion=(char*)mmap(NULL,sizeof(*(pMemComp)),PROT_WRITE|PROT_READ,MAP_SHARED,file,0);

	//Cierro el fichero
	close(file);

	//Apunto el puntero de Datos a la proyeccion del fichero en memoria
	pMemComp=(DatosMemCompartida*)proyeccion;

	//Condición de salida
	int salir=0;

	//Acciones de control de la raqueta
	while(salir==0)
 	{
		if (pMemComp->accion==5)
		{
			salir=1;
		}
		usleep(25000);  
		float posRaqueta;
		//float posRaqueta2;
		posRaqueta=((pMemComp->raqueta1.y2+pMemComp->raqueta1.y1)/2);
		//posRaqueta2=((pMemComp->raqueta2.y2+pMemComp->raqueta2.y1)/2);
		if(posRaqueta<pMemComp->esfera.centro.y)
			pMemComp->accion=1;
		else if(posRaqueta>pMemComp->esfera.centro.y)
			pMemComp->accion=-1;
		else
			pMemComp->accion=0;
		/*if(posRaqueta2<pMemComp->esfera.centro.y)
			pMemComp->accion2=1;
		else if(posRaqueta2>pMemComp->esfera.centro.y)
			pMemComp->accion2=-1;
		else
			pMemComp->accion2=0;*/
	}

	//Desmontamos la proyeccion de memoria
	munmap(proyeccion,sizeof(*(pMemComp)));

}
