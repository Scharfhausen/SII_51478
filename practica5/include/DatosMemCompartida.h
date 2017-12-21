#pragma once 
#include "Esfera.h"
#include "Raqueta.h"
class DatosMemCompartida
{       
public:         
      Esfera esfera;
      Raqueta raqueta1;
      Raqueta raqueta2;

      int accion; //accion1, accion2; //1 arriba, 0 nada, -1 abajo
};
