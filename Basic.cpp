#include<GL/glut.h>
//#include<GL/gl.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);	//background color
	glColor4f(0,0,0,1);	//color of diagram
	
	glBegin(GL_POLYGON);
	glVertex3f(0.5,0.5,0.0);      //x,y,z coordinates of vertex.
	glVertex3f(-0.5,0.5,0.0);
	glVertex3f(-0.5,-0.5,0.0);
	glVertex3f(0.5,-0.5,0.0);
	glEnd();	//end the program
	glFlush();	//Flush values on the screen
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("HELLO EXPERIMENT 1 IN CG ");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
