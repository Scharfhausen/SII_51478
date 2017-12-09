// Esfera.cpp: implementation of the Esfera class.
//
//////////////////////////////////////////////////////////////////////

#include "Esfera.h"
#include "glut.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Esfera::Esfera()
{
	radio=0.5f;
	velocidad.x=3;
	velocidad.y=3;
}

Esfera::~Esfera()
{

}



void Esfera::Dibuja()
{
	glColor3ub(255,255,0);
	glEnable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(centro.x,centro.y,0);
	glutSolidSphere(radio,15,15);
	glPopMatrix();
   	
	
}

void Esfera::Mueve(float t)
{
	centro=centro+velocidad*t;

	radio-=0.05*t;
	if(radio<0.05) radio=0.5; //Si la esfera se hace demasiado pequeña vuelve a su tamaño original	
}
