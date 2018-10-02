#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
float X1, Y1, X2, Y2;	//variables
void LineDDA(){
  float dx=(X2-X1);
  float dy=(Y2-Y1);
  float steps;
  float xInc,yInc,x=X1,y=Y1;
  // Find out whether to increment x or y 
	if(abs(dx)>abs(dy))	// m<1
  		steps=abs(dx);
	else
		steps=abs(dy);	//m>1
  xInc=dx/steps;
  yInc=dy/steps;
  // Clears buffers to preset values 
  glClear(GL_COLOR_BUFFER_BIT);
  // Plot the points 
  glBegin(GL_POINTS);
  // Plot the first point 
  glVertex2i(x,y);
  int k;
  // For every step, find an intermediate vertex 
  for(k=0;k<steps;k++){
    x=x+xInc;
    y=y+yInc;
    //line drawing by increment points due to last vertex coordinates
    glVertex2i(x,y);	//x,y last vertices}
  glEnd();
  glFlush();}
void Init(){
  // Set clear color to white 
  glClearColor(1.0,1.0,1.0,0);
  // Set fill color to black 
  glColor3f(1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-640 , 640 , -480 , 480);	//left right bottom top	
//This is code for drawing x-axis and y-axis
glColor3f(1,0,1);	//x-axis color
glLineWidth(2);		//x-axis width
glBegin(GL_LINES);
  glVertex2i(640,0);
  glVertex2i(-640,0);
glEnd();
glColor3f(1,0,1);	//y-axis color
glLineWidth(2);		//y-axis width
glBegin(GL_LINES);
  glVertex2i(0,480);
  glVertex2i(0,-480);
glEnd();
glFlush();}
void draw_pixel(int x, int y) {
        glColor3f(1,0,1);
        glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();}
int main(int argc, char** argv)
{printf("Enter two end points of the line to be drawn:\n");
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%f%f",&X1,&Y1);
  printf("\nEnter Point1( X2 , Y2):\n");
  scanf("%f%f",&X2,&Y2);
  // Initialise GLUT library 
  glutInit(&argc,argv);
  // Set the initial display mode 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  // Set the initial window position and size 
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  // Create the window with title "DDA_Line" 
  glutCreateWindow("HELLO EXPERIMENT 4 IN CG LAB");
  // Initialize drawing colors 
  Init();
  // Call the displaying function 
  glutDisplayFunc(LineDDA);
   // Keep displaying untill the program is closed 
  glutMainLoop();              return 0;           }