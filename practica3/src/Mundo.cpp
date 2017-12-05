// Mundo.cpp: implementation of the CMundo class.
//
//////////////////////////////////////////////////////////////////////
#include <fstream>
#include <sstream>
#include "Mundo.h"
#include "glut.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
 
char* proyeccion;

CMundo::CMundo()
{
	Init();
}

CMundo::~CMundo()
{
	close(fd);
}

void CMundo::InitGL()
{
	//Habilitamos las luces, la renderizacion y el color de los materiales
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);
}

void print(char *mensaje, int x, int y, float r, float g, float b)
{
	glDisable (GL_LIGHTING);

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT) );

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
	glColor3f(r,g,b);
	glRasterPos3f(x, glutGet(GLUT_WINDOW_HEIGHT)-18-y, 0);
	int len = strlen (mensaje );
	for (int i = 0; i < len; i++) 
		glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, mensaje[i] );
		
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable( GL_DEPTH_TEST );
}
void CMundo::OnDraw()
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	gluLookAt(0.0, 0, 17,  // posicion del ojo
		0.0, 0.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	/////////////////
	///////////
	//		AQUI EMPIEZA MI DIBUJO
	char cad[100];
	sprintf(cad,"Jugador1: %d",puntos1);
	print(cad,10,0,1,1,1);
	sprintf(cad,"Jugador2: %d",puntos2);
	print(cad,650,0,1,1,1);
	int i;
	for(i=0;i<paredes.size();i++)
		paredes[i].Dibuja();

	fondo_izq.Dibuja();
	fondo_dcho.Dibuja();
	jugador1.Dibuja();
	jugador2.Dibuja();
	esfera.Dibuja();

	/////////////////
	///////////
	//		AQUI TERMINA MI DIBUJO
	////////////////////////////

	//Al final, cambiar el buffer
	glutSwapBuffers();
}

void CMundo::OnTimer(int value)
{	
	jugador1.Mueve(0.025f);
	jugador2.Mueve(0.025f);
	esfera.Mueve(0.025f);
	int i;
	for(i=0;i<paredes.size();i++)
	{
		paredes[i].Rebota(esfera);
		paredes[i].Rebota(jugador1);
		paredes[i].Rebota(jugador2);
	}

	jugador1.Rebota(esfera);
	jugador2.Rebota(esfera);
	if(fondo_izq.Rebota(esfera))
	{	
		esfera.centro.x=0;
		esfera.centro.y=rand()/(float)RAND_MAX;
		esfera.velocidad.x=2+2*rand()/(float)RAND_MAX;
		esfera.velocidad.y=2+2*rand()/(float)RAND_MAX;
		puntos2++;
	//Escritura del FIFO
		char cad[200];
		sprintf(cad,"Jugador 2 marca 1 punto, lleva %d", puntos2);
		write(fd,cad,strlen(cad)+1);
	}

	if(fondo_dcho.Rebota(esfera))
	{
		esfera.centro.x=0;
		esfera.centro.y=rand()/(float)RAND_MAX;
		esfera.velocidad.x=-2-2*rand()/(float)RAND_MAX;
		esfera.velocidad.y=-2-2*rand()/(float)RAND_MAX;
		puntos1++;
	//Escritura del FIFO
		char cad[200];
		sprintf(cad,"Jugador 1 marca 1 punto, lleva %d", puntos1);
		write(fd,cad,strlen(cad)+1);
	}
	
	//Tambien debemos actualizar los valores reales en nuestra proyección del fichero
	pMemComp->esfera=esfera;
	pMemComp->raqueta1=jugador1;
	pMemComp->raqueta2=jugador2;
	//Implementación sobre el bot. Recibimos con un switch case el valor de la acción que se proyecta desde el bot en el neuvo fichero proyectado.
	switch(pMemComp->accion1)
	{
		case 1: jugador1.velocidad.y=4; 			
			break;
		case 0: break;
		case -1: jugador1.velocidad.y=-4;
			break;
	}
	if(contador<0)
	{
		switch(pMemComp->accion2)

		{

			case 1: jugador2.velocidad.y=4; 			
				break;

			case 0: break;

			case -1: jugador2.velocidad.y=-4;

				break;

		}	
	}

	//Finalización del juego por límite de puntos e implementacion del mensaje de la tuberia con el ganador.
	int CurrState=0;
	int PrevState=0;
	char cadena[200];
	if(puntos1==3)
	{
		CurrState=1;
		if(CurrState!=PrevState)
		{
			sprintf(cadena,"El jugador 1 consigue 3 puntos y gana.");
			write(fd,cadena,strlen(cadena)+1);
		}
		PrevState=CurrState;
		exit(0);
	}
	if(puntos2==3)
	{
		CurrState=1;
		if(CurrState!=PrevState)
		{
			sprintf(cadena,"El jugador 2 consigue 3 puntos y gana.");
			write(fd,cadena,strlen(cadena)+1);
		}
		PrevState=CurrState;
		exit(0);
	}

	

}

void CMundo::OnKeyboardDown(unsigned char key, int x, int y)
{
	switch(key)
	{
//	case 'a':jugador1.velocidad.x=-1;break;
//	case 'd':jugador1.velocidad.x=1;break;
	case 's':jugador1.velocidad.y=-4;break;
	case 'w':jugador1.velocidad.y=4;break;
	case 'l':jugador2.velocidad.y=-4;break;
	case 'o':jugador2.velocidad.y=4;break;

	}
}

void CMundo::Init()
{
	Plano p;

//Creacion del FIFO

	myfifo="/tmp/myfifo";
	mkfifo(myfifo,0666);
	fd=open(myfifo, O_WRONLY);

//Para el BOT
//Fichero proyectado en memoria
	int file=open("/tmp/datosBot.txt",O_RDWR|O_CREAT|O_TRUNC, 0777); //Creacion del fichero
	write(file,&MemComp,sizeof(MemComp)); //Escribimos en el fichero
	proyeccion=(char*)mmap(NULL,sizeof(MemComp),PROT_WRITE|PROT_READ,MAP_SHARED,file,0); //Asignamos al puntero de proyeccion el lugar donde esta proyectado el fichero
	close(file); //Cerramos el fichero
	pMemComp=(DatosMemCompartida*)proyeccion; //Asignamos el valor del puntero de proyeccion al puntero de Datos
	pMemComp->accion1=0; //De inicio, no queremos que haya ninguna acción.
	pMemComp->accion2=0;

	

//pared inferior
	p.x1=-7;p.y1=-5;
	p.x2=7;p.y2=-5;
	paredes.push_back(p);

//superior
	p.x1=-7;p.y1=5;
	p.x2=7;p.y2=5;
	paredes.push_back(p);

	fondo_izq.r=0;
	fondo_izq.x1=-7;fondo_izq.y1=-5;
	fondo_izq.x2=-7;fondo_izq.y2=5;

	fondo_dcho.r=0;
	fondo_dcho.x1=7;fondo_dcho.y1=-5;
	fondo_dcho.x2=7;fondo_dcho.y2=5;

	//a la izq
	jugador1.g=0;
	jugador1.x1=-6;jugador1.y1=-1;
	jugador1.x2=-6;jugador1.y2=1;

	//a la dcha
	jugador2.g=0;
	jugador2.x1=6;jugador2.y1=-1;
	jugador2.x2=6;jugador2.y2=1;
}
