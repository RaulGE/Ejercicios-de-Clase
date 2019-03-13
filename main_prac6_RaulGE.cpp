///Semestre 2019 - 2
//************************************************************//
/*
FI UNAM
Guzman Esquivel Raul
Grupo 02
Version visual studio 2017
Practica 6
*/

#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement
int rot = 0;
int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int lunatierra = 0;
int marte = 0;
int lunamarte = 0;
int jupiter = 0;
int lunajupiter = 0;
int saturno = 0;
int urano = 0;
int lunaurano = 0;
int neptuno = 0;
int lunaneptuno = 0;


float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glPushMatrix();//sistema solar
		glRotatef(rot, 1, 0, 0);
		glPushMatrix();
		glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
		glutSolidSphere(4, 12, 12);  //Draw Sun (radio,H,V);

		glPopMatrix();

			glPushMatrix();//mercurio
				glRotatef(mercurio, 0.0, 1.0, 0.0); //traslacion
				glTranslatef(8, 0, 0);
				glColor3f(0.976, 0.572, 0.101);	//
				glRotatef(mercurio, 0.0, 1.0, 0.0);//rotacion
				glutSolidSphere(0.5, 12, 12);  //Draw Sun (radio,H,V);

			glPopMatrix();

			glPushMatrix();//venus
				glRotatef(venus, 0.0, 1.0, 0.0); //traslacion
				glTranslatef(11, 0, 0);
				glColor3f(0.992, 0.913, 0.568);	//
				glRotatef(venus, 0.0, 1.0, 0.0);//rotacion
				glutSolidSphere(0.8, 12, 12);  //Draw Sun (radio,H,V);

			glPopMatrix();

			glPushMatrix();//tierra
				glRotatef(tierra, 0.0, 1.0, 0.0); //traslacion
				glTranslatef(13, 0, 0);
				glColor3f(0.462, 0.839, 0.956);	//
				glRotatef(tierra, 0.0, 1.0, 0.0);//rotacion
				glutSolidSphere(0.9, 12, 12);  //Draw Sun (radio,H,V);
					glPushMatrix();//luna tierra
						glRotatef(lunatierra, 0.0, 1.0, 0.0); //traslacion
						glTranslatef(1.9, 0, 0);
						glColor3f(0.662, 0.694, 0.694);	//
						glRotatef(lunatierra, 0.0, 1.0, 0.0);//rotacion
						glutSolidSphere(0.3, 12, 12);  //Draw Sun (radio,H,V);
					glPopMatrix();
			glPopMatrix();

			glPushMatrix();//marte
				glRotatef(marte, 0.0, 1.0, 0.0); //traslacion
				glTranslatef(15, 0, 0);
				glColor3f(0.898, 0.560, 0.431);	//
				glRotatef(marte, 0.0, 1.0, 0.0);//rotacion
				glutSolidSphere(0.4, 12, 12);  //Draw Sun (radio,H,V);
					glPushMatrix();//luna marte
						glRotatef(lunamarte, 0.0, 1.0, 0.0); //traslacion
						glTranslatef(1.5, 0, 0);
						glColor3f(0.662, 0.694, 0.694);	//
						glRotatef(lunamarte, 0.0, 1.0, 0.0);//rotacion
						glutSolidSphere(0.2, 12, 12);  //Draw Sun (radio,H,V);
					glPopMatrix();
			glPopMatrix();

			glPushMatrix();//jupiter
				glRotatef(jupiter, 0.0, 1.0, 0.0); //traslacion
				glTranslatef(17, 0, 0);
				glColor3f(0.968, 0.956, 0.811);	//
				glRotatef(jupiter, 0.0, 1.0, 0.0);//rotacion
				glutSolidSphere(4.5, 25, 25);  //Draw Sun (radio,H,V);
					glPushMatrix();//luna jupiter
						glRotatef(lunajupiter, 0.0, 1.0, 0.0); //traslacion
						glTranslatef(6, 0, 0);
						glColor3f(0.662, 0.694, 0.694);	//
						glRotatef(lunajupiter, 0.0, 1.0, 0.0);//rotacion
						glutSolidSphere(1, 12, 12);  //Draw Sun (radio,H,V);
					glPopMatrix();
						glPushMatrix();//luna jupiter
							glRotatef(lunajupiter, 0.0, 1.0, 0.0); //traslacion
							glTranslatef(0, 0, 6);
							glColor3f(0.662, 0.694, 0.694);	//
							glRotatef(lunajupiter, 0.0, 1.0, 0.0);//rotacion
							glutSolidSphere(1, 12, 12);  //Draw Sun (radio,H,V);
						glPopMatrix();
			glPopMatrix();

			glPushMatrix();//saturno
				glRotatef(saturno, 0.0, 1.0, 0.0); //traslacion
				glTranslatef(19, 0, 0);
				glColor3f(0.847, 0.764, 0.474);	//
				glRotatef(saturno, 0.0, 1.0, 0.0);//rotacion
				glutSolidSphere(3.5, 12, 12);  //Draw Sun (radio,H,V);
					glPushMatrix();
						glRotatef(45, 1.0, 0.0, 0.0); 
					
						//glRotatef(saturno, 0.0, 1.0, 0.0); //traslacion
						glColor3f(1, 0, 0);	//
						//glRotatef(saturno, 1.0, 0.0, 0.0);//rotacion
						glutSolidTorus(0.5, 4, 2, 25);  //Draw Sun (radio,H,V);	
						
						glTranslatef(0.0,0,0.5);
						glColor3f(1, 1, 0);
						glutSolidTorus(0.5, 4, 2, 25);  //Draw Sun (radio,H,V);		
					glPopMatrix();
						
			glPopMatrix();

			glPushMatrix();//urano
				glRotatef(urano, 0.0, 1.0, 0.0); //traslacion
				glTranslatef(21, 0, 0);
				glColor3f(0.764, 0.913, 0.925);	//
				glRotatef(urano, 0.0, 1.0, 0.0);//rotacion
				glutSolidSphere(1.2, 12, 12);  //Draw Sun (radio,H,V);
					glPushMatrix();//luna urano
						glRotatef(lunaurano, 0.0, 1.0, 0.0); //traslacion
						glTranslatef(1.9, 0, 0);
						glColor3f(0.662, 0.694, 0.694);	//
						glRotatef(lunaurano, 0.0, 1.0, 0.0);//rotacion
						glutSolidSphere(0.5, 12, 12);  //Draw Sun (radio,H,V);
					glPopMatrix();
			glPopMatrix();

			glPushMatrix();//neptuno
				glRotatef(neptuno, 0.0, 1.0, 0.0); //traslacion
				glTranslatef(21, 0, 0);
				glColor3f(0.764, 0.913, 0.925);	//
				glRotatef(neptuno, 0.0, 1.0, 0.0);//rotacion
				glutSolidSphere(1.2, 12, 12);  //Draw Sun (radio,H,V);
					glPushMatrix();//luna neptuno
						glRotatef(lunaneptuno, 0.0, 1.0, 0.0); //traslacion
						glTranslatef(1.9, 0, 0);
						glColor3f(0.662, 0.694, 0.694);	//
						glRotatef(lunaneptuno, 0.0, 1.0, 0.0);//rotacion
						glutSolidSphere(0.4, 12, 12);  //Draw Sun (radio,H,V);
					glPopMatrix();
						glPushMatrix();//luna neptuno
							glRotatef(lunaneptuno, 0.0, 1.0, 0.0); //traslacion
							glTranslatef(1, 0, 2);
							glColor3f(0.662, 0.694, 0.694);	//
							glRotatef(lunaneptuno, 0.0, 1.0, 0.0);//rotacion
							glutSolidSphere(0.4, 12, 12);  //Draw Sun (radio,H,V);
						glPopMatrix();
			glPopMatrix();

	glPopMatrix();


	glutSwapBuffers();
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		mercurio = (mercurio - 8) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		venus = (venus - 7) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		tierra = (tierra - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

			if (dwElapsedTime >= 30)
			{
				lunatierra = (lunatierra - 1) % 360;

				dwLastUpdateTime = dwCurrentTime;
			}

	if (dwElapsedTime >= 30)
	{
		marte = (marte - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

			if (dwElapsedTime >= 30)
			{
				lunamarte = (lunamarte - 1) % 360;

				dwLastUpdateTime = dwCurrentTime;
			}


	if (dwElapsedTime >= 30)
	{
		jupiter = (jupiter - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

			if (dwElapsedTime >= 30)
			{
				lunajupiter = (lunajupiter - 1) % 360;

				dwLastUpdateTime = dwCurrentTime;
			}

	if (dwElapsedTime >= 30)
	{
		saturno = (saturno - 3) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		urano = (urano - 2) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}
			if (dwElapsedTime >= 30)
			{
				lunaurano = (lunaurano - 2) % 360;

				dwLastUpdateTime = dwCurrentTime;
			}

	if (dwElapsedTime >= 30)
	{
		neptuno = (neptuno - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}


			if (dwElapsedTime >= 30)
			{
				lunaneptuno = (lunaneptuno - 1) % 360;

				dwLastUpdateTime = dwCurrentTime;
			}


	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		rot -= 3;
		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		rot += 3;
		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6 Sistema Solar Raul GE"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}