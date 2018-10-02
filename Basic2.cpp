#include<GL/glut.h>
//#include<GL/gl.h>
void displayLine()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);	//background color
	glColor4f(0,0,0,1);	//color of diagram
	
	glLineWidth(100);	//initializing line width

	glBegin(GL_LINES);	//for line generation write LINE instead of POLYGON

	glVertex2f(0.5,0.5);      //x,y,z coordinates of vertex.
	glVertex2f(-0.5,-0.5);
	glEnd();	//end the program
	glFlush();	//Flush values on the screen
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("HELLO EXPERIMENT 2 IN CG ");
	glutDisplayFunc(displayLine);
	glutMainLoop();
	return 0;
}
