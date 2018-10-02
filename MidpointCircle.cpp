#include <stdio.h>
#include <GL/glut.h>
int pntX1, pntY1, r;
void plot(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();}
void myInit (void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640, 640, -480, 480);}
void midPointCircleAlgo(){
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);
	while (y > x){
		if (decision < 0){
			x++; 
			decision += 2*x+1;}
		else{
			y--;
			x++;
			decision += 2*(x-y)+1;}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);}}
void myDisplay(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	midPointCircleAlgo();
	glFlush ();
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
int main(int argc, char** argv){	
	printf("Enter the Coordinates for the centre of circle\n\n");
	printf( "Enter X coordinate\n");
	scanf("%d",&pntX1);
	printf("\nEnter Y coordinate\n");
	scanf("%d",&pntY1);
	printf("\nEnter radius : ");
	scanf("%d",&r);
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();}
