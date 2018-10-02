#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
void myInit (void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(-640, 640, -480, 480);
	glColor3f(0,0,0);}
void display (void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	float x, y, i;
	for ( i = 0; i < (2 * pi); i=i+0.001)	//to make circle we increment 0.001	
{
x = 200 * cos(i);	//200 is the radius and circle starts from x-axis if cos(i)
y = 200 * sin(i);	//circle will moves from x-axis to y-axis on changing values
		glVertex2i(x, y);}
	glEnd();
	glFlush();
glColor3f(0,0,0);
glLineWidth(2);
glBegin(GL_LINES);
  glVertex2i(-640,0);
  glVertex2i(640,0);
glEnd();
glColor3f(0,0,0);
glLineWidth(2);
glBegin(GL_LINES);
  glVertex2i(0,480);
  glVertex2i(0,-480);
glEnd();
glFlush();}
int main (int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MID POINT CIRCLE GENERATING ALGORITHM");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();}
