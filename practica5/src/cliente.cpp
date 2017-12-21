#include "glut.h"
#include "MundoCliente.h"
//#include "signal.h"

//el unico objeto global
CMundo mundo;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

//int aux1;//Esta variable sirve para tratar la alarma 
/*void tratar_alarma(int)
{	
	extern int aux1;
	aux1=0;
}*/

int main(int argc,char* argv[])
{
	/*struct sigaction act;
	act.sa_handler=&tratar_alarma;
	act.sa_flags=SA_RESTART;
	sigaction(SIGALRM,&act,NULL);*/
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Cliente");


	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	//glutMouseFunc(OnRaton);

	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
	
	mundo.InitGL();

	
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	
	

	return 0;   
}

void OnDraw(void)
{
	mundo.OnDraw();
}
void OnTimer(int value)
{
	mundo.OnTimer(value);
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}
void OnKeyboardDown(unsigned char key, int x, int y)
{
	mundo.OnKeyboardDown(key,x,y);
	glutPostRedisplay();
}
