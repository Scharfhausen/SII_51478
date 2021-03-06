//Este código ha sido modificado por Alvaro Zornoza (51540)

// Mundo.h: interface for the CMundo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MUNDO_H__9510340A_3D75_485F_93DC_302A43B8039A__INCLUDED_)
#define AFX_MUNDO_H__9510340A_3D75_485F_93DC_302A43B8039A__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include "Plano.h"
#include "Esfera.h"
#include "Raqueta.h"

//Includes de las tuberias

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


//Includes para la memoria compartida

#include "DatosMemCompartida.h"
#include <sys/mman.h>

//Includes para el cliente-servidor

#include <pthread.h>

//Includes para sockets

#include "Socket.h"

class CMundo  

{
public:
	void Init();
	CMundo();
	virtual ~CMundo();	
	
	void InitGL();	
	void OnKeyboardDown(unsigned char key, int x, int y);
	void OnTimer(int value);
	void OnDraw();	

	//Funcion comandos para las teclas cliente-servidor
	void RecibeComandosJugador();

	Esfera esfera;
	std::vector<Plano> paredes;
	Plano fondo_izq;
	Plano fondo_dcho;
	Raqueta jugador1;
	Raqueta jugador2;

	int puntos1;
	int puntos2;

	//Creación de la tubería
	int tuberia;

	//Creación del atributo de memoria compartida
	DatosMemCompartida MemComp;	
	DatosMemCompartida* pMemComp;

	//Tuberia cliente-servidor
	//int tuberiacs;

	//Tuberia teclas cliente servidor
	//int tuberiateclas;

	//Thread cliente-servidor
	pthread_t thid1;

	//Sockets para la practica 5
	Socket socket_conexion, socket_comunicacion;

};

#endif // !defined(AFX_MUNDO_H__9510340A_3D75_485F_93DC_302A43B8039A__INCLUDED_)
